// SPDX-License-Identifier: GPL-3.0-or-later
/*
 * Copyright (c) 2020 SUSE LLC
 *
 * Reads a test plan, sends test commands to the executor and writes the
 * results back into the plan. Also writes the test log output into seperate
 * files.
 *
 */

#include <assert.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "actors.h"
#include "executor.h"
#include "parser.h"

enum tst_status {
	TFAIL = 1,
	TBROK = 2,
};

enum plan_type {
	PLAN_NPROC,
	PLAN_TODO,
	PLAN_SENT,
	PLAN_EXEC,
	PLAN_REAP,
	PLAN_DONE,
};

struct test;
struct test {
	struct cmds cmds;
	enum plan_type status;
	int tres;

	struct test *next;
};

struct tester {
	struct test *test;
	int fd;
};

/* Planner members */
static unsigned int nproc = 1;
static struct test *todos;
static struct test *dones;
static unsigned int stopped;

__attribute__((pure))
static int only_pong(const struct actor *self __attribute__((unused)),
		     const struct msg *msg)
{
	return msg->type == MSG_PONG;
}

static void writer_listen(struct actor *self)
{
	struct msg *msg;

	actor_inbox_filter(self, only_pong);

	while ((msg = actor_inbox_pop(self)) == NULL) {
		dprintf(STDOUT_FILENO, "PING\n");
		usleep(10000);
	}
	assert(msg->type == MSG_PONG);
	free(msg);

	actor_inbox_filter(self, NULL);

	actor_hear_loop(self);
}

static void writer_hear(struct actor *self __attribute__((unused)), struct msg *msg)
{
	struct cmds *cmds;

	switch (msg->type) {
	case MSG_CMDS:
		cmds = msg->ptr;
		dprintf(STDOUT_FILENO, "CMDS %ld %s %s\n",
			addr_to_id(msg->from), cmds->tid, cmds->cmds);
		break;

	case MSG_EXEC:
		dprintf(STDOUT_FILENO, "EXEC %ld\n", addr_to_id(msg->from));
		break;
	case MSG_ALLC:
		dprintf(STDOUT_FILENO, "ALLC %ld\n", msg->val);
		break;
	case MSG_PONG:
		break;
	default:
		assert(0);
	}

	free(msg);
}

/* See executor.c:reader_listen */
static void reader_listen(struct actor *self)
{
	struct msg *msg;
	int r0;
	char buf[LEN_1024];

	assert_perror(errno);

	parser_init();

	for (;;) {
		r0 = read(STDIN_FILENO, buf, sizeof(buf));

		if (!r0) {
			msg = msg_alloc();
			msg->type = MSG_EXIT;

			actor_say(self, ADDR_PLANNER, msg);
			actor_exit(self);
		}

		switch(errno) {
		case EAGAIN:
		case EINTR:
			errno = 0;
			break;
		default:
			assert_perror(errno);
		}

		if (r0 > 0)
			parser_feed(self, buf, r0);
	}
}

static enum plan_type upd_status(enum msg_type msg, enum plan_type cur)
{
	switch(msg) {
	case MSG_CMDS:
		assert(cur == PLAN_TODO);
		return PLAN_SENT;
	case MSG_EXEC:
		assert(cur == PLAN_SENT);
		return PLAN_EXEC;
	case MSG_LOGD:
		break;
	case MSG_TRES:
		break;
	default:
		assert(0);
	}

	switch (cur) {
	case PLAN_REAP:
		return PLAN_DONE;
	case PLAN_EXEC:
		return PLAN_REAP;
	default:
		assert(0);
	}
}

static void tester_hear(struct actor *self, struct msg *msg)
{
	ssize_t r0;
	int fd;
	struct log *log;
	struct tester *my = self->priv;
	struct test *test = my->test;
	struct cmds *cmds;

	switch (msg->type) {
	case MSG_ALLC:
		assert(!test);
		msg->type = MSG_CMDS;
		actor_say(self, ADDR_PLANNER, msg);
		break;

	case MSG_CMDS:
		if (msg->from == ADDR_READER) {
			cmds = msg->ptr;

			assert(test);
			assert(!strcmp(test->cmds.tid, cmds->tid));
			test->status = upd_status(msg->type, test->status);
			free(cmds);

			msg->type = MSG_EXEC;
			actor_say(self, ADDR_WRITER, msg);
			break;
		}

		test = msg->ptr;
		msg->ptr = &test->cmds;
		actor_say(self, ADDR_WRITER, msg);

		fd = open(test->cmds.tid,
			  O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
		assert_perror(errno);
		my->fd = fd;

		my->test = test;
		break;

	case MSG_EXEC:
		/* start timer? */
		test->status = upd_status(msg->type, test->status);
		free(msg);
		break;

	case MSG_LOGD:
		fd = my->fd;
		log = msg->ptr;

		assert(test);
		assert(fd);

		if (!log->len) {
			if (fd) {
				close(fd);
				my->fd = 0;
			}

			test->status = upd_status(msg->type, test->status);
		} else {
			assert(log->len <= LEN_1024);

			r0 = write(fd, log->buf, log->len);
			assert_perror(errno);
			assert((size_t)r0 == log->len);
		}

		free(msg);
		break;
	case MSG_TRES:
		test->tres = (int)msg->val;

		test->status = upd_status(msg->type, test->status);

		free(msg);
		break;
	default:
		assert(0);
	}

	if (!test || test->status != PLAN_DONE)
		return;

	msg = msg_alloc();
	msg->type = MSG_DONE;
	msg->ptr = test;

	actor_say(self, ADDR_PLANNER, msg);
	my->test = NULL;

	msg = msg_alloc();

	if (test->tres & (TFAIL | TBROK)) {
		msg->type = MSG_TRES;
		msg->val = test->tres;
	} else {
		msg->type = MSG_CMDS;
	}

	actor_say(self, ADDR_PLANNER, msg);
}

static void read_plan(void)
{
	int r0;
	FILE *f = fopen("test-plan", "r");
	char type_buf[LEN_8];
	enum plan_type type;
	struct test *test;

	assert_perror(errno);

	for (;;) {
		r0 = fscanf(f, "%7s ", type_buf);
		assert_perror(errno);

		if (r0 == EOF)
			break;

		assert(r0);

		if (!strcmp("NPROC", type_buf))
			type = PLAN_NPROC;
		else if (!strcmp("DONE", type_buf))
			type = PLAN_DONE;
		else if (!strcmp("TODO", type_buf))
			type = PLAN_TODO;
		else {
			fprintf(stderr,
				"Don't understand '%s' in test-plan!\n",
				type_buf);
			assert(0);
		}

		if (type == PLAN_NPROC) {
			r0 = fscanf(f, "%u\n", &nproc);
			assert(r0);
			assert_perror(errno);
			continue;
		}

		test = malloc(sizeof(*test));
		test->status = type;

		if (type == PLAN_TODO) {
			r0 = fscanf(f, "%64s %1024[^\n]",
				    test->cmds.tid,
				    test->cmds.cmds);

			assert_perror(errno);
			actor_assert(r0 == 2, "%d != 2", r0);

			test->next = todos;
			todos = test;
		} else {
			r0 = fscanf(f, "%64s %d %1024[^\n]",
				    test->cmds.tid,
				    &test->tres,
				    test->cmds.cmds);

			assert_perror(errno);
			actor_assert(r0 == 3, "%d != 3", r0);

			test->next = dones;
			dones = test;
		}

		assert_perror(errno);
		assert(r0);

	}

	assert(nproc);
	assert(todos || dones);
}

static void write_plan(void)
{
	int r0;
	FILE *f = fopen("test-plan", "w");
	struct test *test;

	assert_perror(errno);

	r0 = fprintf(f, "NPROC %d\n", nproc);
	assert_perror(errno);
	assert(r0 > 0);

	for (test = todos; test; test = test->next)
		fprintf(f, "TODO %s %s\n", test->cmds.tid, test->cmds.cmds);

	for (test = dones; test; test = test->next) {
		fprintf(f, "DONE %s %d %s\n",
			test->cmds.tid, test->tres, test->cmds.cmds);
	}

	fclose(f);
}

static void planner_listen(struct actor *self)
{
	struct actor *tester;
	struct msg *msg;
	addr_t id;

	read_plan();

	for (id = 0; id < nproc; id++) {
		tester = actor_alloc();
		tester->addr = id_to_addr(id);
		tester->priv = malloc(sizeof(struct tester));
		memset(tester->priv, 0, sizeof(struct tester));
		tester->hear = tester_hear;
		actor_start(tester);

		msg = msg_alloc();
		msg->type = MSG_ALLC;
		msg->val = id;
		actor_say(self, ADDR_WRITER, msg);
	}

	actor_hear_loop(self);
}

static void planner_hear(struct actor *self, struct msg *msg)
{
	struct test *test;

	switch(msg->type) {
	case MSG_CMDS:
		test = todos;

		if (stopped || !test) {
			stopped++;
			free(msg);
			break;
		}

		todos = test->next;
		test->next = NULL;

		msg->ptr = test;
		actor_say(self, msg->from, msg);
		break;

	case MSG_TRES:
		assert(msg->val & (TFAIL | TBROK));
		stopped++;
		free(msg);
		break;

	case MSG_DONE:
		test = msg->ptr;
		test->next = dones;
		dones = test;

		assert(test->status == PLAN_DONE);
		free(msg);
		break;

	case MSG_EXIT:
		stopped = nproc;
		free(msg);
		break;

	default:
		assert(0);
	}

	assert(stopped <= nproc);
	if (stopped != nproc)
		return;

	write_plan();

	actor_exit(self);
}

int main(void)
{
	pthread_t planner_t;
	struct actor *reader, *writer,  *planner;

	actors_init();

	writer = actor_alloc();
	writer->addr = ADDR_WRITER;
	writer->listen = writer_listen;
	writer->hear = writer_hear;
	actor_start(writer);

	planner = actor_alloc();
	planner->addr = ADDR_PLANNER;
	planner->listen = planner_listen;
	planner->hear = planner_hear;
	planner_t = actor_start(planner);

	reader = actor_alloc();
	reader->addr = ADDR_READER;
	reader->listen = reader_listen;
	actor_start(reader);

	pthread_join(planner_t, NULL);

	rcu_unregister_thread();

	return 0;
}

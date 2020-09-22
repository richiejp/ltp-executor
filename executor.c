// SPDX-License-Identifier: GPL-3.0-or-later
/*
 * Copyright (c) 2020 SUSE LLC
 */

#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <poll.h>

#include <sys/types.h>
#include <sys/wait.h>

#include "actors.h"
#include "executor.h"
#include "parser.h"

#ifdef NDEBUG
#   warning "Assert is used to check for errors"
#endif

struct tester {
	pid_t child;
	int cout;
	int eout;
	int result;
	struct cmds *test;
};

struct tres {
	int result;
};

static int kmsg;

void shutdown(struct actor *self)
{
	struct msg *msg = msg_alloc();
	msg->type = MSG_EXIT;

	actor_say(self, ADDR_WRITER, msg);
	actor_exit(self);
}

/* TODO: in all cases where we read or write to a file descriptor, there is
 * probably a faster way. We probably want to use io_uring on newer kernels
 * (assuming it works on non-sockets) and then use fallbacks. */
static void reader_listen(struct actor *self)
{
	int r0;
	char buf[LEN_1024];

	assert_perror(errno);

	parser_init();

	for (;;) {
		r0 = read(STDIN_FILENO, buf, sizeof(buf));

		/* If we are reading from a char device it can
		 * repeatedly return EOF, but may read successfully in
		 * the future */
		if (!r0) {
			usleep(1000);

			r0 = read(STDIN_FILENO, buf, sizeof(buf));
			if (r0 < 0 && errno == EBADF)
				shutdown(self);

			if (!r0)
				continue;
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
		else
			pthread_yield();
	}
}

/* As we may be writing to a dodgy special file or character device
 * that may behave any way it wants...
 *
 * TODO: Also retry after EIO?
 * */
#define WRITER_PRINTF(...) do {			       \
	r0 = dprintf(STDOUT_FILENO, ##__VA_ARGS__);    \
	if (errno == EAGAIN || errno == EINTR) {       \
		usleep(100);			       \
		dprintf(STDOUT_FILENO, "\n");	       \
		errno = 0;			       \
	}					       \
	assert_perror(errno);			       \
} while (r0 < 0)

static void writer_hear(struct actor *self, struct msg *msg)
{
	ssize_t r0;
	size_t written;
	struct log *log;
	struct tres *tres;
	struct cmds *cmds;

	/* TODO: It is critical we get log and test result messages out of the
	 * SUT as soon as possible. So we should avoid all unecessary work
	 * here. See tester_check/listen. */

	switch (msg->type) {
	case MSG_PONG:
		WRITER_PRINTF("PONG\n");
		break;

	case MSG_LOGD:
		log = msg->ptr;
		WRITER_PRINTF("LOGD %ld %ld ", addr_to_id(msg->from), log->len);

		written = 0;
		do {
			r0 = write(STDOUT_FILENO, log->buf, log->len);

			if (r0 > 0)
				written += (size_t)r0;
			else if (errno == EAGAIN || errno == EINTR)
				usleep(100);
			else
				assert_perror(errno);
		} while (written < log->len);

		assert_perror(errno);
		assert((ssize_t)log->len == r0);
		WRITER_PRINTF("\n");
		break;

	case MSG_TRES:
		tres = msg->ptr;
		WRITER_PRINTF("TRES %ld %d\n",
			addr_to_id(msg->from), tres->result);
		free(tres);
		break;

	case MSG_EXIT:
		free(msg);
		WRITER_PRINTF("+EXIT\n");
		actor_exit(self);
		break;

	case MSG_CMDS:
		cmds = msg->ptr;
		WRITER_PRINTF("+CMDS %ld %s %s\n",
			addr_to_id(msg->from), cmds->tid, cmds->cmds);
		break;

	case MSG_ERRO:
		WRITER_PRINTF("ERRO 0 %s\n", (char *)msg->ptr);
		break;

	case MSG_EXEC:
		WRITER_PRINTF("+EXEC %ld\n", addr_to_id(msg->from));
		break;
	case MSG_ALLC:
		WRITER_PRINTF("+ALLC %ld\n", addr_to_id(msg->from));
		break;
	default:
		assert(0);
	}

	free(msg);
}

static void tester_check_child(struct actor *self)
{
	int r0, wstatus;
	struct tester *my = self->priv;
	struct tres *tres;
	struct msg *msg;

	r0 = waitpid(my->child, &wstatus, WNOHANG);
	assert_perror(errno);
	assert(r0 > -1);

	if (!r0)
		return;

	tres = malloc(sizeof(*tres));
	assert_perror(errno);
	tres->result = -1;

	if (WIFEXITED(wstatus))
		tres->result = WEXITSTATUS(wstatus);
	if (WCOREDUMP(wstatus))
		tres->result = 0xDEAD;
	assert(tres->result > -1);

	my->child = 0;

	msg = msg_alloc();
	msg->type = MSG_TRES;
	msg->ptr = tres;
	actor_say(self, ADDR_WRITER, msg);
}

static void tester_check_output(struct actor *self)
{
	ssize_t r0;
	struct log *log;
	struct tester *my = self->priv;
	struct msg *msg;
	struct pollfd fds[2] = {
		{ 0, POLLIN | POLLPRI, 0 },
		{ 0, POLLIN | POLLPRI, 0 }
	};
	nfds_t i, nfds = 0;

	/* TODO: the writer could pass back spent log messages instead of
	 * recreating them. */
	/* TDOD: We don't want to malloc log buffers or messages in the tester
	 * listen loop atall */
	/* TODO: Instead of reading into a buffer we could inform the writer
	 * that data is ready on our cout fd and it could splice() this into
	 * the output fd */

	if (my->cout)
		fds[nfds++].fd = my->cout;

	if (my->eout)
		fds[nfds++].fd = my->eout;

	r0 = poll(fds, nfds, 100);
	if (r0 < 0) {
		if (errno == EINTR) {
			errno = 0;
			return;
		}
		assert_perror(errno);
	}

	if (!r0)
		return;

	for (i = 0; i < nfds; i++) {
		if (!fds[i].revents)
			continue;

		msg = msg_alloc_extra(sizeof(*log));
		msg->type = MSG_LOGD;
		log = msg->ptr;

		while ((r0 = read(fds[i].fd, log->buf, LEN_1024 - 1)) < 0) {
			if (errno != EINTR)
				assert_perror(errno);

			errno = 0;
		}

		if (!r0) {
			close(fds[i].fd);

			if (fds[i].fd == my->cout)
				my->cout = 0;
			else
				my->eout = 0;

			if (my->cout || my->eout) {
				free(msg);
				continue;
			}
		}

		log->len = r0;
		actor_say(self, ADDR_WRITER, msg);
	}
}

static void tester_listen(struct actor *self)
{
	struct msg *msg = msg_alloc();
	struct tester *my = malloc(sizeof(struct tester));

	assert_perror(errno);
	assert(my);
	memset(my, 0, sizeof(*my));
	self->priv = my;

	msg->type = MSG_ALLC;
	actor_say(self, ADDR_WRITER, msg);

	for (;;) {
		msg = actor_inbox_pop(self);

		if (msg)
			self->hear(self, msg);
		else if (!(my->child || my->cout || my->eout))
			actor_wait(self, NULL);

		if (my->child)
			tester_check_child(self);

		if (my->cout || my->eout)
			tester_check_output(self);
	}
}

static void kmsg_log(char *msg)
{
	size_t len;
	int r0;

	if (!kmsg)
		return;

	len = strlen(msg);
	r0 = write(kmsg, msg, len);

	assert_perror(errno);
	actor_assert(r0 == (int)len, "%u < %zu", r0, len);
}
/* TODO: many/all runtest entries don't require sh. Some runtest entries set
 * an environment var beforehand which can be done with a seperate command. */
static void tester_exec(struct actor *self)
{
	int r0, r1;
	pid_t pid;
	int cin[2], cout[2], eout[2];
	struct tester *my = self->priv;

	assert(!my->child);
	assert(my->test);
	assert(my->test->cmds[0]);

	r0 = pipe2(cin, O_CLOEXEC);
	assert_perror(errno);
	assert(!r0);

	r1 = pipe2(cout, O_CLOEXEC);
	assert_perror(errno);
	assert(!r1);
	r1 = pipe2(eout, O_CLOEXEC);
	assert_perror(errno);
	assert(!r1);

	pid = fork();
	assert_perror(errno);
	assert(pid > -1);

	if (!pid) {
		close(cin[1]);
		close(cout[0]);
		close(eout[0]);

		dup3(cin[0], STDIN_FILENO, 0);
		assert_perror(errno);
		dup3(cout[1], STDOUT_FILENO, 0);
		assert_perror(errno);
		dup3(eout[1], STDERR_FILENO, 0);
		assert_perror(errno);

		r0 = execlp("/usr/bin/sh", "sh", (char *)NULL);
		assert_perror(errno);
		assert(!r0);
	}

	close(cin[0]);
	close(cout[1]);
	close(eout[1]);

	kmsg_log(my->test->tid);

	r0 = strlen(my->test->cmds);
	do {
		r1 = write(cin[1], my->test->cmds, r0);
		if (r1 < 0) {
			if (errno != EINTR)
				assert_perror(errno);

			r1 = 0;
			errno = 0;
		}

		r0 -= r1;
	} while (r0);

	close(cin[1]);

	my->cout = cout[0];
	my->eout = eout[0];
	my->child = pid;
}

static void tester_hear(struct actor *self, struct msg *msg)
{
	struct tester *my = self->priv;

	assert(my);

	switch (msg->type) {
	case MSG_CMDS:
		assert(msg->ptr);
		assert(!my->child);
		assert(!my->cout);
		assert(!my->eout);

		if (my->test)
			free(my->test);
		my->test = msg->ptr;
		actor_say(self, ADDR_WRITER, msg);
		break;

	case MSG_EXEC:
		tester_exec(self);
		actor_say(self, ADDR_WRITER, msg);
		break;

	case MSG_EXIT:
		free(msg);
		actor_exit(self);
		break;

	case MSG_ALLC:
		assert(!my->child);
		assert(!my->cout);
		assert(!my->eout);
		free(my->test);
		my->test = NULL;

		actor_say(self, ADDR_WRITER, msg);
		break;

	default:
		assert(0);
	}
}

void tester_start(struct actor *self, addr_t id)
{
	struct msg *msg;
	struct actor *tester;

	if (actor_exists(id)) {
		msg = msg_alloc();
		msg->type = MSG_ALLC;
		actor_say(self, id, msg);
		return;
	}

	tester = actor_alloc();
	tester->addr = id;
	tester->listen = tester_listen;
	tester->hear = tester_hear;

	actor_start(tester);
}

int main(void)
{
	int r0, r1;
	struct actor *reader, *writer;
	pthread_t reader_t, writer_t;
	char *intro;

	assert(asprintf(&intro, "Executor v%d.%d\n",
			executor_VERSION_MAJOR, executor_VERSION_MINOR));
	fputs(intro, stderr);

	kmsg = open("/dev/kmsg", O_WRONLY);
	if (kmsg < 0) {
		kmsg = 0;
		perror("Not logging to /dev/kmsg");
		errno = 0;
	}
	kmsg_log(intro);
	free(intro);

	actors_init();

	reader = actor_alloc();
	reader->addr = ADDR_READER;
	reader->listen = reader_listen;

	writer = actor_alloc();
	writer->addr = ADDR_WRITER;
	writer->hear = writer_hear;

	writer_t = actor_start(writer);
	reader_t = actor_start(reader);

	/* TODO: wait for testers to shutdown */
	/* TODO: abstract to actor function */
	r0 = pthread_join(reader_t, NULL);
	r1 = pthread_join(writer_t, NULL);

	assert_perror(r0);
	assert_perror(r1);

	rcu_unregister_thread();

	return 0;
}

/* # driver - drive the executor
 *
 * Reads a test plan, sends test commands to the executor and writes the
 * results back into the plan. Also writes the test log output into seperate
 * files.
 *
 * The idea is the test runner can do something like the following:
 *
 * $ mkdir test
 * $ cd test
 * $ tstctl init $LTP_DIR/runtest/syscalls
 * $ drive <$SUT_OUT >$SUT_IN
 * $ tstctl status
 *
 * Then if the test plan completed
 *
 * $ tstctl export > $RESULTS/syscalls.json
 * $ cd .. && rm -r test
 *
 * Or if the driver lost contact with the executor before completing then the
 * test harness can restart the SUT or whatever. Then just continue with:
 *
 * $ drive <$SUT_OUT >$SUT_IN
 **/

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

enum plan_type {
	PLAN_NPROC,
	PLAN_TODO,
	PLAN_DONE,
};

struct test;
struct test {
	struct cmds cmds;
	enum plan_type status;

	struct test *next;
};

struct logs;
struct logs {
	char tid[LEN_64];

	struct logs *next;
};

struct logger {
	struct logs *logs;
	int fd;
};

static unsigned int nproc = 1;
static struct test *cases;

static void read_plan(void)
{
	int r0;
	FILE *f = fopen("test-plan", "r");
	char type_buf[LEN_8];
	enum plan_type type;
	static struct test *prev = NULL, *test;

	cases = malloc(sizeof(*cases));
	assert_perror(errno);
	test = cases;

	for (;;) {
		r0 = fscanf(f, "%4s ", type_buf);
		assert_perror(errno);

		if (!r0)
			break;

		if (!strcmp("NPROC", type_buf))
			type = PLAN_NPROC;
		else if (!strcmp("DONE", type_buf))
			type = PLAN_DONE;
		else if (!strcmp("TODO", type_buf))
			type = PLAN_DONE;
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

		r0 = fscanf(f, "%64s %1024[^\n]",
			    test->cmds.tid,
			    test->cmds.cmds);
		assert_perror(errno);
		assert(r0);

		test->status = type;

		test->next = malloc(sizeof(*test));
		assert_perror(errno);
		prev = test;
		test = test->next;
	}

	free(test);
	prev->next = NULL;
}

static void logger_hear(struct actor *self, struct msg *msg)
{
	ssize_t r0;
	int fd;
	struct log *log;
	struct logger *my = self->priv;
	struct logs *logs = my->logs;

	switch (msg->type) {
	case MSG_LOGD:
		log = msg->ptr;

		/* Log is for current test case */
		if (logs && !strcmp(logs->tid, log->tid)) {
			fd = my->fd;
			goto write_log;
		}

		/* Log is for past test case; Temporarily reopen its log
		 * file */
		for (; logs; logs = logs->next) {
			if (strcmp(logs->tid, log->tid))
				continue;

			fd = open(logs->tid, O_WRONLY | O_APPEND);
			assert_perror(errno);
			goto write_log;
		}

		/* Log is for new test case; open new log file as
		 * current and close past one */
		logs = malloc(sizeof(*logs));
		assert_perror(errno);
		memcpy(logs->tid, log->tid, sizeof(logs->tid));
		logs->next = my->logs;
		my->logs = logs;

		close(my->fd);
		my->fd = open(logs->tid, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
		assert_perror(errno);
		fd = my->fd;

	write_log:
		assert(log->len <= LEN_1024);
		r0 = write(fd, log->buf, log->len);
		assert_perror(errno);
		assert((size_t)r0 == log->len);

		if (fd != my->fd)
			close(fd);

		free(log->tid);
		free(log);
		break;
	default:
		assert(0);
	}
}

int main(void)
{
	pthread_t logger_t;
	struct actor *logger;

	logger = actor_alloc();
	logger->addr = ADDR_LOGGER;
	logger->hear = logger_hear;

	logger_t = actor_start(logger);

	read_plan();
	/* Create the SUT reader */
	/* Read test plan */
	/* Create the log file writers */
	/* start the test controller */

	pthread_join(logger_t, NULL);

	rcu_unregister_thread();

	return 0;
}

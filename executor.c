/* Protocol
 *
 * Human readable protocal for the simple SUT-side test executor.
 *
 * TODO: Use some existing protocol and command set?
 *
 * # Notation
 *
 * Literal text is written verbatim as is whitespace. Arguments or values are
 * enclosed in '<' and '>'. The type of the value preceeds the values name,
 * seperated by a ':' e.g. <type:name>. Optional arguments are enclosed in '['
 * and ']'.
 *
 * # Data types
 *
 * Protocol is made up of literal characters, strings and integers
 *
 * ## Integers (int)
 *
 * All numbers are unsigned integers, represented as a human readable string
 * of chars e.g. `12` is literally the integer twelve. Should not exceed
 * uint64_t.
 *
 * ### Identity (ID)
 *
 * Used to identify a test or communication channel, so that multiple
 * tests/operations can be carried out at once. It is an integer N where N > 0
 * and N <= INT_MAX.
 *
 * ## Strings
 *
 * None of the strings have quote marks around them!
 *
 * ### Symbols (sym)
 *
 * Strings with no whitespace or special characters, much like C symbols
 * except they can also include '-'. They are delimited by whitespace
 *
 * ### Prefixed Strings <strn>
 *
 * Binary safe strings, prefixed with the integer length. May contain any
 * character. Written like:
 *
 * <Int:length> <char[length]:chars>
 *
 * e.g. `7 foo bar` is the string "foo bar"
 *
 * ### Newline terminated strings <str>
 *
 * A string terminated by a new line. e.g. `foo bar\n`.
 *
 * # SUT Commands and responses
 *
 * TODO: Not all of these are implemented, see parse.rl.
 *
 * Most commands `cmd` respond with `+<sym:cmd> [<ID:id>]` or `-<sym:cmd>
 * [<ID:id>] <str:error>` to acknowledge the command.
 *
 * + `PING\n` -> PONG\n
 * + `ALLC <ID:id>\n` -> `+ALLC <ID:id>\n`
 * + `CMDS <ID:id> <sym:tid> <str:cmds>` -> `+CMDS <ID:id> <sym:tid> ...`
 * + `ENVE <ID:id> <sym:name> <str:value>` -> `+ENVE <ID:id> <sym:name> ...`
 * + `EXEC <ID:id>\n` -> `+EXEC <ID:id>\n`
 * + `FREE <ID:id>\n` -> `+FREE <ID:id>\n`
 * + `EXIT\n` -> `+EXIT\n` then `eof` ofcourse.
 *
 * # SUT Notifications
 *
 * + `FRKD <ID:id>\n`
 * + `LOGD <ID:id> <strn:log>\n`
 * + `TRET <ID:id> <int:returned>\n`
 * + `ERRD <ID:id> <str:message>`
 */

#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <getopt.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

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
	int result;
	struct cmds *test;
};

struct log {
	size_t len;
	char *tid;
	char buf[LEN_1024];
};

struct tres {
	char *tid;
	int result;
};

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
	int fd, r0;
	char buf[LEN_1024];

	/* I assume that setting the stdin FD itself to NONBLOCK will cause
	 * some unexpected behaviour somewhere. */
	fd = dup(STDIN_FILENO);
	fcntl(fd, F_SETFL, O_NONBLOCK);
	assert_perror(errno);

	parser_init();

	for (;;) {
		r0 = read(fd, buf, sizeof(buf));

		if (!r0)
			shutdown(self);

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

static void writer_hear(struct actor *self, struct msg *msg)
{
	struct log *log;
	struct tres *tres;
	struct cmds *cmds;

	/* TODO: It is critical we get log and test result messages out of the
	 * SUT as soon as possible. So we should avoid all unecessary work
	 * here. See tester_check/listen. */

	switch (msg->type) {
	case MSG_PONG:
		printf("PONG\n");
		break;

	case MSG_LOGD:
		log = msg->ptr;
		printf("LOGD %ld %s %ld ", addr_to_id(msg->from),
		       log->tid, log->len);
		fwrite(log->buf, sizeof(char), log->len, stdout);
		printf("\n");
		free(log);
		break;

	case MSG_TRES:
		tres = msg->ptr;
		printf("TRES %ld %s %d\n", addr_to_id(msg->from),
		       tres->tid, tres->result);
		free(tres);
		break;

	case MSG_EXIT:
		free(msg);
		printf("+EXIT\n");
		actor_exit(self);
		break;

	case MSG_CMDS:
		cmds = msg->ptr;
		printf("+CMDS %ld %s %s\n", addr_to_id(msg->from),
		       cmds->tid, cmds->cmds);
		break;

	case MSG_ERRO:
		printf("ERRO 0 %s\n", (char *)msg->ptr);
		break;

	case MSG_EXEC:
		printf("+EXEC %ld\n", addr_to_id(msg->from));
		break;
	case MSG_ALLC:
		printf("+ALLC %ld\n", addr_to_id(msg->from));
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
	tres->tid = my->test->tid;
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

static void tester_check_cout(struct actor *self)
{
	ssize_t r0;
	struct log *log = malloc(sizeof(*log));
	struct tester *my = self->priv;
	struct msg *msg;

	/* TODO: the writer could pass back spent log messages instead of
	 * recreating them. */
	/* TDOD: We don't want to malloc log buffers or messages in the tester
	 * listen loop atall */

	r0 = read(my->cout, log->buf, LEN_1024);

	switch(errno) {
	case EAGAIN:
	case EINTR:
		errno = 0;
		break;
	}

	assert_perror(errno);

	if (r0 < 0) {
		free(log);
		return;
	}

	if (!r0) {
		free(log);
		close(my->cout);
		my->cout = 0;
		return;
	}

	log->len = r0;
	log->tid = my->test->tid;

	msg = msg_alloc();
	msg->type = MSG_LOGD;
	msg->ptr = log;
	actor_say(self, ADDR_WRITER, msg);
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

		if (!(msg || my->child || my->cout))
			pthread_yield();

		if (msg)
			self->hear(self, msg);

		if (my->child)
			tester_check_child(self);

		if (my->cout)
			tester_check_cout(self);
	}
}

/* TODO: many/all runtest entries don't require sh. Some runtest entries set
 * an environment var beforehand which can be done with a seperate command. */
static void tester_exec(struct actor *self)
{
	int r0, r1;
	pid_t pid;
	int cin[2], cout[2];
	struct tester *my = self->priv;

	assert(!my->child);
	assert(my->test);
	assert(my->test->tid[0]);
	assert(my->test->cmds[0]);

	r0 = pipe(cin);
	r1 = pipe(cout);
	assert_perror(errno);
	assert(!r0);
	fcntl(cout[0], F_SETFL, O_NONBLOCK);
	assert(!r1);
	assert_perror(errno);

	pid = fork();
	assert_perror(errno);

	if (!pid) {
		close(cin[1]);
		close(cout[0]);
		dup2(cin[0], STDIN_FILENO);
		assert_perror(errno);
		dup2(cout[1], STDOUT_FILENO);
		assert_perror(errno);

		execlp("sh", "sh", (char *)NULL);
		assert_perror(errno);
	}

	close(cin[0]);
	close(cout[1]);

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
	my->child = pid;
}

static void tester_hear(struct actor *self, struct msg *msg)
{
	struct tester *my = self->priv;

	assert(my);

	switch (msg->type) {
	case MSG_CMDS:
		assert(msg->ptr);
		/* TODO: Leaks the previous struct cmds, but we can't just
		 * free it because there may be log/res messages with a
		 * pointer to the tid. Could use urcu_ref or hash the tid to a
		 * uint_64 */
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
	default:
		assert(0);
	}
}

void tester_start(addr_t id)
{
	struct actor *tester = actor_alloc();

	tester->addr = id;
	tester->listen = tester_listen;
	tester->hear = tester_hear;

	actor_start(tester);
}

int main(void/* int argc, char **argv */)
{
	int r0, r1;
	struct actor *reader, *writer;
	pthread_t reader_t, writer_t;

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

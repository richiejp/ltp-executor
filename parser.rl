#include <errno.h>
#include <stdlib.h>
#include <stddef.h>

#include "actors.h"
#include "executor.h"
#include "parser.h"

static void error_msg(struct actor *self, char *text)
{
	struct msg *msg = msg_alloc();

	msg->type = MSG_ERRO;
	msg->ptr = text;
	actor_say(self, ADDR_WRITER, msg);
}

/* Ragel finite state machine (FSM) definition for parsing commands
 *
 * It is much easier to understand this by looking at the state transition
 * graph e.g `ragel -V -p parser.rl | dot -Tsvg | display`
 *
 * */
%%{
	machine parse;

	include "parser-common.rl";

	action say_pong {
		msg = msg_alloc();
		msg->type = MSG_PONG;
		actor_say(self, ADDR_WRITER, msg);
	}

	action say_allc { tester_start(id); }

	action alloc_cmds {
		cmds = malloc(sizeof(*cmds));

		assert_perror(errno);
		assert(cmds);

		buf_len = sizeof(cmds->tid);
		buf = cmds->tid;
	}

	action set_cmds_tid {
		*buf = '\0';
		buf = cmds->cmds;
	}

	action say_cmds {
		*buf = '\0';
		buf = NULL;

		msg = msg_alloc();
		msg->type = MSG_CMDS;
		msg->ptr = cmds;

		actor_say(self, id, msg);
	}

	action say_exec {
		msg = msg_alloc();
		msg->type = MSG_EXEC;

		actor_say(self, id, msg);
	}

	action exit { shutdown(self); }

	action exp_cmd {
		error_msg(self, "Epected ping, allc, exit, cmds, or exec");
		fgoto main;
	}

	ping = "ping"i $err(exp_cmd) ws* nl @say_pong;

	allc = "allc"i $err(exp_cmd) ws+ >err(exp_ws)
		id ws* nl @say_allc;

	exit = "exit"i $err(exp_cmd) ws* nl @exit;

	cmds = "cmds"i $err(exp_cmd)
		ws+ >err(exp_ws)
		id %alloc_cmds
		ws+ >err(exp_ws)
		sym @add_char %set_cmds_tid
		ws+ >err(exp_ws)
		str @add_char
		nl @say_cmds;

	exec = "exec"i $err(exp_cmd) ws+ id ws* nl @say_exec;

	main := (ping | allc | exit | cmds | exec)*;

	write data nofinal noerror;
}%%

/* Holds the current state of the finite state machine
 */
static int cs;
static size_t n, id, buf_len;
static char *buf;
struct cmds *cmds;

void parser_init(void)
{
	%%{
		write init;
	}%%
}

/* Feed the parsing FSM a, possibly incomplete, stream of command data. The
 * state is retained between calls unless you call parser_init again
 */
void parser_feed(struct actor *self, char *str, size_t len)
{
	char *p = str, *pe = str + len;
	char *eof = NULL;
	struct msg *msg;

	%%{
		write exec;
	}%%
}

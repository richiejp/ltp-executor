#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "actors.h"
#include "executor.h"
#include "parser.h"

static void error_msg(struct actor *self __attribute__((unused)),
		      char *text)
{
	fprintf(stderr, "%s\n", text);
	assert(0);
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

	action exp_cmd {
		error_msg(self, "Epected ping, allc, exit, cmds, or exec");
		fgoto main;
	}

	action say_pong {
		msg = msg_alloc();
		msg->type = MSG_PONG;
		actor_say(self, ADDR_WRITER, msg);
	}

	action say_allc {  }

	pong = "PONG" $err(exp_cmd) nl @say_pong;

	allc = "+ALLC" $err(exp_cmd) ws >err(exp_ws)
		id nl @say_allc;

	main := (pong | allc)*;

	write data nofinal noerror;
}%%

/* Holds the current state of the finite state machine
 */
static int cs;
static size_t n, id/* , buf_len */;
/* static char *buf; */
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

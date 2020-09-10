// SPDX-License-Identifier: GPL-3.0-or-later
/*
 * Copyright (c) 2020 SUSE LLC
 */
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
 * You may be able to guess how Ragel expressions work if you are familiar
 * with regular expressions or lex, BNF etc., however note that side-effects
 * (actions) can be embedded within the Ragel expressions (see
 * http://www.colm.net/files/ragel/ragel-guide-6.10.pdf Chapter 3).
 */
%%{
	machine parse;

	include "parser-common.rl";

	action say_pong {
		msg = msg_alloc();
		msg->type = MSG_PONG;
		actor_say(self, ADDR_WRITER, msg);
	}

	action say_allc { tester_start(self, id); }

	action exit { shutdown(self); }

	action exp_cmd {
		error_msg(self, "Epected ping, allc, exit, cmds, or exec");
		fgoto clear;
	}

	ping = "ping"i $err(exp_cmd) ws* nl @say_pong;
	allc = "allc"i $err(exp_cmd) allc_body @say_allc;
	exit = "exit"i $err(exp_cmd) ws* nl @exit;
	cmds = "cmds"i $err(exp_cmd) cmds_body;
	exec = "exec"i $err(exp_cmd) exec_body;

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

// SPDX-License-Identifier: GPL-3.0-or-later
/*
 * Copyright (c) 2020 SUSE LLC
 */
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

/* Also See parser.rl commetns
 *
 * Note that the LOGD command is especially complex and uses a
 * 'semantic condition' with a entry guarded concatenation (<:) for
 * the length prefixed string.
 * */
%%{
	machine parse;

	include "parser-common.rl";

	action exp_cmd {
		DBG("Epected pong, +allc, +cmds, +exec, logd or tres.\nBuffer Dump: ");
		fwrite(str, 1, len, stderr);
	}

	action say_pong {
		msg = msg_alloc();
		msg->type = MSG_PONG;
		actor_say(self, ADDR_WRITER, msg);
		msg = NULL;
	}

	action say_allc {
		msg = msg_alloc();
		msg->type = MSG_ALLC;
		actor_say(self, id, msg);
		msg = NULL;
	}

	action alloc_log {
		msg = msg_alloc_extra(sizeof(*log));
		msg->type = MSG_LOGD;
		log = msg->ptr;
	}

	action set_log_buf {
		buf = log->buf;
		buf_len = LEN_1024;
	}

	action set_log_len {
		log->len = n;
		n = 0;
	}

	action say_log {
		*buf = '\0';
		assert(msg);
		actor_say(self, id, msg);
		msg = NULL;
	}

	action say_tres {
		msg = msg_alloc();
		msg->type = MSG_TRES;
		msg->val = n;
		actor_say(self, id, msg);
		msg = NULL;
	}

	pong = "PONG" $err(exp_cmd) nl @say_pong;
	allc = "+ALLC" $err(exp_cmd) allc_body @say_allc;
	cmds = "+CMDS" $err(exp_cmd) cmds_body;
	exec = "+EXEC" $err(exp_cmd) exec_body;
	logd = "LOGD" $err(exp_cmd) ws >err(exp_ws) >alloc_log
		id ws >err(exp_ws) %set_log_buf
		uint %set_log_len ws >err(exp_ws)
		( any* when { n < log->len } ) @add_char
		<: nl @say_log;
	tres = "TRES" $err(exp_cmd) ws >err(exp_ws)
		id ws >err(exp_ws)
		uint nl @say_tres;

	main := (pong | allc | cmds | exec | tres | logd)*;

	write data nofinal noerror;
}%%

static int cs;
static addr_t id;
static size_t n, buf_len;
static char *buf;
static struct cmds *cmds;
static struct log *log;
struct msg *msg;

void parser_init(void)
{
	%%{
		write init;
	}%%
}

void parser_feed(struct actor *self, char *str, size_t len)
{
	char *p = str, *pe = str + len;
	char *eof = NULL;

	%%{
		write exec;
	}%%
}

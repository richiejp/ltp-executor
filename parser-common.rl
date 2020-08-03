%%{
	machine parse;

	action first_digit { n = fc - '0'; }
	action add_digit { n = n * 10 + (fc - '0'); }

	action add_char {
		n++;
		actor_assert(n < buf_len - 1, "%zu >= %zu", n, buf_len);
		*(buf++) = fc;
	}

	action set_id {
		/* TODO: Validate ID */
		id = id_to_addr(n);
	}

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

	action exp_nl {
		error_msg(self, "Expected new line");
		fgoto main;
	}

	action exp_ws {
		error_msg(self, "Expected white space");
		fgoto main;
	}

	action exp_digit {
		error_msg(self, "Expected digit");
		fgoto main;
	}

	action exp_sym {
		error_msg(self, "Expected symbol character");
		fgoto main;
	}

	action exp_str {
		error_msg(self, "Expected string character");
		fgoto main;
	}

	nl = '\n' >err(exp_nl);
	ws = (space - [\n\r]);

	uint = (digit @first_digit digit* @add_digit) $err(exp_digit);
	id = uint %set_id;

	sym = (any - space)+ $err(exp_sym);
        str = (any - nl)+ $err(exp_str);

	allc_body = ws+ >err(exp_ws) id ws* nl;
	cmds_body = ws+ >err(exp_ws)
		id %alloc_cmds
		ws+ >err(exp_ws)
		sym @add_char %set_cmds_tid
		ws+ >err(exp_ws)
		str @add_char
		nl @say_cmds;
	exec_body = ws+ id ws* nl @say_exec;
}%%

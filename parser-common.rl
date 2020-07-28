%%{
	machine parse;

	action first_digit { n = fc - '0'; }
	action add_digit { n = n * 10 + (fc - '0'); }

	action add_char {
		n++;
		assert(n < buf_len - 1);
		*(buf++) = fc;
	}

	action set_id {
		/* TODO: Validate ID */
		id = id_to_addr(n);
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

	nl = '\n' %err(exp_nl);
	ws = (space - [\n\r]);

	uint = (digit @first_digit digit* @add_digit) $err(exp_digit);
	id = uint %set_id;

	sym = (any - space)+ $err(exp_sym);
        str = (any - nl)+ $err(exp_str);

}%%

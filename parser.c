#line 1 "/home/rich/qa/ltp-executor/parser.rl"
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

#line 35 "/home/rich/qa/ltp-executor/parser.c"
static const int parse_start = 33;

static const int parse_en_main = 33;


#line 64 "/home/rich/qa/ltp-executor/parser.rl"


/* Holds the current state of the finite state machine
*/
static int cs;
static size_t n, id, buf_len;
static char *buf;
struct cmds *cmds;

void parser_init(void)
{
	
#line 54 "/home/rich/qa/ltp-executor/parser.c"
	{
		cs = (int)parse_start;
	}
	
#line 77 "/home/rich/qa/ltp-executor/parser.rl"
	
}

/* Feed the parsing FSM a, possibly incomplete, stream of command data. The
* state is retained between calls unless you call parser_init again
*/
void parser_feed(struct actor *self, char *str, size_t len)
{
	char *p = str, *pe = str + len;
	char *eof = NULL;
	struct msg *msg;
	
	
#line 73 "/home/rich/qa/ltp-executor/parser.c"
	{
		
		_resume: {}
		if ( p == pe && p != eof )
			goto _out;
		switch ( cs ) {
			case 33:
			if ( p == eof ) {
				goto _ctr84;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 65: {
						goto _ctr85;
					}
					case 67: {
						goto _ctr86;
					}
					case 69: {
						goto _ctr87;
					}
					case 80: {
						goto _ctr88;
					}
					case 97: {
						goto _ctr85;
					}
					case 99: {
						goto _ctr86;
					}
					case 101: {
						goto _ctr87;
					}
					case 112: {
						goto _ctr88;
					}
				}
				goto _ctr2;
			}
			case 0:
			if ( p == eof ) {
				goto _ctr0;	goto _again;
			}
			else {
				goto _again;
			}
			case 1:
			if ( p == eof ) {
				goto _ctr1;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 76: {
						goto _ctr3;
					}
					case 108: {
						goto _ctr3;
					}
				}
				goto _ctr2;
			}
			case 2:
			if ( p == eof ) {
				goto _ctr4;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 76: {
						goto _ctr5;
					}
					case 108: {
						goto _ctr5;
					}
				}
				goto _ctr2;
			}
			case 3:
			if ( p == eof ) {
				goto _ctr6;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 67: {
						goto _ctr7;
					}
					case 99: {
						goto _ctr7;
					}
				}
				goto _ctr2;
			}
			case 4:
			if ( p == eof ) {
				goto _ctr8;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 9: {
						goto _ctr10;
					}
					case 32: {
						goto _ctr10;
					}
				}
				if ( 11 <= ( (*( p))) && ( (*( p))) <= 12 ) {
					goto _ctr10;
				}
				goto _ctr9;
			}
			case 5:
			if ( p == eof ) {
				goto _ctr11;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 9: {
						goto _ctr10;
					}
					case 32: {
						goto _ctr10;
					}
				}
				if ( ( (*( p))) > 12 ) {
					if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
						goto _ctr13;
					}
				} else if ( ( (*( p))) >= 11 ) {
					goto _ctr10;
				}
				goto _ctr12;
			}
			case 6:
			if ( p == eof ) {
				goto _ctr14;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 10: {
						goto _ctr17;
					}
					case 32: {
						goto _ctr16;
					}
				}
				if ( ( (*( p))) > 12 ) {
					if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
						goto _ctr18;
					}
				} else if ( ( (*( p))) >= 9 ) {
					goto _ctr16;
				}
				goto _ctr15;
			}
			case 7:
			if ( p == eof ) {
				goto _ctr19;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 10: {
						goto _ctr22;
					}
					case 32: {
						goto _ctr21;
					}
				}
				if ( 9 <= ( (*( p))) && ( (*( p))) <= 12 ) {
					goto _ctr21;
				}
				goto _ctr20;
			}
			case 8:
			if ( p == eof ) {
				goto _ctr23;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 77: {
						goto _ctr24;
					}
					case 109: {
						goto _ctr24;
					}
				}
				goto _ctr2;
			}
			case 9:
			if ( p == eof ) {
				goto _ctr25;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 68: {
						goto _ctr26;
					}
					case 100: {
						goto _ctr26;
					}
				}
				goto _ctr2;
			}
			case 10:
			if ( p == eof ) {
				goto _ctr27;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 83: {
						goto _ctr28;
					}
					case 115: {
						goto _ctr28;
					}
				}
				goto _ctr2;
			}
			case 11:
			if ( p == eof ) {
				goto _ctr29;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 9: {
						goto _ctr30;
					}
					case 32: {
						goto _ctr30;
					}
				}
				if ( 11 <= ( (*( p))) && ( (*( p))) <= 12 ) {
					goto _ctr30;
				}
				goto _ctr9;
			}
			case 12:
			if ( p == eof ) {
				goto _ctr31;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 9: {
						goto _ctr30;
					}
					case 32: {
						goto _ctr30;
					}
				}
				if ( ( (*( p))) > 12 ) {
					if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
						goto _ctr32;
					}
				} else if ( ( (*( p))) >= 11 ) {
					goto _ctr30;
				}
				goto _ctr12;
			}
			case 13:
			if ( p == eof ) {
				goto _ctr33;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 9: {
						goto _ctr35;
					}
					case 32: {
						goto _ctr35;
					}
				}
				if ( ( (*( p))) > 12 ) {
					if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
						goto _ctr36;
					}
				} else if ( ( (*( p))) >= 11 ) {
					goto _ctr35;
				}
				goto _ctr34;
			}
			case 14:
			if ( p == eof ) {
				goto _ctr37;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 10: {
						goto _ctr40;
					}
					case 13: {
						goto _ctr40;
					}
					case 32: {
						goto _ctr39;
					}
				}
				if ( 9 <= ( (*( p))) && ( (*( p))) <= 12 ) {
					goto _ctr39;
				}
				goto _ctr38;
			}
			case 15:
			if ( p == eof ) {
				goto _ctr41;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 10: {
						goto _ctr43;
					}
					case 13: {
						goto _ctr43;
					}
					case 32: {
						goto _ctr42;
					}
				}
				if ( 9 <= ( (*( p))) && ( (*( p))) <= 12 ) {
					goto _ctr42;
				}
				goto _ctr38;
			}
			case 16:
			if ( p == eof ) {
				goto _ctr44;	goto _again;
			}
			else {
				if ( ( (*( p))) == 10 ) {
					goto _ctr46;
				}
				goto _ctr45;
			}
			case 17:
			if ( p == eof ) {
				goto _ctr47;	goto _again;
			}
			else {
				if ( ( (*( p))) == 10 ) {
					goto _ctr48;
				}
				goto _ctr45;
			}
			case 18:
			if ( p == eof ) {
				goto _ctr49;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 88: {
						goto _ctr50;
					}
					case 120: {
						goto _ctr50;
					}
				}
				goto _ctr2;
			}
			case 19:
			if ( p == eof ) {
				goto _ctr51;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 69: {
						goto _ctr52;
					}
					case 73: {
						goto _ctr53;
					}
					case 101: {
						goto _ctr52;
					}
					case 105: {
						goto _ctr53;
					}
				}
				goto _ctr2;
			}
			case 20:
			if ( p == eof ) {
				goto _ctr54;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 67: {
						goto _ctr55;
					}
					case 99: {
						goto _ctr55;
					}
				}
				goto _ctr2;
			}
			case 21:
			if ( p == eof ) {
				goto _ctr56;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 9: {
						goto _ctr57;
					}
					case 32: {
						goto _ctr57;
					}
				}
				if ( 11 <= ( (*( p))) && ( (*( p))) <= 12 ) {
					goto _ctr57;
				}
				goto _ctr2;
			}
			case 22:
			if ( p == eof ) {
				goto _ctr58;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 9: {
						goto _ctr57;
					}
					case 32: {
						goto _ctr57;
					}
				}
				if ( ( (*( p))) > 12 ) {
					if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
						goto _ctr59;
					}
				} else if ( ( (*( p))) >= 11 ) {
					goto _ctr57;
				}
				goto _ctr12;
			}
			case 23:
			if ( p == eof ) {
				goto _ctr60;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 10: {
						goto _ctr62;
					}
					case 32: {
						goto _ctr61;
					}
				}
				if ( ( (*( p))) > 12 ) {
					if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
						goto _ctr63;
					}
				} else if ( ( (*( p))) >= 9 ) {
					goto _ctr61;
				}
				goto _ctr15;
			}
			case 24:
			if ( p == eof ) {
				goto _ctr64;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 10: {
						goto _ctr66;
					}
					case 32: {
						goto _ctr65;
					}
				}
				if ( 9 <= ( (*( p))) && ( (*( p))) <= 12 ) {
					goto _ctr65;
				}
				goto _ctr20;
			}
			case 25:
			if ( p == eof ) {
				goto _ctr67;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 84: {
						goto _ctr68;
					}
					case 116: {
						goto _ctr68;
					}
				}
				goto _ctr2;
			}
			case 26:
			if ( p == eof ) {
				goto _ctr69;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 10: {
						goto _ctr72;
					}
					case 32: {
						goto _ctr71;
					}
				}
				if ( 9 <= ( (*( p))) && ( (*( p))) <= 12 ) {
					goto _ctr71;
				}
				goto _ctr70;
			}
			case 27:
			if ( p == eof ) {
				goto _ctr73;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 10: {
						goto _ctr72;
					}
					case 32: {
						goto _ctr71;
					}
				}
				if ( 9 <= ( (*( p))) && ( (*( p))) <= 12 ) {
					goto _ctr71;
				}
				goto _ctr20;
			}
			case 28:
			if ( p == eof ) {
				goto _ctr74;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 73: {
						goto _ctr75;
					}
					case 105: {
						goto _ctr75;
					}
				}
				goto _ctr2;
			}
			case 29:
			if ( p == eof ) {
				goto _ctr76;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 78: {
						goto _ctr77;
					}
					case 110: {
						goto _ctr77;
					}
				}
				goto _ctr2;
			}
			case 30:
			if ( p == eof ) {
				goto _ctr78;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 71: {
						goto _ctr79;
					}
					case 103: {
						goto _ctr79;
					}
				}
				goto _ctr2;
			}
			case 31:
			if ( p == eof ) {
				goto _ctr80;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 10: {
						goto _ctr82;
					}
					case 32: {
						goto _ctr81;
					}
				}
				if ( 9 <= ( (*( p))) && ( (*( p))) <= 12 ) {
					goto _ctr81;
				}
				goto _ctr70;
			}
			case 32:
			if ( p == eof ) {
				goto _ctr83;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 10: {
						goto _ctr82;
					}
					case 32: {
						goto _ctr81;
					}
				}
				if ( 9 <= ( (*( p))) && ( (*( p))) <= 12 ) {
					goto _ctr81;
				}
				goto _ctr20;
			}
		}
		
		_ctr0: cs = 0; goto _again;
		_ctr2: cs = 0; goto f0;
		_ctr9: cs = 0; goto f1;
		_ctr12: cs = 0; goto f2;
		_ctr15: cs = 0; goto f4;
		_ctr20: cs = 0; goto f8;
		_ctr34: cs = 0; goto f10;
		_ctr40: cs = 0; goto f12;
		_ctr43: cs = 0; goto f14;
		_ctr46: cs = 0; goto f16;
		_ctr70: cs = 0; goto f20;
		_ctr85: cs = 1; goto _again;
		_ctr1: cs = 1; goto f0;
		_ctr3: cs = 2; goto _again;
		_ctr4: cs = 2; goto f0;
		_ctr5: cs = 3; goto _again;
		_ctr6: cs = 3; goto f0;
		_ctr7: cs = 4; goto _again;
		_ctr8: cs = 4; goto f1;
		_ctr10: cs = 5; goto _again;
		_ctr11: cs = 5; goto f2;
		_ctr13: cs = 6; goto f3;
		_ctr14: cs = 6; goto f4;
		_ctr18: cs = 6; goto f7;
		_ctr21: cs = 7; goto _again;
		_ctr16: cs = 7; goto f5;
		_ctr19: cs = 7; goto f8;
		_ctr86: cs = 8; goto _again;
		_ctr23: cs = 8; goto f0;
		_ctr24: cs = 9; goto _again;
		_ctr25: cs = 9; goto f0;
		_ctr26: cs = 10; goto _again;
		_ctr27: cs = 10; goto f0;
		_ctr28: cs = 11; goto _again;
		_ctr29: cs = 11; goto f1;
		_ctr30: cs = 12; goto _again;
		_ctr31: cs = 12; goto f2;
		_ctr32: cs = 13; goto f3;
		_ctr36: cs = 13; goto f7;
		_ctr33: cs = 13; goto f10;
		_ctr39: cs = 14; goto _again;
		_ctr35: cs = 14; goto f11;
		_ctr37: cs = 14; goto f12;
		_ctr38: cs = 15; goto f13;
		_ctr41: cs = 15; goto f14;
		_ctr42: cs = 16; goto f15;
		_ctr44: cs = 16; goto f16;
		_ctr45: cs = 17; goto f13;
		_ctr47: cs = 17; goto f16;
		_ctr87: cs = 18; goto _again;
		_ctr49: cs = 18; goto f0;
		_ctr50: cs = 19; goto _again;
		_ctr51: cs = 19; goto f0;
		_ctr52: cs = 20; goto _again;
		_ctr54: cs = 20; goto f0;
		_ctr55: cs = 21; goto _again;
		_ctr56: cs = 21; goto f0;
		_ctr57: cs = 22; goto _again;
		_ctr58: cs = 22; goto f2;
		_ctr59: cs = 23; goto f3;
		_ctr60: cs = 23; goto f4;
		_ctr63: cs = 23; goto f7;
		_ctr65: cs = 24; goto _again;
		_ctr61: cs = 24; goto f5;
		_ctr64: cs = 24; goto f8;
		_ctr53: cs = 25; goto _again;
		_ctr67: cs = 25; goto f0;
		_ctr68: cs = 26; goto _again;
		_ctr69: cs = 26; goto f20;
		_ctr71: cs = 27; goto _again;
		_ctr73: cs = 27; goto f8;
		_ctr88: cs = 28; goto _again;
		_ctr74: cs = 28; goto f0;
		_ctr75: cs = 29; goto _again;
		_ctr76: cs = 29; goto f0;
		_ctr77: cs = 30; goto _again;
		_ctr78: cs = 30; goto f0;
		_ctr79: cs = 31; goto _again;
		_ctr80: cs = 31; goto f20;
		_ctr81: cs = 32; goto _again;
		_ctr83: cs = 32; goto f8;
		_ctr84: cs = 33; goto _again;
		_ctr17: cs = 33; goto f6;
		_ctr22: cs = 33; goto f9;
		_ctr48: cs = 33; goto f17;
		_ctr62: cs = 33; goto f18;
		_ctr66: cs = 33; goto f19;
		_ctr72: cs = 33; goto f21;
		_ctr82: cs = 33; goto f22;
		
		f3:
		{
#line 4 "/home/rich/qa/ltp-executor/parser-common.rl"
			n = (( (*( p)))) - '0'; }
		
#line 774 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f7:
		{
#line 5 "/home/rich/qa/ltp-executor/parser-common.rl"
			n = n * 10 + ((( (*( p)))) - '0'); }
		
#line 781 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f13:
		{
#line 7 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			n++;
			actor_assert(n < buf_len, "%zu >= %zu", n, buf_len);
			*(buf++) = (( (*( p))));
		}
		
#line 792 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f5:
		{
#line 13 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			/* TODO: Validate ID */
			id = id_to_addr(n);
		}
		
#line 802 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f15:
		{
#line 28 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			*buf = '\0';
			buf = cmds->cmds;
		}
		
#line 812 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f17:
		{
#line 33 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			*buf = '\0';
			buf = NULL;
			
			msg = msg_alloc();
			msg->type = MSG_CMDS;
			msg->ptr = cmds;
			
			actor_say(self, id, msg);
		}
		
#line 828 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f19:
		{
#line 44 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			msg = msg_alloc();
			msg->type = MSG_EXEC;
			
			actor_say(self, id, msg);
		}
		
#line 840 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f8:
		{
#line 51 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected new line");
			{cs = 33; goto _again;}}
		
#line 849 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f2:
		{
#line 61 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected digit");
			{cs = 33; goto _again;}}
		
#line 858 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f12:
		{
#line 66 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected symbol character");
			{cs = 33; goto _again;}}
		
#line 867 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f22:
		{
#line 37 "/home/rich/qa/ltp-executor/parser.rl"
			
			msg = msg_alloc();
			msg->type = MSG_PONG;
			actor_say(self, ADDR_WRITER, msg);
		}
		
#line 878 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f9:
		{
#line 43 "/home/rich/qa/ltp-executor/parser.rl"
			tester_start(self, id); }
		
#line 885 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f21:
		{
#line 45 "/home/rich/qa/ltp-executor/parser.rl"
			shutdown(self); }
		
#line 892 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f0:
		{
#line 47 "/home/rich/qa/ltp-executor/parser.rl"
			
			error_msg(self, "Epected ping, allc, exit, cmds, or exec");
			/* TODO: Errors are probably most common when a user is typing
			* stuff in manually. So we can reduce some noise by clearing
			* the read buffer up to the first newline char (if any) */
			{cs = 33; goto _again;}}
		
#line 904 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f11:
		{
#line 13 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			/* TODO: Validate ID */
			id = id_to_addr(n);
		}
		
#line 914 "/home/rich/qa/ltp-executor/parser.c"
		{
#line 18 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			cmds = malloc(sizeof(*cmds));
			
			assert_perror(errno);
			assert(cmds);
			
			buf_len = sizeof(cmds->tid);
			buf = cmds->tid;
		}
		
#line 927 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f18:
		{
#line 13 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			/* TODO: Validate ID */
			id = id_to_addr(n);
		}
		
#line 937 "/home/rich/qa/ltp-executor/parser.c"
		{
#line 44 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			msg = msg_alloc();
			msg->type = MSG_EXEC;
			
			actor_say(self, id, msg);
		}
		
#line 947 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f6:
		{
#line 13 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			/* TODO: Validate ID */
			id = id_to_addr(n);
		}
		
#line 957 "/home/rich/qa/ltp-executor/parser.c"
		{
#line 43 "/home/rich/qa/ltp-executor/parser.rl"
			tester_start(self, id); }
		
#line 962 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f16:
		{
#line 51 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected new line");
			{cs = 33; goto _again;}}
		
#line 971 "/home/rich/qa/ltp-executor/parser.c"
		{
#line 71 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected string character");
			{cs = 33; goto _again;}}
		
#line 978 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f4:
		{
#line 61 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected digit");
			{cs = 33; goto _again;}}
		
#line 987 "/home/rich/qa/ltp-executor/parser.c"
		{
#line 51 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected new line");
			{cs = 33; goto _again;}}
		
#line 994 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f10:
		{
#line 61 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected digit");
			{cs = 33; goto _again;}}
		
#line 1003 "/home/rich/qa/ltp-executor/parser.c"
		{
#line 56 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected white space");
			{cs = 33; goto _again;}}
		
#line 1010 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f14:
		{
#line 66 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected symbol character");
			{cs = 33; goto _again;}}
		
#line 1019 "/home/rich/qa/ltp-executor/parser.c"
		{
#line 56 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected white space");
			{cs = 33; goto _again;}}
		
#line 1026 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f20:
		{
#line 47 "/home/rich/qa/ltp-executor/parser.rl"
			
			error_msg(self, "Epected ping, allc, exit, cmds, or exec");
			/* TODO: Errors are probably most common when a user is typing
			* stuff in manually. So we can reduce some noise by clearing
			* the read buffer up to the first newline char (if any) */
			{cs = 33; goto _again;}}
		
#line 1038 "/home/rich/qa/ltp-executor/parser.c"
		{
#line 51 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected new line");
			{cs = 33; goto _again;}}
		
#line 1045 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f1:
		{
#line 47 "/home/rich/qa/ltp-executor/parser.rl"
			
			error_msg(self, "Epected ping, allc, exit, cmds, or exec");
			/* TODO: Errors are probably most common when a user is typing
			* stuff in manually. So we can reduce some noise by clearing
			* the read buffer up to the first newline char (if any) */
			{cs = 33; goto _again;}}
		
#line 1057 "/home/rich/qa/ltp-executor/parser.c"
		{
#line 56 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected white space");
			{cs = 33; goto _again;}}
		
#line 1064 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		
		_again: {}
		if ( p == eof ) {
			if ( cs >= 33 )
				goto _out;
		}
		else {
			if ( cs != 0 ) {
				p += 1;
				goto _resume;
			}
		}
		_out: {}
	}
	
#line 91 "/home/rich/qa/ltp-executor/parser.rl"
	
}

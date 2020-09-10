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
static const int parse_start = 39;

static const int parse_en_clear = 37;
static const int parse_en_main = 39;


#line 61 "/home/rich/qa/ltp-executor/parser.rl"


/* Holds the current state of the finite state machine
*/
static int cs;
static size_t n, id, buf_len;
static char *buf;
struct cmds *cmds;

void parser_init(void)
{
	
#line 55 "/home/rich/qa/ltp-executor/parser.c"
	{
		cs = (int)parse_start;
	}
	
#line 74 "/home/rich/qa/ltp-executor/parser.rl"
	
}

/* Feed the parsing FSM a, possibly incomplete, stream of command data. The
* state is retained between calls unless you call parser_init again
*/
void parser_feed(struct actor *self, char *str, size_t len)
{
	char *p = str, *pe = str + len;
	char *eof = NULL;
	struct msg *msg;
	
	
#line 74 "/home/rich/qa/ltp-executor/parser.c"
	{
		
		_resume: {}
		if ( p == pe && p != eof )
			goto _out;
		switch ( cs ) {
			case 39:
			if ( p == eof ) {
				goto _ctr97;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 65: {
						goto _ctr98;
					}
					case 67: {
						goto _ctr99;
					}
					case 69: {
						goto _ctr100;
					}
					case 80: {
						goto _ctr101;
					}
					case 97: {
						goto _ctr98;
					}
					case 99: {
						goto _ctr99;
					}
					case 101: {
						goto _ctr100;
					}
					case 112: {
						goto _ctr101;
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
					case 13: {
						goto _ctr18;
					}
					case 32: {
						goto _ctr16;
					}
				}
				if ( ( (*( p))) > 12 ) {
					if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
						goto _ctr19;
					}
				} else if ( ( (*( p))) >= 9 ) {
					goto _ctr16;
				}
				goto _ctr15;
			}
			case 7:
			if ( p == eof ) {
				goto _ctr20;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 10: {
						goto _ctr23;
					}
					case 13: {
						goto _ctr24;
					}
					case 32: {
						goto _ctr22;
					}
				}
				if ( 9 <= ( (*( p))) && ( (*( p))) <= 12 ) {
					goto _ctr22;
				}
				goto _ctr21;
			}
			case 8:
			if ( p == eof ) {
				goto _ctr25;	goto _again;
			}
			else {
				if ( ( (*( p))) == 10 ) {
					goto _ctr23;
				}
				goto _ctr21;
			}
			case 9:
			if ( p == eof ) {
				goto _ctr26;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 77: {
						goto _ctr27;
					}
					case 109: {
						goto _ctr27;
					}
				}
				goto _ctr2;
			}
			case 10:
			if ( p == eof ) {
				goto _ctr28;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 68: {
						goto _ctr29;
					}
					case 100: {
						goto _ctr29;
					}
				}
				goto _ctr2;
			}
			case 11:
			if ( p == eof ) {
				goto _ctr30;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 83: {
						goto _ctr31;
					}
					case 115: {
						goto _ctr31;
					}
				}
				goto _ctr2;
			}
			case 12:
			if ( p == eof ) {
				goto _ctr32;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 9: {
						goto _ctr33;
					}
					case 32: {
						goto _ctr33;
					}
				}
				if ( 11 <= ( (*( p))) && ( (*( p))) <= 12 ) {
					goto _ctr33;
				}
				goto _ctr9;
			}
			case 13:
			if ( p == eof ) {
				goto _ctr34;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 9: {
						goto _ctr33;
					}
					case 32: {
						goto _ctr33;
					}
				}
				if ( ( (*( p))) > 12 ) {
					if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
						goto _ctr35;
					}
				} else if ( ( (*( p))) >= 11 ) {
					goto _ctr33;
				}
				goto _ctr12;
			}
			case 14:
			if ( p == eof ) {
				goto _ctr36;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 9: {
						goto _ctr38;
					}
					case 32: {
						goto _ctr38;
					}
				}
				if ( ( (*( p))) > 12 ) {
					if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
						goto _ctr39;
					}
				} else if ( ( (*( p))) >= 11 ) {
					goto _ctr38;
				}
				goto _ctr37;
			}
			case 15:
			if ( p == eof ) {
				goto _ctr40;	goto _again;
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
				goto _ctr41;
			}
			case 16:
			if ( p == eof ) {
				goto _ctr44;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 10: {
						goto _ctr46;
					}
					case 13: {
						goto _ctr46;
					}
					case 32: {
						goto _ctr45;
					}
				}
				if ( 9 <= ( (*( p))) && ( (*( p))) <= 12 ) {
					goto _ctr45;
				}
				goto _ctr41;
			}
			case 17:
			if ( p == eof ) {
				goto _ctr47;	goto _again;
			}
			else {
				if ( ( (*( p))) == 10 ) {
					goto _ctr49;
				}
				goto _ctr48;
			}
			case 18:
			if ( p == eof ) {
				goto _ctr50;	goto _again;
			}
			else {
				if ( ( (*( p))) == 10 ) {
					goto _ctr51;
				}
				goto _ctr48;
			}
			case 19:
			if ( p == eof ) {
				goto _ctr52;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 88: {
						goto _ctr53;
					}
					case 120: {
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
					case 69: {
						goto _ctr55;
					}
					case 73: {
						goto _ctr56;
					}
					case 101: {
						goto _ctr55;
					}
					case 105: {
						goto _ctr56;
					}
				}
				goto _ctr2;
			}
			case 21:
			if ( p == eof ) {
				goto _ctr57;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 67: {
						goto _ctr58;
					}
					case 99: {
						goto _ctr58;
					}
				}
				goto _ctr2;
			}
			case 22:
			if ( p == eof ) {
				goto _ctr59;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 9: {
						goto _ctr60;
					}
					case 32: {
						goto _ctr60;
					}
				}
				if ( 11 <= ( (*( p))) && ( (*( p))) <= 12 ) {
					goto _ctr60;
				}
				goto _ctr2;
			}
			case 23:
			if ( p == eof ) {
				goto _ctr61;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 9: {
						goto _ctr60;
					}
					case 32: {
						goto _ctr60;
					}
				}
				if ( ( (*( p))) > 12 ) {
					if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
						goto _ctr62;
					}
				} else if ( ( (*( p))) >= 11 ) {
					goto _ctr60;
				}
				goto _ctr12;
			}
			case 24:
			if ( p == eof ) {
				goto _ctr63;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 10: {
						goto _ctr65;
					}
					case 13: {
						goto _ctr66;
					}
					case 32: {
						goto _ctr64;
					}
				}
				if ( ( (*( p))) > 12 ) {
					if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
						goto _ctr67;
					}
				} else if ( ( (*( p))) >= 9 ) {
					goto _ctr64;
				}
				goto _ctr15;
			}
			case 25:
			if ( p == eof ) {
				goto _ctr68;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 10: {
						goto _ctr70;
					}
					case 13: {
						goto _ctr71;
					}
					case 32: {
						goto _ctr69;
					}
				}
				if ( 9 <= ( (*( p))) && ( (*( p))) <= 12 ) {
					goto _ctr69;
				}
				goto _ctr21;
			}
			case 26:
			if ( p == eof ) {
				goto _ctr72;	goto _again;
			}
			else {
				if ( ( (*( p))) == 10 ) {
					goto _ctr70;
				}
				goto _ctr21;
			}
			case 27:
			if ( p == eof ) {
				goto _ctr73;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 84: {
						goto _ctr74;
					}
					case 116: {
						goto _ctr74;
					}
				}
				goto _ctr2;
			}
			case 28:
			if ( p == eof ) {
				goto _ctr75;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 10: {
						goto _ctr78;
					}
					case 13: {
						goto _ctr79;
					}
					case 32: {
						goto _ctr77;
					}
				}
				if ( 9 <= ( (*( p))) && ( (*( p))) <= 12 ) {
					goto _ctr77;
				}
				goto _ctr76;
			}
			case 29:
			if ( p == eof ) {
				goto _ctr80;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 10: {
						goto _ctr78;
					}
					case 13: {
						goto _ctr79;
					}
					case 32: {
						goto _ctr77;
					}
				}
				if ( 9 <= ( (*( p))) && ( (*( p))) <= 12 ) {
					goto _ctr77;
				}
				goto _ctr21;
			}
			case 30:
			if ( p == eof ) {
				goto _ctr81;	goto _again;
			}
			else {
				if ( ( (*( p))) == 10 ) {
					goto _ctr78;
				}
				goto _ctr21;
			}
			case 31:
			if ( p == eof ) {
				goto _ctr82;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 73: {
						goto _ctr83;
					}
					case 105: {
						goto _ctr83;
					}
				}
				goto _ctr2;
			}
			case 32:
			if ( p == eof ) {
				goto _ctr84;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 78: {
						goto _ctr85;
					}
					case 110: {
						goto _ctr85;
					}
				}
				goto _ctr2;
			}
			case 33:
			if ( p == eof ) {
				goto _ctr86;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 71: {
						goto _ctr87;
					}
					case 103: {
						goto _ctr87;
					}
				}
				goto _ctr2;
			}
			case 34:
			if ( p == eof ) {
				goto _ctr88;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 10: {
						goto _ctr90;
					}
					case 13: {
						goto _ctr91;
					}
					case 32: {
						goto _ctr89;
					}
				}
				if ( 9 <= ( (*( p))) && ( (*( p))) <= 12 ) {
					goto _ctr89;
				}
				goto _ctr76;
			}
			case 35:
			if ( p == eof ) {
				goto _ctr92;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 10: {
						goto _ctr90;
					}
					case 13: {
						goto _ctr91;
					}
					case 32: {
						goto _ctr89;
					}
				}
				if ( 9 <= ( (*( p))) && ( (*( p))) <= 12 ) {
					goto _ctr89;
				}
				goto _ctr21;
			}
			case 36:
			if ( p == eof ) {
				goto _ctr93;	goto _again;
			}
			else {
				if ( ( (*( p))) == 10 ) {
					goto _ctr90;
				}
				goto _ctr21;
			}
			case 37:
			if ( p == eof ) {
				goto _ctr94;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 10: {
						goto _ctr95;
					}
					case 13: {
						goto _ctr96;
					}
				}
				goto _ctr94;
			}
			case 40:
			if ( p == eof ) {
				goto _ctr102;	goto _again;
			}
			else {
				goto _ctr0;
			}
			case 38:
			if ( p == eof ) {
				goto _ctr96;	goto _again;
			}
			else {
				if ( ( (*( p))) == 10 ) {
					goto _ctr95;
				}
				goto _ctr0;
			}
		}
		
		_ctr0: cs = 0; goto _again;
		_ctr2: cs = 0; goto f0;
		_ctr9: cs = 0; goto f1;
		_ctr12: cs = 0; goto f2;
		_ctr15: cs = 0; goto f4;
		_ctr21: cs = 0; goto f8;
		_ctr37: cs = 0; goto f10;
		_ctr43: cs = 0; goto f12;
		_ctr46: cs = 0; goto f14;
		_ctr49: cs = 0; goto f16;
		_ctr76: cs = 0; goto f20;
		_ctr98: cs = 1; goto _again;
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
		_ctr19: cs = 6; goto f7;
		_ctr22: cs = 7; goto _again;
		_ctr16: cs = 7; goto f5;
		_ctr20: cs = 7; goto f8;
		_ctr24: cs = 8; goto _again;
		_ctr18: cs = 8; goto f5;
		_ctr25: cs = 8; goto f8;
		_ctr99: cs = 9; goto _again;
		_ctr26: cs = 9; goto f0;
		_ctr27: cs = 10; goto _again;
		_ctr28: cs = 10; goto f0;
		_ctr29: cs = 11; goto _again;
		_ctr30: cs = 11; goto f0;
		_ctr31: cs = 12; goto _again;
		_ctr32: cs = 12; goto f1;
		_ctr33: cs = 13; goto _again;
		_ctr34: cs = 13; goto f2;
		_ctr35: cs = 14; goto f3;
		_ctr39: cs = 14; goto f7;
		_ctr36: cs = 14; goto f10;
		_ctr42: cs = 15; goto _again;
		_ctr38: cs = 15; goto f11;
		_ctr40: cs = 15; goto f12;
		_ctr41: cs = 16; goto f13;
		_ctr44: cs = 16; goto f14;
		_ctr45: cs = 17; goto f15;
		_ctr47: cs = 17; goto f16;
		_ctr48: cs = 18; goto f13;
		_ctr50: cs = 18; goto f16;
		_ctr100: cs = 19; goto _again;
		_ctr52: cs = 19; goto f0;
		_ctr53: cs = 20; goto _again;
		_ctr54: cs = 20; goto f0;
		_ctr55: cs = 21; goto _again;
		_ctr57: cs = 21; goto f0;
		_ctr58: cs = 22; goto _again;
		_ctr59: cs = 22; goto f0;
		_ctr60: cs = 23; goto _again;
		_ctr61: cs = 23; goto f2;
		_ctr62: cs = 24; goto f3;
		_ctr63: cs = 24; goto f4;
		_ctr67: cs = 24; goto f7;
		_ctr69: cs = 25; goto _again;
		_ctr64: cs = 25; goto f5;
		_ctr68: cs = 25; goto f8;
		_ctr71: cs = 26; goto _again;
		_ctr66: cs = 26; goto f5;
		_ctr72: cs = 26; goto f8;
		_ctr56: cs = 27; goto _again;
		_ctr73: cs = 27; goto f0;
		_ctr74: cs = 28; goto _again;
		_ctr75: cs = 28; goto f20;
		_ctr77: cs = 29; goto _again;
		_ctr80: cs = 29; goto f8;
		_ctr79: cs = 30; goto _again;
		_ctr81: cs = 30; goto f8;
		_ctr101: cs = 31; goto _again;
		_ctr82: cs = 31; goto f0;
		_ctr83: cs = 32; goto _again;
		_ctr84: cs = 32; goto f0;
		_ctr85: cs = 33; goto _again;
		_ctr86: cs = 33; goto f0;
		_ctr87: cs = 34; goto _again;
		_ctr88: cs = 34; goto f20;
		_ctr89: cs = 35; goto _again;
		_ctr92: cs = 35; goto f8;
		_ctr91: cs = 36; goto _again;
		_ctr93: cs = 36; goto f8;
		_ctr94: cs = 37; goto _again;
		_ctr96: cs = 38; goto _again;
		_ctr97: cs = 39; goto _again;
		_ctr17: cs = 39; goto f6;
		_ctr23: cs = 39; goto f9;
		_ctr51: cs = 39; goto f17;
		_ctr65: cs = 39; goto f18;
		_ctr70: cs = 39; goto f19;
		_ctr78: cs = 39; goto f21;
		_ctr90: cs = 39; goto f22;
		_ctr102: cs = 40; goto _again;
		_ctr95: cs = 40; goto f23;
		
		f3:
		{
#line 4 "/home/rich/qa/ltp-executor/parser-common.rl"
			n = (( (*( p)))) - '0'; }
		
#line 885 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f7:
		{
#line 5 "/home/rich/qa/ltp-executor/parser-common.rl"
			n = n * 10 + ((( (*( p)))) - '0'); }
		
#line 892 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f13:
		{
#line 7 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			n++;
			actor_assert(n < buf_len, "%zu >= %zu", n, buf_len);
			*(buf++) = (( (*( p))));
		}
		
#line 903 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f5:
		{
#line 13 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			/* TODO: Validate ID */
			id = id_to_addr(n);
		}
		
#line 913 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f15:
		{
#line 28 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			*buf = '\0';
			buf_len = sizeof(cmds->cmds);
			buf = cmds->cmds;
		}
		
#line 924 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f17:
		{
#line 34 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			*buf = '\0';
			buf = NULL;
			
			msg = msg_alloc();
			msg->type = MSG_CMDS;
			msg->ptr = cmds;
			
			actor_say(self, id, msg);
		}
		
#line 940 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f19:
		{
#line 45 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			msg = msg_alloc();
			msg->type = MSG_EXEC;
			
			actor_say(self, id, msg);
		}
		
#line 952 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f8:
		{
#line 52 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected new line");
			{cs = 37; goto _again;}}
		
#line 961 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f2:
		{
#line 62 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected digit");
			{cs = 37; goto _again;}}
		
#line 970 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f12:
		{
#line 67 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected symbol character");
			{cs = 37; goto _again;}}
		
#line 979 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f23:
		{
#line 77 "/home/rich/qa/ltp-executor/parser-common.rl"
			{cs = 39; goto _again;}}
		
#line 986 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f22:
		{
#line 37 "/home/rich/qa/ltp-executor/parser.rl"
			
			msg = msg_alloc();
			msg->type = MSG_PONG;
			actor_say(self, ADDR_WRITER, msg);
		}
		
#line 997 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f9:
		{
#line 43 "/home/rich/qa/ltp-executor/parser.rl"
			tester_start(self, id); }
		
#line 1004 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f21:
		{
#line 45 "/home/rich/qa/ltp-executor/parser.rl"
			shutdown(self); }
		
#line 1011 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f0:
		{
#line 47 "/home/rich/qa/ltp-executor/parser.rl"
			
			error_msg(self, "Epected ping, allc, exit, cmds, or exec");
			{cs = 37; goto _again;}}
		
#line 1020 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f11:
		{
#line 13 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			/* TODO: Validate ID */
			id = id_to_addr(n);
		}
		
#line 1030 "/home/rich/qa/ltp-executor/parser.c"
		{
#line 18 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			cmds = malloc(sizeof(*cmds));
			
			assert_perror(errno);
			assert(cmds);
			
			buf_len = sizeof(cmds->tid);
			buf = cmds->tid;
		}
		
#line 1043 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f18:
		{
#line 13 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			/* TODO: Validate ID */
			id = id_to_addr(n);
		}
		
#line 1053 "/home/rich/qa/ltp-executor/parser.c"
		{
#line 45 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			msg = msg_alloc();
			msg->type = MSG_EXEC;
			
			actor_say(self, id, msg);
		}
		
#line 1063 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f6:
		{
#line 13 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			/* TODO: Validate ID */
			id = id_to_addr(n);
		}
		
#line 1073 "/home/rich/qa/ltp-executor/parser.c"
		{
#line 43 "/home/rich/qa/ltp-executor/parser.rl"
			tester_start(self, id); }
		
#line 1078 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f16:
		{
#line 52 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected new line");
			{cs = 37; goto _again;}}
		
#line 1087 "/home/rich/qa/ltp-executor/parser.c"
		{
#line 72 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected string character");
			{cs = 37; goto _again;}}
		
#line 1094 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f4:
		{
#line 62 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected digit");
			{cs = 37; goto _again;}}
		
#line 1103 "/home/rich/qa/ltp-executor/parser.c"
		{
#line 52 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected new line");
			{cs = 37; goto _again;}}
		
#line 1110 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f10:
		{
#line 62 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected digit");
			{cs = 37; goto _again;}}
		
#line 1119 "/home/rich/qa/ltp-executor/parser.c"
		{
#line 57 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected white space");
			{cs = 37; goto _again;}}
		
#line 1126 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f14:
		{
#line 67 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected symbol character");
			{cs = 37; goto _again;}}
		
#line 1135 "/home/rich/qa/ltp-executor/parser.c"
		{
#line 57 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected white space");
			{cs = 37; goto _again;}}
		
#line 1142 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f20:
		{
#line 47 "/home/rich/qa/ltp-executor/parser.rl"
			
			error_msg(self, "Epected ping, allc, exit, cmds, or exec");
			{cs = 37; goto _again;}}
		
#line 1151 "/home/rich/qa/ltp-executor/parser.c"
		{
#line 52 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected new line");
			{cs = 37; goto _again;}}
		
#line 1158 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		f1:
		{
#line 47 "/home/rich/qa/ltp-executor/parser.rl"
			
			error_msg(self, "Epected ping, allc, exit, cmds, or exec");
			{cs = 37; goto _again;}}
		
#line 1167 "/home/rich/qa/ltp-executor/parser.c"
		{
#line 57 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected white space");
			{cs = 37; goto _again;}}
		
#line 1174 "/home/rich/qa/ltp-executor/parser.c"
		goto _again;
		
		_again: {}
		if ( p == eof ) {
			if ( cs >= 39 )
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
	
#line 88 "/home/rich/qa/ltp-executor/parser.rl"
	
}

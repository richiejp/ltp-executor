#line 1 "/home/rich/qa/ltp-executor/driver-parser.rl"
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

#line 30 "/home/rich/qa/ltp-executor/driver-parser.c"
static const int parse_start = 47;

static const int parse_en_main = 47;


#line 98 "/home/rich/qa/ltp-executor/driver-parser.rl"


static int cs;
static addr_t id;
static size_t n, buf_len;
static char *buf;
static struct cmds *cmds;
static struct log *log;
struct msg *msg;

void parser_init(void)
{
	
#line 50 "/home/rich/qa/ltp-executor/driver-parser.c"
	{
		cs = (int)parse_start;
	}
	
#line 112 "/home/rich/qa/ltp-executor/driver-parser.rl"
	
}

void parser_feed(struct actor *self, char *str, size_t len)
{
	char *p = str, *pe = str + len;
	char *eof = NULL;
	
	
#line 65 "/home/rich/qa/ltp-executor/driver-parser.c"
	{
		int _ck;
		
		_resume: {}
		if ( p == pe && p != eof )
			goto _out;
		switch ( cs ) {
			case 47:
			if ( p == eof ) {
				goto _ctr119;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 43: {
						goto _ctr120;
					}
					case 76: {
						goto _ctr121;
					}
					case 80: {
						goto _ctr122;
					}
					case 84: {
						goto _ctr123;
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
					case 65: {
						goto _ctr3;
					}
					case 67: {
						goto _ctr4;
					}
					case 69: {
						goto _ctr5;
					}
				}
				goto _ctr2;
			}
			case 2:
			if ( p == eof ) {
				goto _ctr6;	goto _again;
			}
			else {
				if ( ( (*( p))) == 76 ) {
					goto _ctr7;
				}
				goto _ctr2;
			}
			case 3:
			if ( p == eof ) {
				goto _ctr8;	goto _again;
			}
			else {
				if ( ( (*( p))) == 76 ) {
					goto _ctr9;
				}
				goto _ctr2;
			}
			case 4:
			if ( p == eof ) {
				goto _ctr10;	goto _again;
			}
			else {
				if ( ( (*( p))) == 67 ) {
					goto _ctr11;
				}
				goto _ctr2;
			}
			case 5:
			if ( p == eof ) {
				goto _ctr12;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 9: {
						goto _ctr14;
					}
					case 32: {
						goto _ctr14;
					}
				}
				if ( 11 <= ( (*( p))) && ( (*( p))) <= 12 ) {
					goto _ctr14;
				}
				goto _ctr13;
			}
			case 6:
			if ( p == eof ) {
				goto _ctr15;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 9: {
						goto _ctr14;
					}
					case 32: {
						goto _ctr14;
					}
				}
				if ( ( (*( p))) > 12 ) {
					if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
						goto _ctr17;
					}
				} else if ( ( (*( p))) >= 11 ) {
					goto _ctr14;
				}
				goto _ctr16;
			}
			case 7:
			if ( p == eof ) {
				goto _ctr18;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 10: {
						goto _ctr21;
					}
					case 32: {
						goto _ctr20;
					}
				}
				if ( ( (*( p))) > 12 ) {
					if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
						goto _ctr22;
					}
				} else if ( ( (*( p))) >= 9 ) {
					goto _ctr20;
				}
				goto _ctr19;
			}
			case 8:
			if ( p == eof ) {
				goto _ctr23;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 10: {
						goto _ctr26;
					}
					case 32: {
						goto _ctr25;
					}
				}
				if ( 9 <= ( (*( p))) && ( (*( p))) <= 12 ) {
					goto _ctr25;
				}
				goto _ctr24;
			}
			case 9:
			if ( p == eof ) {
				goto _ctr27;	goto _again;
			}
			else {
				if ( ( (*( p))) == 77 ) {
					goto _ctr28;
				}
				goto _ctr2;
			}
			case 10:
			if ( p == eof ) {
				goto _ctr29;	goto _again;
			}
			else {
				if ( ( (*( p))) == 68 ) {
					goto _ctr30;
				}
				goto _ctr2;
			}
			case 11:
			if ( p == eof ) {
				goto _ctr31;	goto _again;
			}
			else {
				if ( ( (*( p))) == 83 ) {
					goto _ctr32;
				}
				goto _ctr2;
			}
			case 12:
			if ( p == eof ) {
				goto _ctr33;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 9: {
						goto _ctr34;
					}
					case 32: {
						goto _ctr34;
					}
				}
				if ( 11 <= ( (*( p))) && ( (*( p))) <= 12 ) {
					goto _ctr34;
				}
				goto _ctr13;
			}
			case 13:
			if ( p == eof ) {
				goto _ctr35;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 9: {
						goto _ctr34;
					}
					case 32: {
						goto _ctr34;
					}
				}
				if ( ( (*( p))) > 12 ) {
					if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
						goto _ctr36;
					}
				} else if ( ( (*( p))) >= 11 ) {
					goto _ctr34;
				}
				goto _ctr16;
			}
			case 14:
			if ( p == eof ) {
				goto _ctr37;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 9: {
						goto _ctr39;
					}
					case 32: {
						goto _ctr39;
					}
				}
				if ( ( (*( p))) > 12 ) {
					if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
						goto _ctr40;
					}
				} else if ( ( (*( p))) >= 11 ) {
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
						goto _ctr44;
					}
					case 13: {
						goto _ctr44;
					}
					case 32: {
						goto _ctr43;
					}
				}
				if ( 9 <= ( (*( p))) && ( (*( p))) <= 12 ) {
					goto _ctr43;
				}
				goto _ctr42;
			}
			case 16:
			if ( p == eof ) {
				goto _ctr45;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 10: {
						goto _ctr47;
					}
					case 13: {
						goto _ctr47;
					}
					case 32: {
						goto _ctr46;
					}
				}
				if ( 9 <= ( (*( p))) && ( (*( p))) <= 12 ) {
					goto _ctr46;
				}
				goto _ctr42;
			}
			case 17:
			if ( p == eof ) {
				goto _ctr48;	goto _again;
			}
			else {
				if ( ( (*( p))) == 10 ) {
					goto _ctr50;
				}
				goto _ctr49;
			}
			case 18:
			if ( p == eof ) {
				goto _ctr51;	goto _again;
			}
			else {
				if ( ( (*( p))) == 10 ) {
					goto _ctr52;
				}
				goto _ctr49;
			}
			case 19:
			if ( p == eof ) {
				goto _ctr53;	goto _again;
			}
			else {
				if ( ( (*( p))) == 88 ) {
					goto _ctr54;
				}
				goto _ctr2;
			}
			case 20:
			if ( p == eof ) {
				goto _ctr55;	goto _again;
			}
			else {
				if ( ( (*( p))) == 69 ) {
					goto _ctr56;
				}
				goto _ctr2;
			}
			case 21:
			if ( p == eof ) {
				goto _ctr57;	goto _again;
			}
			else {
				if ( ( (*( p))) == 67 ) {
					goto _ctr58;
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
				goto _ctr16;
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
					case 32: {
						goto _ctr64;
					}
				}
				if ( ( (*( p))) > 12 ) {
					if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
						goto _ctr66;
					}
				} else if ( ( (*( p))) >= 9 ) {
					goto _ctr64;
				}
				goto _ctr19;
			}
			case 25:
			if ( p == eof ) {
				goto _ctr67;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 10: {
						goto _ctr69;
					}
					case 32: {
						goto _ctr68;
					}
				}
				if ( 9 <= ( (*( p))) && ( (*( p))) <= 12 ) {
					goto _ctr68;
				}
				goto _ctr24;
			}
			case 26:
			if ( p == eof ) {
				goto _ctr70;	goto _again;
			}
			else {
				if ( ( (*( p))) == 79 ) {
					goto _ctr71;
				}
				goto _ctr2;
			}
			case 27:
			if ( p == eof ) {
				goto _ctr72;	goto _again;
			}
			else {
				if ( ( (*( p))) == 71 ) {
					goto _ctr73;
				}
				goto _ctr2;
			}
			case 28:
			if ( p == eof ) {
				goto _ctr74;	goto _again;
			}
			else {
				if ( ( (*( p))) == 68 ) {
					goto _ctr75;
				}
				goto _ctr2;
			}
			case 29:
			if ( p == eof ) {
				goto _ctr76;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 9: {
						goto _ctr77;
					}
					case 32: {
						goto _ctr77;
					}
				}
				if ( 11 <= ( (*( p))) && ( (*( p))) <= 12 ) {
					goto _ctr77;
				}
				goto _ctr13;
			}
			case 30:
			if ( p == eof ) {
				goto _ctr78;	goto _again;
			}
			else {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto _ctr79;
				}
				goto _ctr16;
			}
			case 31:
			if ( p == eof ) {
				goto _ctr80;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 9: {
						goto _ctr81;
					}
					case 32: {
						goto _ctr81;
					}
				}
				if ( ( (*( p))) > 12 ) {
					if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
						goto _ctr82;
					}
				} else if ( ( (*( p))) >= 11 ) {
					goto _ctr81;
				}
				goto _ctr38;
			}
			case 32:
			if ( p == eof ) {
				goto _ctr83;	goto _again;
			}
			else {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto _ctr84;
				}
				goto _ctr16;
			}
			case 33:
			if ( p == eof ) {
				goto _ctr85;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 9: {
						goto _ctr86;
					}
					case 32: {
						goto _ctr86;
					}
				}
				if ( ( (*( p))) > 12 ) {
					if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
						goto _ctr87;
					}
				} else if ( ( (*( p))) >= 11 ) {
					goto _ctr86;
				}
				goto _ctr38;
			}
			case 34:
			if ( p == eof ) {
				goto _ctr88;	goto _again;
			}
			else {
				if ( ( (*( p))) == 10 ) {
					_ck = 0;
					if ( ( n < log->len )
#line 613 "/home/rich/qa/ltp-executor/driver-parser.c"
					)
					_ck += 1;
					if ( _ck > 0 ) {
						goto _ctr90;
					} else {
						goto _ctr91;
					}
					
				}
				_ck = 0;
				if ( ( n < log->len )
#line 625 "/home/rich/qa/ltp-executor/driver-parser.c"
				)
				_ck += 1;
				if ( _ck > 0 ) {
					goto _ctr90;
				} else {
					goto _ctr89;
				}
				
			}
			case 35:
			if ( p == eof ) {
				goto _ctr92;	goto _again;
			}
			else {
				if ( ( (*( p))) == 79 ) {
					goto _ctr93;
				}
				goto _ctr2;
			}
			case 36:
			if ( p == eof ) {
				goto _ctr94;	goto _again;
			}
			else {
				if ( ( (*( p))) == 78 ) {
					goto _ctr95;
				}
				goto _ctr2;
			}
			case 37:
			if ( p == eof ) {
				goto _ctr96;	goto _again;
			}
			else {
				if ( ( (*( p))) == 71 ) {
					goto _ctr97;
				}
				goto _ctr2;
			}
			case 38:
			if ( p == eof ) {
				goto _ctr98;	goto _again;
			}
			else {
				if ( ( (*( p))) == 10 ) {
					goto _ctr100;
				}
				goto _ctr99;
			}
			case 39:
			if ( p == eof ) {
				goto _ctr101;	goto _again;
			}
			else {
				if ( ( (*( p))) == 82 ) {
					goto _ctr102;
				}
				goto _ctr2;
			}
			case 40:
			if ( p == eof ) {
				goto _ctr103;	goto _again;
			}
			else {
				if ( ( (*( p))) == 69 ) {
					goto _ctr104;
				}
				goto _ctr2;
			}
			case 41:
			if ( p == eof ) {
				goto _ctr105;	goto _again;
			}
			else {
				if ( ( (*( p))) == 83 ) {
					goto _ctr106;
				}
				goto _ctr2;
			}
			case 42:
			if ( p == eof ) {
				goto _ctr107;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 9: {
						goto _ctr108;
					}
					case 32: {
						goto _ctr108;
					}
				}
				if ( 11 <= ( (*( p))) && ( (*( p))) <= 12 ) {
					goto _ctr108;
				}
				goto _ctr13;
			}
			case 43:
			if ( p == eof ) {
				goto _ctr109;	goto _again;
			}
			else {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto _ctr110;
				}
				goto _ctr16;
			}
			case 44:
			if ( p == eof ) {
				goto _ctr111;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 9: {
						goto _ctr112;
					}
					case 32: {
						goto _ctr112;
					}
				}
				if ( ( (*( p))) > 12 ) {
					if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
						goto _ctr113;
					}
				} else if ( ( (*( p))) >= 11 ) {
					goto _ctr112;
				}
				goto _ctr38;
			}
			case 45:
			if ( p == eof ) {
				goto _ctr114;	goto _again;
			}
			else {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto _ctr115;
				}
				goto _ctr16;
			}
			case 46:
			if ( p == eof ) {
				goto _ctr116;	goto _again;
			}
			else {
				if ( ( (*( p))) == 10 ) {
					goto _ctr117;
				}
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto _ctr118;
				}
				goto _ctr19;
			}
		}
		
		_ctr0: cs = 0; goto _again;
		_ctr2: cs = 0; goto f0;
		_ctr13: cs = 0; goto f1;
		_ctr16: cs = 0; goto f2;
		_ctr19: cs = 0; goto f4;
		_ctr24: cs = 0; goto f8;
		_ctr38: cs = 0; goto f10;
		_ctr44: cs = 0; goto f12;
		_ctr47: cs = 0; goto f14;
		_ctr50: cs = 0; goto f16;
		_ctr99: cs = 0; goto f24;
		_ctr120: cs = 1; goto _again;
		_ctr1: cs = 1; goto f0;
		_ctr3: cs = 2; goto _again;
		_ctr6: cs = 2; goto f0;
		_ctr7: cs = 3; goto _again;
		_ctr8: cs = 3; goto f0;
		_ctr9: cs = 4; goto _again;
		_ctr10: cs = 4; goto f0;
		_ctr11: cs = 5; goto _again;
		_ctr12: cs = 5; goto f1;
		_ctr14: cs = 6; goto _again;
		_ctr15: cs = 6; goto f2;
		_ctr17: cs = 7; goto f3;
		_ctr18: cs = 7; goto f4;
		_ctr22: cs = 7; goto f7;
		_ctr25: cs = 8; goto _again;
		_ctr20: cs = 8; goto f5;
		_ctr23: cs = 8; goto f8;
		_ctr4: cs = 9; goto _again;
		_ctr27: cs = 9; goto f0;
		_ctr28: cs = 10; goto _again;
		_ctr29: cs = 10; goto f0;
		_ctr30: cs = 11; goto _again;
		_ctr31: cs = 11; goto f0;
		_ctr32: cs = 12; goto _again;
		_ctr33: cs = 12; goto f1;
		_ctr34: cs = 13; goto _again;
		_ctr35: cs = 13; goto f2;
		_ctr36: cs = 14; goto f3;
		_ctr40: cs = 14; goto f7;
		_ctr37: cs = 14; goto f10;
		_ctr43: cs = 15; goto _again;
		_ctr39: cs = 15; goto f11;
		_ctr41: cs = 15; goto f12;
		_ctr42: cs = 16; goto f13;
		_ctr45: cs = 16; goto f14;
		_ctr46: cs = 17; goto f15;
		_ctr48: cs = 17; goto f16;
		_ctr49: cs = 18; goto f13;
		_ctr51: cs = 18; goto f16;
		_ctr5: cs = 19; goto _again;
		_ctr53: cs = 19; goto f0;
		_ctr54: cs = 20; goto _again;
		_ctr55: cs = 20; goto f0;
		_ctr56: cs = 21; goto _again;
		_ctr57: cs = 21; goto f0;
		_ctr58: cs = 22; goto _again;
		_ctr59: cs = 22; goto f0;
		_ctr60: cs = 23; goto _again;
		_ctr61: cs = 23; goto f2;
		_ctr62: cs = 24; goto f3;
		_ctr63: cs = 24; goto f4;
		_ctr66: cs = 24; goto f7;
		_ctr68: cs = 25; goto _again;
		_ctr64: cs = 25; goto f5;
		_ctr67: cs = 25; goto f8;
		_ctr121: cs = 26; goto _again;
		_ctr70: cs = 26; goto f0;
		_ctr71: cs = 27; goto _again;
		_ctr72: cs = 27; goto f0;
		_ctr73: cs = 28; goto _again;
		_ctr74: cs = 28; goto f0;
		_ctr75: cs = 29; goto _again;
		_ctr76: cs = 29; goto f1;
		_ctr78: cs = 30; goto f2;
		_ctr77: cs = 30; goto f20;
		_ctr79: cs = 31; goto f3;
		_ctr82: cs = 31; goto f7;
		_ctr80: cs = 31; goto f10;
		_ctr83: cs = 32; goto f2;
		_ctr81: cs = 32; goto f5;
		_ctr87: cs = 33; goto f7;
		_ctr85: cs = 33; goto f10;
		_ctr84: cs = 33; goto f21;
		_ctr88: cs = 34; goto f8;
		_ctr86: cs = 34; goto f22;
		_ctr122: cs = 35; goto _again;
		_ctr92: cs = 35; goto f0;
		_ctr93: cs = 36; goto _again;
		_ctr94: cs = 36; goto f0;
		_ctr95: cs = 37; goto _again;
		_ctr96: cs = 37; goto f0;
		_ctr97: cs = 38; goto _again;
		_ctr98: cs = 38; goto f24;
		_ctr123: cs = 39; goto _again;
		_ctr101: cs = 39; goto f0;
		_ctr102: cs = 40; goto _again;
		_ctr103: cs = 40; goto f0;
		_ctr104: cs = 41; goto _again;
		_ctr105: cs = 41; goto f0;
		_ctr106: cs = 42; goto _again;
		_ctr107: cs = 42; goto f1;
		_ctr108: cs = 43; goto _again;
		_ctr109: cs = 43; goto f2;
		_ctr110: cs = 44; goto f3;
		_ctr113: cs = 44; goto f7;
		_ctr111: cs = 44; goto f10;
		_ctr114: cs = 45; goto f2;
		_ctr112: cs = 45; goto f5;
		_ctr115: cs = 46; goto f3;
		_ctr116: cs = 46; goto f4;
		_ctr118: cs = 46; goto f7;
		_ctr119: cs = 47; goto _again;
		_ctr21: cs = 47; goto f6;
		_ctr26: cs = 47; goto f9;
		_ctr52: cs = 47; goto f17;
		_ctr65: cs = 47; goto f18;
		_ctr69: cs = 47; goto f19;
		_ctr100: cs = 47; goto f25;
		_ctr117: cs = 47; goto f26;
		_ctr89: cs = 0; goto f8;
		_ctr90: cs = 34; goto f13;
		_ctr91: cs = 47; goto f23;
		
		f3:
		{
#line 4 "/home/rich/qa/ltp-executor/parser-common.rl"
			n = (( (*( p)))) - '0'; }
		
#line 910 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f7:
		{
#line 5 "/home/rich/qa/ltp-executor/parser-common.rl"
			n = n * 10 + ((( (*( p)))) - '0'); }
		
#line 917 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f13:
		{
#line 7 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			n++;
			actor_assert(n < buf_len, "%zu >= %zu", n, buf_len);
			*(buf++) = (( (*( p))));
		}
		
#line 928 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f5:
		{
#line 13 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			/* TODO: Validate ID */
			id = id_to_addr(n);
		}
		
#line 938 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f15:
		{
#line 28 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			*buf = '\0';
			buf = cmds->cmds;
		}
		
#line 948 "/home/rich/qa/ltp-executor/driver-parser.c"
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
		
#line 964 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f19:
		{
#line 44 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			msg = msg_alloc();
			msg->type = MSG_EXEC;
			
			actor_say(self, id, msg);
		}
		
#line 976 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f8:
		{
#line 51 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected new line");
			{cs = 47; goto _again;}}
		
#line 985 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f2:
		{
#line 61 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected digit");
			{cs = 47; goto _again;}}
		
#line 994 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f12:
		{
#line 66 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected symbol character");
			{cs = 47; goto _again;}}
		
#line 1003 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f0:
		{
#line 32 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			DBG("Epected pong, +allc, +cmds, +exec, logd or tres.\nBuffer Dump: ");
			fwrite(str, 1, len, stderr);
		}
		
#line 1013 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f25:
		{
#line 37 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			msg = msg_alloc();
			msg->type = MSG_PONG;
			actor_say(self, ADDR_WRITER, msg);
			msg = NULL;
		}
		
#line 1025 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f9:
		{
#line 44 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			msg = msg_alloc();
			msg->type = MSG_ALLC;
			actor_say(self, id, msg);
			msg = NULL;
		}
		
#line 1037 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f20:
		{
#line 51 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			msg = msg_alloc_extra(sizeof(*log));
			msg->type = MSG_LOGD;
			log = msg->ptr;
		}
		
#line 1048 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f22:
		{
#line 62 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			log->len = n;
			n = 0;
		}
		
#line 1058 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f23:
		{
#line 67 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			*buf = '\0';
			assert(msg);
			actor_say(self, id, msg);
			msg = NULL;
		}
		
#line 1070 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f26:
		{
#line 74 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			msg = msg_alloc();
			msg->type = MSG_TRES;
			msg->val = n;
			actor_say(self, id, msg);
			msg = NULL;
		}
		
#line 1083 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f11:
		{
#line 13 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			/* TODO: Validate ID */
			id = id_to_addr(n);
		}
		
#line 1093 "/home/rich/qa/ltp-executor/driver-parser.c"
		{
#line 18 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			cmds = malloc(sizeof(*cmds));
			
			assert_perror(errno);
			assert(cmds);
			
			buf_len = sizeof(cmds->tid);
			buf = cmds->tid;
		}
		
#line 1106 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f18:
		{
#line 13 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			/* TODO: Validate ID */
			id = id_to_addr(n);
		}
		
#line 1116 "/home/rich/qa/ltp-executor/driver-parser.c"
		{
#line 44 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			msg = msg_alloc();
			msg->type = MSG_EXEC;
			
			actor_say(self, id, msg);
		}
		
#line 1126 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f6:
		{
#line 13 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			/* TODO: Validate ID */
			id = id_to_addr(n);
		}
		
#line 1136 "/home/rich/qa/ltp-executor/driver-parser.c"
		{
#line 44 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			msg = msg_alloc();
			msg->type = MSG_ALLC;
			actor_say(self, id, msg);
			msg = NULL;
		}
		
#line 1146 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f16:
		{
#line 51 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected new line");
			{cs = 47; goto _again;}}
		
#line 1155 "/home/rich/qa/ltp-executor/driver-parser.c"
		{
#line 71 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected string character");
			{cs = 47; goto _again;}}
		
#line 1162 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f4:
		{
#line 61 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected digit");
			{cs = 47; goto _again;}}
		
#line 1171 "/home/rich/qa/ltp-executor/driver-parser.c"
		{
#line 51 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected new line");
			{cs = 47; goto _again;}}
		
#line 1178 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f10:
		{
#line 61 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected digit");
			{cs = 47; goto _again;}}
		
#line 1187 "/home/rich/qa/ltp-executor/driver-parser.c"
		{
#line 56 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected white space");
			{cs = 47; goto _again;}}
		
#line 1194 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f14:
		{
#line 66 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected symbol character");
			{cs = 47; goto _again;}}
		
#line 1203 "/home/rich/qa/ltp-executor/driver-parser.c"
		{
#line 56 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected white space");
			{cs = 47; goto _again;}}
		
#line 1210 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f24:
		{
#line 32 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			DBG("Epected pong, +allc, +cmds, +exec, logd or tres.\nBuffer Dump: ");
			fwrite(str, 1, len, stderr);
		}
		
#line 1220 "/home/rich/qa/ltp-executor/driver-parser.c"
		{
#line 51 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected new line");
			{cs = 47; goto _again;}}
		
#line 1227 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f1:
		{
#line 32 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			DBG("Epected pong, +allc, +cmds, +exec, logd or tres.\nBuffer Dump: ");
			fwrite(str, 1, len, stderr);
		}
		
#line 1237 "/home/rich/qa/ltp-executor/driver-parser.c"
		{
#line 56 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected white space");
			{cs = 47; goto _again;}}
		
#line 1244 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f21:
		{
#line 57 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			buf = log->buf;
			buf_len = LEN_1024;
		}
		
#line 1254 "/home/rich/qa/ltp-executor/driver-parser.c"
		{
#line 4 "/home/rich/qa/ltp-executor/parser-common.rl"
			n = (( (*( p)))) - '0'; }
		
#line 1259 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		
		_again: {}
		if ( p == eof ) {
			if ( cs >= 47 )
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
	
#line 122 "/home/rich/qa/ltp-executor/driver-parser.rl"
	
}

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
}

/* Also See parser.rl commetns
*
* Note that the LOGD command is especially complex and uses a
* 'semantic condition' with a entry guarded concatenation (<:) for
* the length prefixed string.
* */

#line 29 "/home/rich/qa/ltp-executor/driver-parser.c"
static const int parse_start = 54;

static const int parse_en_clear = 52;
static const int parse_en_main = 54;


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
			case 54:
			if ( p == eof ) {
				goto _ctr135;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 43: {
						goto _ctr136;
					}
					case 76: {
						goto _ctr137;
					}
					case 80: {
						goto _ctr138;
					}
					case 84: {
						goto _ctr139;
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
					case 13: {
						goto _ctr22;
					}
					case 32: {
						goto _ctr20;
					}
				}
				if ( ( (*( p))) > 12 ) {
					if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
						goto _ctr23;
					}
				} else if ( ( (*( p))) >= 9 ) {
					goto _ctr20;
				}
				goto _ctr19;
			}
			case 8:
			if ( p == eof ) {
				goto _ctr24;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 10: {
						goto _ctr27;
					}
					case 13: {
						goto _ctr28;
					}
					case 32: {
						goto _ctr26;
					}
				}
				if ( 9 <= ( (*( p))) && ( (*( p))) <= 12 ) {
					goto _ctr26;
				}
				goto _ctr25;
			}
			case 9:
			if ( p == eof ) {
				goto _ctr29;	goto _again;
			}
			else {
				if ( ( (*( p))) == 10 ) {
					goto _ctr27;
				}
				goto _ctr25;
			}
			case 10:
			if ( p == eof ) {
				goto _ctr30;	goto _again;
			}
			else {
				if ( ( (*( p))) == 77 ) {
					goto _ctr31;
				}
				goto _ctr2;
			}
			case 11:
			if ( p == eof ) {
				goto _ctr32;	goto _again;
			}
			else {
				if ( ( (*( p))) == 68 ) {
					goto _ctr33;
				}
				goto _ctr2;
			}
			case 12:
			if ( p == eof ) {
				goto _ctr34;	goto _again;
			}
			else {
				if ( ( (*( p))) == 83 ) {
					goto _ctr35;
				}
				goto _ctr2;
			}
			case 13:
			if ( p == eof ) {
				goto _ctr36;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 9: {
						goto _ctr37;
					}
					case 32: {
						goto _ctr37;
					}
				}
				if ( 11 <= ( (*( p))) && ( (*( p))) <= 12 ) {
					goto _ctr37;
				}
				goto _ctr13;
			}
			case 14:
			if ( p == eof ) {
				goto _ctr38;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 9: {
						goto _ctr37;
					}
					case 32: {
						goto _ctr37;
					}
				}
				if ( ( (*( p))) > 12 ) {
					if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
						goto _ctr39;
					}
				} else if ( ( (*( p))) >= 11 ) {
					goto _ctr37;
				}
				goto _ctr16;
			}
			case 15:
			if ( p == eof ) {
				goto _ctr40;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 9: {
						goto _ctr42;
					}
					case 32: {
						goto _ctr42;
					}
				}
				if ( ( (*( p))) > 12 ) {
					if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
						goto _ctr43;
					}
				} else if ( ( (*( p))) >= 11 ) {
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
				goto _ctr45;
			}
			case 17:
			if ( p == eof ) {
				goto _ctr48;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 10: {
						goto _ctr50;
					}
					case 13: {
						goto _ctr50;
					}
					case 32: {
						goto _ctr49;
					}
				}
				if ( 9 <= ( (*( p))) && ( (*( p))) <= 12 ) {
					goto _ctr49;
				}
				goto _ctr45;
			}
			case 18:
			if ( p == eof ) {
				goto _ctr51;	goto _again;
			}
			else {
				if ( ( (*( p))) == 10 ) {
					goto _ctr53;
				}
				goto _ctr52;
			}
			case 19:
			if ( p == eof ) {
				goto _ctr54;	goto _again;
			}
			else {
				if ( ( (*( p))) == 10 ) {
					goto _ctr55;
				}
				goto _ctr52;
			}
			case 20:
			if ( p == eof ) {
				goto _ctr56;	goto _again;
			}
			else {
				if ( ( (*( p))) == 88 ) {
					goto _ctr57;
				}
				goto _ctr2;
			}
			case 21:
			if ( p == eof ) {
				goto _ctr58;	goto _again;
			}
			else {
				if ( ( (*( p))) == 69 ) {
					goto _ctr59;
				}
				goto _ctr2;
			}
			case 22:
			if ( p == eof ) {
				goto _ctr60;	goto _again;
			}
			else {
				if ( ( (*( p))) == 67 ) {
					goto _ctr61;
				}
				goto _ctr2;
			}
			case 23:
			if ( p == eof ) {
				goto _ctr62;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 9: {
						goto _ctr63;
					}
					case 32: {
						goto _ctr63;
					}
				}
				if ( 11 <= ( (*( p))) && ( (*( p))) <= 12 ) {
					goto _ctr63;
				}
				goto _ctr2;
			}
			case 24:
			if ( p == eof ) {
				goto _ctr64;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 9: {
						goto _ctr63;
					}
					case 32: {
						goto _ctr63;
					}
				}
				if ( ( (*( p))) > 12 ) {
					if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
						goto _ctr65;
					}
				} else if ( ( (*( p))) >= 11 ) {
					goto _ctr63;
				}
				goto _ctr16;
			}
			case 25:
			if ( p == eof ) {
				goto _ctr66;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 10: {
						goto _ctr68;
					}
					case 13: {
						goto _ctr69;
					}
					case 32: {
						goto _ctr67;
					}
				}
				if ( ( (*( p))) > 12 ) {
					if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
						goto _ctr70;
					}
				} else if ( ( (*( p))) >= 9 ) {
					goto _ctr67;
				}
				goto _ctr19;
			}
			case 26:
			if ( p == eof ) {
				goto _ctr71;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 10: {
						goto _ctr73;
					}
					case 13: {
						goto _ctr74;
					}
					case 32: {
						goto _ctr72;
					}
				}
				if ( 9 <= ( (*( p))) && ( (*( p))) <= 12 ) {
					goto _ctr72;
				}
				goto _ctr25;
			}
			case 27:
			if ( p == eof ) {
				goto _ctr75;	goto _again;
			}
			else {
				if ( ( (*( p))) == 10 ) {
					goto _ctr73;
				}
				goto _ctr25;
			}
			case 28:
			if ( p == eof ) {
				goto _ctr76;	goto _again;
			}
			else {
				if ( ( (*( p))) == 79 ) {
					goto _ctr77;
				}
				goto _ctr2;
			}
			case 29:
			if ( p == eof ) {
				goto _ctr78;	goto _again;
			}
			else {
				if ( ( (*( p))) == 71 ) {
					goto _ctr79;
				}
				goto _ctr2;
			}
			case 30:
			if ( p == eof ) {
				goto _ctr80;	goto _again;
			}
			else {
				if ( ( (*( p))) == 68 ) {
					goto _ctr81;
				}
				goto _ctr2;
			}
			case 31:
			if ( p == eof ) {
				goto _ctr82;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 9: {
						goto _ctr83;
					}
					case 32: {
						goto _ctr83;
					}
				}
				if ( 11 <= ( (*( p))) && ( (*( p))) <= 12 ) {
					goto _ctr83;
				}
				goto _ctr13;
			}
			case 32:
			if ( p == eof ) {
				goto _ctr84;	goto _again;
			}
			else {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto _ctr85;
				}
				goto _ctr16;
			}
			case 33:
			if ( p == eof ) {
				goto _ctr86;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 9: {
						goto _ctr87;
					}
					case 32: {
						goto _ctr87;
					}
				}
				if ( ( (*( p))) > 12 ) {
					if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
						goto _ctr88;
					}
				} else if ( ( (*( p))) >= 11 ) {
					goto _ctr87;
				}
				goto _ctr41;
			}
			case 34:
			if ( p == eof ) {
				goto _ctr89;	goto _again;
			}
			else {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto _ctr90;
				}
				goto _ctr16;
			}
			case 35:
			if ( p == eof ) {
				goto _ctr91;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 9: {
						goto _ctr92;
					}
					case 32: {
						goto _ctr92;
					}
				}
				if ( ( (*( p))) > 12 ) {
					if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
						goto _ctr93;
					}
				} else if ( ( (*( p))) >= 11 ) {
					goto _ctr92;
				}
				goto _ctr41;
			}
			case 36:
			if ( p == eof ) {
				goto _ctr94;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 10: {
						_ck = 0;
						if ( ( n < log->len )
#line 646 "/home/rich/qa/ltp-executor/driver-parser.c"
						)
						_ck += 1;
						if ( _ck > 0 ) {
							goto _ctr96;
						} else {
							goto _ctr97;
						}
						
					}
					case 13: {
						_ck = 0;
						if ( ( n < log->len )
#line 659 "/home/rich/qa/ltp-executor/driver-parser.c"
						)
						_ck += 1;
						if ( _ck > 0 ) {
							goto _ctr96;
						} else {
							goto _ctr98;
						}
						
					}
				}
				_ck = 0;
				if ( ( n < log->len )
#line 672 "/home/rich/qa/ltp-executor/driver-parser.c"
				)
				_ck += 1;
				if ( _ck > 0 ) {
					goto _ctr96;
				} else {
					goto _ctr95;
				}
				
			}
			case 37:
			if ( p == eof ) {
				goto _ctr99;	goto _again;
			}
			else {
				if ( ( (*( p))) == 10 ) {
					goto _ctr100;
				}
				goto _ctr25;
			}
			case 38:
			if ( p == eof ) {
				goto _ctr101;	goto _again;
			}
			else {
				if ( ( (*( p))) == 79 ) {
					goto _ctr102;
				}
				goto _ctr2;
			}
			case 39:
			if ( p == eof ) {
				goto _ctr103;	goto _again;
			}
			else {
				if ( ( (*( p))) == 78 ) {
					goto _ctr104;
				}
				goto _ctr2;
			}
			case 40:
			if ( p == eof ) {
				goto _ctr105;	goto _again;
			}
			else {
				if ( ( (*( p))) == 71 ) {
					goto _ctr106;
				}
				goto _ctr2;
			}
			case 41:
			if ( p == eof ) {
				goto _ctr107;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 10: {
						goto _ctr109;
					}
					case 13: {
						goto _ctr110;
					}
				}
				goto _ctr108;
			}
			case 42:
			if ( p == eof ) {
				goto _ctr111;	goto _again;
			}
			else {
				if ( ( (*( p))) == 10 ) {
					goto _ctr109;
				}
				goto _ctr25;
			}
			case 43:
			if ( p == eof ) {
				goto _ctr112;	goto _again;
			}
			else {
				if ( ( (*( p))) == 82 ) {
					goto _ctr113;
				}
				goto _ctr2;
			}
			case 44:
			if ( p == eof ) {
				goto _ctr114;	goto _again;
			}
			else {
				if ( ( (*( p))) == 69 ) {
					goto _ctr115;
				}
				goto _ctr2;
			}
			case 45:
			if ( p == eof ) {
				goto _ctr116;	goto _again;
			}
			else {
				if ( ( (*( p))) == 83 ) {
					goto _ctr117;
				}
				goto _ctr2;
			}
			case 46:
			if ( p == eof ) {
				goto _ctr118;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 9: {
						goto _ctr119;
					}
					case 32: {
						goto _ctr119;
					}
				}
				if ( 11 <= ( (*( p))) && ( (*( p))) <= 12 ) {
					goto _ctr119;
				}
				goto _ctr13;
			}
			case 47:
			if ( p == eof ) {
				goto _ctr120;	goto _again;
			}
			else {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto _ctr121;
				}
				goto _ctr16;
			}
			case 48:
			if ( p == eof ) {
				goto _ctr122;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 9: {
						goto _ctr123;
					}
					case 32: {
						goto _ctr123;
					}
				}
				if ( ( (*( p))) > 12 ) {
					if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
						goto _ctr124;
					}
				} else if ( ( (*( p))) >= 11 ) {
					goto _ctr123;
				}
				goto _ctr41;
			}
			case 49:
			if ( p == eof ) {
				goto _ctr125;	goto _again;
			}
			else {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto _ctr126;
				}
				goto _ctr16;
			}
			case 50:
			if ( p == eof ) {
				goto _ctr127;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 10: {
						goto _ctr128;
					}
					case 13: {
						goto _ctr129;
					}
				}
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto _ctr130;
				}
				goto _ctr19;
			}
			case 51:
			if ( p == eof ) {
				goto _ctr131;	goto _again;
			}
			else {
				if ( ( (*( p))) == 10 ) {
					goto _ctr128;
				}
				goto _ctr25;
			}
			case 52:
			if ( p == eof ) {
				goto _ctr132;	goto _again;
			}
			else {
				switch( ( (*( p))) ) {
					case 10: {
						goto _ctr133;
					}
					case 13: {
						goto _ctr134;
					}
				}
				goto _ctr132;
			}
			case 55:
			if ( p == eof ) {
				goto _ctr140;	goto _again;
			}
			else {
				goto _ctr0;
			}
			case 53:
			if ( p == eof ) {
				goto _ctr134;	goto _again;
			}
			else {
				if ( ( (*( p))) == 10 ) {
					goto _ctr133;
				}
				goto _ctr0;
			}
		}
		
		_ctr0: cs = 0; goto _again;
		_ctr2: cs = 0; goto f0;
		_ctr13: cs = 0; goto f1;
		_ctr16: cs = 0; goto f2;
		_ctr19: cs = 0; goto f4;
		_ctr25: cs = 0; goto f8;
		_ctr41: cs = 0; goto f10;
		_ctr47: cs = 0; goto f12;
		_ctr50: cs = 0; goto f14;
		_ctr53: cs = 0; goto f16;
		_ctr108: cs = 0; goto f24;
		_ctr136: cs = 1; goto _again;
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
		_ctr23: cs = 7; goto f7;
		_ctr26: cs = 8; goto _again;
		_ctr20: cs = 8; goto f5;
		_ctr24: cs = 8; goto f8;
		_ctr28: cs = 9; goto _again;
		_ctr22: cs = 9; goto f5;
		_ctr29: cs = 9; goto f8;
		_ctr4: cs = 10; goto _again;
		_ctr30: cs = 10; goto f0;
		_ctr31: cs = 11; goto _again;
		_ctr32: cs = 11; goto f0;
		_ctr33: cs = 12; goto _again;
		_ctr34: cs = 12; goto f0;
		_ctr35: cs = 13; goto _again;
		_ctr36: cs = 13; goto f1;
		_ctr37: cs = 14; goto _again;
		_ctr38: cs = 14; goto f2;
		_ctr39: cs = 15; goto f3;
		_ctr43: cs = 15; goto f7;
		_ctr40: cs = 15; goto f10;
		_ctr46: cs = 16; goto _again;
		_ctr42: cs = 16; goto f11;
		_ctr44: cs = 16; goto f12;
		_ctr45: cs = 17; goto f13;
		_ctr48: cs = 17; goto f14;
		_ctr49: cs = 18; goto f15;
		_ctr51: cs = 18; goto f16;
		_ctr52: cs = 19; goto f13;
		_ctr54: cs = 19; goto f16;
		_ctr5: cs = 20; goto _again;
		_ctr56: cs = 20; goto f0;
		_ctr57: cs = 21; goto _again;
		_ctr58: cs = 21; goto f0;
		_ctr59: cs = 22; goto _again;
		_ctr60: cs = 22; goto f0;
		_ctr61: cs = 23; goto _again;
		_ctr62: cs = 23; goto f0;
		_ctr63: cs = 24; goto _again;
		_ctr64: cs = 24; goto f2;
		_ctr65: cs = 25; goto f3;
		_ctr66: cs = 25; goto f4;
		_ctr70: cs = 25; goto f7;
		_ctr72: cs = 26; goto _again;
		_ctr67: cs = 26; goto f5;
		_ctr71: cs = 26; goto f8;
		_ctr74: cs = 27; goto _again;
		_ctr69: cs = 27; goto f5;
		_ctr75: cs = 27; goto f8;
		_ctr137: cs = 28; goto _again;
		_ctr76: cs = 28; goto f0;
		_ctr77: cs = 29; goto _again;
		_ctr78: cs = 29; goto f0;
		_ctr79: cs = 30; goto _again;
		_ctr80: cs = 30; goto f0;
		_ctr81: cs = 31; goto _again;
		_ctr82: cs = 31; goto f1;
		_ctr84: cs = 32; goto f2;
		_ctr83: cs = 32; goto f20;
		_ctr85: cs = 33; goto f3;
		_ctr88: cs = 33; goto f7;
		_ctr86: cs = 33; goto f10;
		_ctr89: cs = 34; goto f2;
		_ctr87: cs = 34; goto f5;
		_ctr93: cs = 35; goto f7;
		_ctr91: cs = 35; goto f10;
		_ctr90: cs = 35; goto f21;
		_ctr94: cs = 36; goto f8;
		_ctr92: cs = 36; goto f22;
		_ctr99: cs = 37; goto f8;
		_ctr138: cs = 38; goto _again;
		_ctr101: cs = 38; goto f0;
		_ctr102: cs = 39; goto _again;
		_ctr103: cs = 39; goto f0;
		_ctr104: cs = 40; goto _again;
		_ctr105: cs = 40; goto f0;
		_ctr106: cs = 41; goto _again;
		_ctr107: cs = 41; goto f24;
		_ctr110: cs = 42; goto _again;
		_ctr111: cs = 42; goto f8;
		_ctr139: cs = 43; goto _again;
		_ctr112: cs = 43; goto f0;
		_ctr113: cs = 44; goto _again;
		_ctr114: cs = 44; goto f0;
		_ctr115: cs = 45; goto _again;
		_ctr116: cs = 45; goto f0;
		_ctr117: cs = 46; goto _again;
		_ctr118: cs = 46; goto f1;
		_ctr119: cs = 47; goto _again;
		_ctr120: cs = 47; goto f2;
		_ctr121: cs = 48; goto f3;
		_ctr124: cs = 48; goto f7;
		_ctr122: cs = 48; goto f10;
		_ctr125: cs = 49; goto f2;
		_ctr123: cs = 49; goto f5;
		_ctr126: cs = 50; goto f3;
		_ctr127: cs = 50; goto f4;
		_ctr130: cs = 50; goto f7;
		_ctr129: cs = 51; goto _again;
		_ctr131: cs = 51; goto f8;
		_ctr132: cs = 52; goto _again;
		_ctr134: cs = 53; goto _again;
		_ctr135: cs = 54; goto _again;
		_ctr21: cs = 54; goto f6;
		_ctr27: cs = 54; goto f9;
		_ctr55: cs = 54; goto f17;
		_ctr68: cs = 54; goto f18;
		_ctr73: cs = 54; goto f19;
		_ctr100: cs = 54; goto f23;
		_ctr109: cs = 54; goto f25;
		_ctr128: cs = 54; goto f26;
		_ctr140: cs = 55; goto _again;
		_ctr133: cs = 55; goto f27;
		_ctr95: cs = 0; goto f8;
		_ctr96: cs = 36; goto f13;
		_ctr98: cs = 37; goto _again;
		_ctr97: cs = 54; goto f23;
		
		f3:
		{
#line 4 "/home/rich/qa/ltp-executor/parser-common.rl"
			n = (( (*( p)))) - '0'; }
		
#line 1046 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f7:
		{
#line 5 "/home/rich/qa/ltp-executor/parser-common.rl"
			n = n * 10 + ((( (*( p)))) - '0'); }
		
#line 1053 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f13:
		{
#line 7 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			n++;
			actor_assert(n < buf_len, "%zu >= %zu", n, buf_len);
			*(buf++) = (( (*( p))));
		}
		
#line 1064 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f5:
		{
#line 13 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			/* TODO: Validate ID */
			id = id_to_addr(n);
		}
		
#line 1074 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f15:
		{
#line 28 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			*buf = '\0';
			buf_len = sizeof(cmds->cmds);
			buf = cmds->cmds;
		}
		
#line 1085 "/home/rich/qa/ltp-executor/driver-parser.c"
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
		
#line 1101 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f19:
		{
#line 45 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			msg = msg_alloc();
			msg->type = MSG_EXEC;
			
			actor_say(self, id, msg);
		}
		
#line 1113 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f8:
		{
#line 52 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected new line");
			{cs = 52; goto _again;}}
		
#line 1122 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f2:
		{
#line 62 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected digit");
			{cs = 52; goto _again;}}
		
#line 1131 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f12:
		{
#line 67 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected symbol character");
			{cs = 52; goto _again;}}
		
#line 1140 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f27:
		{
#line 77 "/home/rich/qa/ltp-executor/parser-common.rl"
			{cs = 54; goto _again;}}
		
#line 1147 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f0:
		{
#line 31 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			DBG("Expected pong, +allc, +cmds, +exec, logd or tres.\nBuffer Dump: ");
			fwrite(str, 1, len, stderr);
			{cs = 52; goto _again;}}
		
#line 1157 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f25:
		{
#line 37 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			msg = msg_alloc();
			msg->type = MSG_PONG;
			actor_say(self, ADDR_WRITER, msg);
			msg = NULL;
		}
		
#line 1169 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f9:
		{
#line 44 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			msg = msg_alloc();
			msg->type = MSG_ALLC;
			actor_say(self, id, msg);
			msg = NULL;
		}
		
#line 1181 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f20:
		{
#line 51 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			msg = msg_alloc_extra(sizeof(*log));
			msg->type = MSG_LOGD;
			log = msg->ptr;
		}
		
#line 1192 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f22:
		{
#line 62 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			log->len = n;
			n = 0;
		}
		
#line 1202 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f23:
		{
#line 67 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			*buf = '\0';
			assert(msg);
			actor_say(self, id, msg);
			msg = NULL;
		}
		
#line 1214 "/home/rich/qa/ltp-executor/driver-parser.c"
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
		
#line 1227 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f11:
		{
#line 13 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			/* TODO: Validate ID */
			id = id_to_addr(n);
		}
		
#line 1237 "/home/rich/qa/ltp-executor/driver-parser.c"
		{
#line 18 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			cmds = malloc(sizeof(*cmds));
			
			assert_perror(errno);
			assert(cmds);
			
			buf_len = sizeof(cmds->tid);
			buf = cmds->tid;
		}
		
#line 1250 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f18:
		{
#line 13 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			/* TODO: Validate ID */
			id = id_to_addr(n);
		}
		
#line 1260 "/home/rich/qa/ltp-executor/driver-parser.c"
		{
#line 45 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			msg = msg_alloc();
			msg->type = MSG_EXEC;
			
			actor_say(self, id, msg);
		}
		
#line 1270 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f6:
		{
#line 13 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			/* TODO: Validate ID */
			id = id_to_addr(n);
		}
		
#line 1280 "/home/rich/qa/ltp-executor/driver-parser.c"
		{
#line 44 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			msg = msg_alloc();
			msg->type = MSG_ALLC;
			actor_say(self, id, msg);
			msg = NULL;
		}
		
#line 1290 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f16:
		{
#line 52 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected new line");
			{cs = 52; goto _again;}}
		
#line 1299 "/home/rich/qa/ltp-executor/driver-parser.c"
		{
#line 72 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected string character");
			{cs = 52; goto _again;}}
		
#line 1306 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f4:
		{
#line 62 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected digit");
			{cs = 52; goto _again;}}
		
#line 1315 "/home/rich/qa/ltp-executor/driver-parser.c"
		{
#line 52 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected new line");
			{cs = 52; goto _again;}}
		
#line 1322 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f10:
		{
#line 62 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected digit");
			{cs = 52; goto _again;}}
		
#line 1331 "/home/rich/qa/ltp-executor/driver-parser.c"
		{
#line 57 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected white space");
			{cs = 52; goto _again;}}
		
#line 1338 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f14:
		{
#line 67 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected symbol character");
			{cs = 52; goto _again;}}
		
#line 1347 "/home/rich/qa/ltp-executor/driver-parser.c"
		{
#line 57 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected white space");
			{cs = 52; goto _again;}}
		
#line 1354 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f24:
		{
#line 31 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			DBG("Expected pong, +allc, +cmds, +exec, logd or tres.\nBuffer Dump: ");
			fwrite(str, 1, len, stderr);
			{cs = 52; goto _again;}}
		
#line 1364 "/home/rich/qa/ltp-executor/driver-parser.c"
		{
#line 52 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected new line");
			{cs = 52; goto _again;}}
		
#line 1371 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f1:
		{
#line 31 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			DBG("Expected pong, +allc, +cmds, +exec, logd or tres.\nBuffer Dump: ");
			fwrite(str, 1, len, stderr);
			{cs = 52; goto _again;}}
		
#line 1381 "/home/rich/qa/ltp-executor/driver-parser.c"
		{
#line 57 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected white space");
			{cs = 52; goto _again;}}
		
#line 1388 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		f21:
		{
#line 57 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			buf = log->buf;
			buf_len = LEN_1024;
		}
		
#line 1398 "/home/rich/qa/ltp-executor/driver-parser.c"
		{
#line 4 "/home/rich/qa/ltp-executor/parser-common.rl"
			n = (( (*( p)))) - '0'; }
		
#line 1403 "/home/rich/qa/ltp-executor/driver-parser.c"
		goto _again;
		
		_again: {}
		if ( p == eof ) {
			if ( cs >= 54 )
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

#line 1 "/home/rich/qa/ltp-executor/driver-parser.rl"
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

#line 26 "/home/rich/qa/ltp-executor/driver-parser.c"
static const int parse_start = 47;

static const int parse_en_main = 47;


#line 94 "/home/rich/qa/ltp-executor/driver-parser.rl"


static int cs;
static addr_t id;
static size_t n, buf_len;
static char *buf;
static struct cmds *cmds;
static struct log *log;
struct msg *msg;

void parser_init(void)
{
	
#line 46 "/home/rich/qa/ltp-executor/driver-parser.c"
	{
		cs = (int)parse_start;
	}
	
#line 108 "/home/rich/qa/ltp-executor/driver-parser.rl"
	
}

void parser_feed(struct actor *self, char *str, size_t len)
{
	char *p = str, *pe = str + len;
	char *eof = NULL;
	
	
#line 61 "/home/rich/qa/ltp-executor/driver-parser.c"
	{
		int _ck;
		if ( p == pe )
			goto _test_eof;
		switch ( cs ) {
			case 47:
			goto st_case_47;
			case 0:
			goto st_case_0;
			case 1:
			goto st_case_1;
			case 2:
			goto st_case_2;
			case 3:
			goto st_case_3;
			case 4:
			goto st_case_4;
			case 5:
			goto st_case_5;
			case 6:
			goto st_case_6;
			case 7:
			goto st_case_7;
			case 8:
			goto st_case_8;
			case 9:
			goto st_case_9;
			case 10:
			goto st_case_10;
			case 11:
			goto st_case_11;
			case 12:
			goto st_case_12;
			case 13:
			goto st_case_13;
			case 14:
			goto st_case_14;
			case 15:
			goto st_case_15;
			case 16:
			goto st_case_16;
			case 17:
			goto st_case_17;
			case 18:
			goto st_case_18;
			case 19:
			goto st_case_19;
			case 20:
			goto st_case_20;
			case 21:
			goto st_case_21;
			case 22:
			goto st_case_22;
			case 23:
			goto st_case_23;
			case 24:
			goto st_case_24;
			case 25:
			goto st_case_25;
			case 26:
			goto st_case_26;
			case 27:
			goto st_case_27;
			case 28:
			goto st_case_28;
			case 29:
			goto st_case_29;
			case 30:
			goto st_case_30;
			case 31:
			goto st_case_31;
			case 32:
			goto st_case_32;
			case 33:
			goto st_case_33;
			case 34:
			goto st_case_34;
			case 35:
			goto st_case_35;
			case 36:
			goto st_case_36;
			case 37:
			goto st_case_37;
			case 38:
			goto st_case_38;
			case 39:
			goto st_case_39;
			case 40:
			goto st_case_40;
			case 41:
			goto st_case_41;
			case 42:
			goto st_case_42;
			case 43:
			goto st_case_43;
			case 44:
			goto st_case_44;
			case 45:
			goto st_case_45;
			case 46:
			goto st_case_46;
		}
		goto st_out;
		_ctr91:
		{
#line 63 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			*buf = '\0';
			assert(msg);
			actor_say(self, id, msg);
			msg = NULL;
		}
		
#line 175 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st47;
		_ctr21:
		{
#line 13 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			/* TODO: Validate ID */
			id = id_to_addr(n);
		}
		
#line 186 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		{
#line 40 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			msg = msg_alloc();
			msg->type = MSG_ALLC;
			actor_say(self, id, msg);
			msg = NULL;
		}
		
#line 197 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st47;
		_ctr26:
		{
#line 40 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			msg = msg_alloc();
			msg->type = MSG_ALLC;
			actor_say(self, id, msg);
			msg = NULL;
		}
		
#line 210 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st47;
		_ctr52:
		{
#line 33 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			*buf = '\0';
			buf = NULL;
			
			msg = msg_alloc();
			msg->type = MSG_CMDS;
			msg->ptr = cmds;
			
			actor_say(self, id, msg);
		}
		
#line 227 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st47;
		_ctr65:
		{
#line 13 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			/* TODO: Validate ID */
			id = id_to_addr(n);
		}
		
#line 238 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		{
#line 44 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			msg = msg_alloc();
			msg->type = MSG_EXEC;
			
			actor_say(self, id, msg);
		}
		
#line 249 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st47;
		_ctr69:
		{
#line 44 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			msg = msg_alloc();
			msg->type = MSG_EXEC;
			
			actor_say(self, id, msg);
		}
		
#line 262 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st47;
		_ctr100:
		{
#line 33 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			msg = msg_alloc();
			msg->type = MSG_PONG;
			actor_say(self, ADDR_WRITER, msg);
			msg = NULL;
		}
		
#line 275 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st47;
		_ctr117:
		{
#line 70 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			msg = msg_alloc();
			msg->type = MSG_TRES;
			msg->val = n;
			actor_say(self, id, msg);
			msg = NULL;
		}
		
#line 289 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st47;
		_st47:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof47;
		st_case_47:
		switch( ( (*( p))) ) {
			case 43: {
				goto _st1;
			}
			case 76: {
				goto _st26;
			}
			case 80: {
				goto _st35;
			}
			case 84: {
				goto _st39;
			}
		}
		{
			goto _ctr2;
		}
		_ctr89:
		{
#line 51 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected new line");
			{goto _st47;}}
		
#line 327 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st0;
		_ctr2:
		{
#line 28 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			DBG("Epected pong, +allc, +cmds, +exec, logd or tres.\nBuffer Dump: ");
			fwrite(str, 1, len, stderr);
		}
		
#line 338 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st0;
		_ctr13:
		{
#line 28 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			DBG("Epected pong, +allc, +cmds, +exec, logd or tres.\nBuffer Dump: ");
			fwrite(str, 1, len, stderr);
		}
		
#line 349 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		{
#line 56 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected white space");
			{goto _st47;}}
		
#line 357 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st0;
		_ctr16:
		{
#line 61 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected digit");
			{goto _st47;}}
		
#line 367 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st0;
		_ctr19:
		{
#line 61 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected digit");
			{goto _st47;}}
		
#line 377 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		{
#line 51 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected new line");
			{goto _st47;}}
		
#line 385 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st0;
		_ctr24:
		{
#line 51 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected new line");
			{goto _st47;}}
		
#line 395 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st0;
		_ctr38:
		{
#line 61 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected digit");
			{goto _st47;}}
		
#line 405 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		{
#line 56 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected white space");
			{goto _st47;}}
		
#line 413 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st0;
		_ctr44:
		{
#line 66 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected symbol character");
			{goto _st47;}}
		
#line 423 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st0;
		_ctr47:
		{
#line 66 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected symbol character");
			{goto _st47;}}
		
#line 433 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		{
#line 56 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected white space");
			{goto _st47;}}
		
#line 441 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st0;
		_ctr50:
		{
#line 51 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected new line");
			{goto _st47;}}
		
#line 451 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		{
#line 71 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected string character");
			{goto _st47;}}
		
#line 459 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st0;
		_ctr99:
		{
#line 28 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			DBG("Epected pong, +allc, +cmds, +exec, logd or tres.\nBuffer Dump: ");
			fwrite(str, 1, len, stderr);
		}
		
#line 470 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		{
#line 51 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected new line");
			{goto _st47;}}
		
#line 478 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st0;
		st_case_0:
		_st0:
		cs = 0;
		goto _pop;
		_ctr1:
		{
#line 28 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			DBG("Epected pong, +allc, +cmds, +exec, logd or tres.\nBuffer Dump: ");
			fwrite(str, 1, len, stderr);
		}
		
#line 493 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st1;
		_st1:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof1;
		st_case_1:
		switch( ( (*( p))) ) {
			case 65: {
				goto _st2;
			}
			case 67: {
				goto _st9;
			}
			case 69: {
				goto _st19;
			}
		}
		{
			goto _ctr2;
		}
		_ctr6:
		{
#line 28 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			DBG("Epected pong, +allc, +cmds, +exec, logd or tres.\nBuffer Dump: ");
			fwrite(str, 1, len, stderr);
		}
		
#line 529 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st2;
		_st2:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof2;
		st_case_2:
		if ( ( (*( p))) == 76 ) {
			goto _st3;
		}
		{
			goto _ctr2;
		}
		_ctr8:
		{
#line 28 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			DBG("Epected pong, +allc, +cmds, +exec, logd or tres.\nBuffer Dump: ");
			fwrite(str, 1, len, stderr);
		}
		
#line 557 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st3;
		_st3:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof3;
		st_case_3:
		if ( ( (*( p))) == 76 ) {
			goto _st4;
		}
		{
			goto _ctr2;
		}
		_ctr10:
		{
#line 28 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			DBG("Epected pong, +allc, +cmds, +exec, logd or tres.\nBuffer Dump: ");
			fwrite(str, 1, len, stderr);
		}
		
#line 585 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st4;
		_st4:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof4;
		st_case_4:
		if ( ( (*( p))) == 67 ) {
			goto _st5;
		}
		{
			goto _ctr2;
		}
		_ctr12:
		{
#line 28 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			DBG("Epected pong, +allc, +cmds, +exec, logd or tres.\nBuffer Dump: ");
			fwrite(str, 1, len, stderr);
		}
		
#line 613 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		{
#line 56 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected white space");
			{goto _st47;}}
		
#line 621 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st5;
		_st5:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof5;
		st_case_5:
		switch( ( (*( p))) ) {
			case 9: {
				goto _st6;
			}
			case 32: {
				goto _st6;
			}
		}
		if ( 11 <= ( (*( p))) && ( (*( p))) <= 12 ) {
			goto _st6;
		}
		{
			goto _ctr13;
		}
		_ctr15:
		{
#line 61 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected digit");
			{goto _st47;}}
		
#line 656 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st6;
		_st6:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof6;
		st_case_6:
		switch( ( (*( p))) ) {
			case 9: {
				goto _st6;
			}
			case 32: {
				goto _st6;
			}
		}
		if ( ( (*( p))) > 12 ) {
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto _ctr17;
			}
		} else if ( ( (*( p))) >= 11 ) {
			goto _st6;
		}
		{
			goto _ctr16;
		}
		_ctr17:
		{
#line 4 "/home/rich/qa/ltp-executor/parser-common.rl"
			n = (( (*( p)))) - '0'; }
		
#line 693 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st7;
		_ctr18:
		{
#line 61 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected digit");
			{goto _st47;}}
		
#line 703 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		{
#line 51 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected new line");
			{goto _st47;}}
		
#line 711 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st7;
		_ctr22:
		{
#line 5 "/home/rich/qa/ltp-executor/parser-common.rl"
			n = n * 10 + ((( (*( p)))) - '0'); }
		
#line 719 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st7;
		_st7:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof7;
		st_case_7:
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
		{
			goto _ctr19;
		}
		_ctr20:
		{
#line 13 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			/* TODO: Validate ID */
			id = id_to_addr(n);
		}
		
#line 759 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st8;
		_ctr23:
		{
#line 51 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected new line");
			{goto _st47;}}
		
#line 769 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st8;
		_st8:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof8;
		st_case_8:
		switch( ( (*( p))) ) {
			case 10: {
				goto _ctr26;
			}
			case 32: {
				goto _st8;
			}
		}
		if ( 9 <= ( (*( p))) && ( (*( p))) <= 12 ) {
			goto _st8;
		}
		{
			goto _ctr24;
		}
		_ctr27:
		{
#line 28 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			DBG("Epected pong, +allc, +cmds, +exec, logd or tres.\nBuffer Dump: ");
			fwrite(str, 1, len, stderr);
		}
		
#line 805 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st9;
		_st9:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof9;
		st_case_9:
		if ( ( (*( p))) == 77 ) {
			goto _st10;
		}
		{
			goto _ctr2;
		}
		_ctr29:
		{
#line 28 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			DBG("Epected pong, +allc, +cmds, +exec, logd or tres.\nBuffer Dump: ");
			fwrite(str, 1, len, stderr);
		}
		
#line 833 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st10;
		_st10:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof10;
		st_case_10:
		if ( ( (*( p))) == 68 ) {
			goto _st11;
		}
		{
			goto _ctr2;
		}
		_ctr31:
		{
#line 28 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			DBG("Epected pong, +allc, +cmds, +exec, logd or tres.\nBuffer Dump: ");
			fwrite(str, 1, len, stderr);
		}
		
#line 861 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st11;
		_st11:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof11;
		st_case_11:
		if ( ( (*( p))) == 83 ) {
			goto _st12;
		}
		{
			goto _ctr2;
		}
		_ctr33:
		{
#line 28 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			DBG("Epected pong, +allc, +cmds, +exec, logd or tres.\nBuffer Dump: ");
			fwrite(str, 1, len, stderr);
		}
		
#line 889 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		{
#line 56 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected white space");
			{goto _st47;}}
		
#line 897 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st12;
		_st12:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof12;
		st_case_12:
		switch( ( (*( p))) ) {
			case 9: {
				goto _st13;
			}
			case 32: {
				goto _st13;
			}
		}
		if ( 11 <= ( (*( p))) && ( (*( p))) <= 12 ) {
			goto _st13;
		}
		{
			goto _ctr13;
		}
		_ctr35:
		{
#line 61 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected digit");
			{goto _st47;}}
		
#line 932 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st13;
		_st13:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof13;
		st_case_13:
		switch( ( (*( p))) ) {
			case 9: {
				goto _st13;
			}
			case 32: {
				goto _st13;
			}
		}
		if ( ( (*( p))) > 12 ) {
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto _ctr36;
			}
		} else if ( ( (*( p))) >= 11 ) {
			goto _st13;
		}
		{
			goto _ctr16;
		}
		_ctr36:
		{
#line 4 "/home/rich/qa/ltp-executor/parser-common.rl"
			n = (( (*( p)))) - '0'; }
		
#line 969 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st14;
		_ctr40:
		{
#line 5 "/home/rich/qa/ltp-executor/parser-common.rl"
			n = n * 10 + ((( (*( p)))) - '0'); }
		
#line 977 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st14;
		_ctr37:
		{
#line 61 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected digit");
			{goto _st47;}}
		
#line 987 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		{
#line 56 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected white space");
			{goto _st47;}}
		
#line 995 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st14;
		_st14:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof14;
		st_case_14:
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
		{
			goto _ctr38;
		}
		_ctr39:
		{
#line 13 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			/* TODO: Validate ID */
			id = id_to_addr(n);
		}
		
#line 1035 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		{
#line 18 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			cmds = malloc(sizeof(*cmds));
			
			assert_perror(errno);
			assert(cmds);
			
			buf_len = sizeof(cmds->tid);
			buf = cmds->tid;
		}
		
#line 1049 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st15;
		_ctr41:
		{
#line 66 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected symbol character");
			{goto _st47;}}
		
#line 1059 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st15;
		_st15:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof15;
		st_case_15:
		switch( ( (*( p))) ) {
			case 10: {
				goto _ctr44;
			}
			case 13: {
				goto _ctr44;
			}
			case 32: {
				goto _st15;
			}
		}
		if ( 9 <= ( (*( p))) && ( (*( p))) <= 12 ) {
			goto _st15;
		}
		{
			goto _ctr42;
		}
		_ctr42:
		{
#line 7 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			n++;
			actor_assert(n < buf_len - 1, "%zu >= %zu", n, buf_len);
			*(buf++) = (( (*( p))));
		}
		
#line 1099 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st16;
		_ctr45:
		{
#line 66 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected symbol character");
			{goto _st47;}}
		
#line 1109 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		{
#line 56 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected white space");
			{goto _st47;}}
		
#line 1117 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st16;
		_st16:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof16;
		st_case_16:
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
		{
			goto _ctr42;
		}
		_ctr46:
		{
#line 28 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			*buf = '\0';
			buf = cmds->cmds;
		}
		
#line 1156 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st17;
		_ctr48:
		{
#line 51 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected new line");
			{goto _st47;}}
		
#line 1166 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		{
#line 71 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected string character");
			{goto _st47;}}
		
#line 1174 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st17;
		_st17:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof17;
		st_case_17:
		if ( ( (*( p))) == 10 ) {
			goto _ctr50;
		}
		{
			goto _ctr49;
		}
		_ctr49:
		{
#line 7 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			n++;
			actor_assert(n < buf_len - 1, "%zu >= %zu", n, buf_len);
			*(buf++) = (( (*( p))));
		}
		
#line 1203 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st18;
		_ctr51:
		{
#line 51 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected new line");
			{goto _st47;}}
		
#line 1213 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		{
#line 71 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected string character");
			{goto _st47;}}
		
#line 1221 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st18;
		_st18:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof18;
		st_case_18:
		if ( ( (*( p))) == 10 ) {
			goto _ctr52;
		}
		{
			goto _ctr49;
		}
		_ctr53:
		{
#line 28 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			DBG("Epected pong, +allc, +cmds, +exec, logd or tres.\nBuffer Dump: ");
			fwrite(str, 1, len, stderr);
		}
		
#line 1249 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st19;
		_st19:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof19;
		st_case_19:
		if ( ( (*( p))) == 88 ) {
			goto _st20;
		}
		{
			goto _ctr2;
		}
		_ctr55:
		{
#line 28 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			DBG("Epected pong, +allc, +cmds, +exec, logd or tres.\nBuffer Dump: ");
			fwrite(str, 1, len, stderr);
		}
		
#line 1277 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st20;
		_st20:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof20;
		st_case_20:
		if ( ( (*( p))) == 69 ) {
			goto _st21;
		}
		{
			goto _ctr2;
		}
		_ctr57:
		{
#line 28 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			DBG("Epected pong, +allc, +cmds, +exec, logd or tres.\nBuffer Dump: ");
			fwrite(str, 1, len, stderr);
		}
		
#line 1305 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st21;
		_st21:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof21;
		st_case_21:
		if ( ( (*( p))) == 67 ) {
			goto _st22;
		}
		{
			goto _ctr2;
		}
		_ctr59:
		{
#line 28 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			DBG("Epected pong, +allc, +cmds, +exec, logd or tres.\nBuffer Dump: ");
			fwrite(str, 1, len, stderr);
		}
		
#line 1333 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st22;
		_st22:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof22;
		st_case_22:
		switch( ( (*( p))) ) {
			case 9: {
				goto _st23;
			}
			case 32: {
				goto _st23;
			}
		}
		if ( 11 <= ( (*( p))) && ( (*( p))) <= 12 ) {
			goto _st23;
		}
		{
			goto _ctr2;
		}
		_ctr61:
		{
#line 61 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected digit");
			{goto _st47;}}
		
#line 1368 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st23;
		_st23:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof23;
		st_case_23:
		switch( ( (*( p))) ) {
			case 9: {
				goto _st23;
			}
			case 32: {
				goto _st23;
			}
		}
		if ( ( (*( p))) > 12 ) {
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto _ctr62;
			}
		} else if ( ( (*( p))) >= 11 ) {
			goto _st23;
		}
		{
			goto _ctr16;
		}
		_ctr62:
		{
#line 4 "/home/rich/qa/ltp-executor/parser-common.rl"
			n = (( (*( p)))) - '0'; }
		
#line 1405 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st24;
		_ctr63:
		{
#line 61 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected digit");
			{goto _st47;}}
		
#line 1415 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		{
#line 51 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected new line");
			{goto _st47;}}
		
#line 1423 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st24;
		_ctr66:
		{
#line 5 "/home/rich/qa/ltp-executor/parser-common.rl"
			n = n * 10 + ((( (*( p)))) - '0'); }
		
#line 1431 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st24;
		_st24:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof24;
		st_case_24:
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
		{
			goto _ctr19;
		}
		_ctr64:
		{
#line 13 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			/* TODO: Validate ID */
			id = id_to_addr(n);
		}
		
#line 1471 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st25;
		_ctr67:
		{
#line 51 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected new line");
			{goto _st47;}}
		
#line 1481 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st25;
		_st25:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof25;
		st_case_25:
		switch( ( (*( p))) ) {
			case 10: {
				goto _ctr69;
			}
			case 32: {
				goto _st25;
			}
		}
		if ( 9 <= ( (*( p))) && ( (*( p))) <= 12 ) {
			goto _st25;
		}
		{
			goto _ctr24;
		}
		_ctr70:
		{
#line 28 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			DBG("Epected pong, +allc, +cmds, +exec, logd or tres.\nBuffer Dump: ");
			fwrite(str, 1, len, stderr);
		}
		
#line 1517 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st26;
		_st26:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof26;
		st_case_26:
		if ( ( (*( p))) == 79 ) {
			goto _st27;
		}
		{
			goto _ctr2;
		}
		_ctr72:
		{
#line 28 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			DBG("Epected pong, +allc, +cmds, +exec, logd or tres.\nBuffer Dump: ");
			fwrite(str, 1, len, stderr);
		}
		
#line 1545 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st27;
		_st27:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof27;
		st_case_27:
		if ( ( (*( p))) == 71 ) {
			goto _st28;
		}
		{
			goto _ctr2;
		}
		_ctr74:
		{
#line 28 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			DBG("Epected pong, +allc, +cmds, +exec, logd or tres.\nBuffer Dump: ");
			fwrite(str, 1, len, stderr);
		}
		
#line 1573 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st28;
		_st28:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof28;
		st_case_28:
		if ( ( (*( p))) == 68 ) {
			goto _st29;
		}
		{
			goto _ctr2;
		}
		_ctr76:
		{
#line 28 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			DBG("Epected pong, +allc, +cmds, +exec, logd or tres.\nBuffer Dump: ");
			fwrite(str, 1, len, stderr);
		}
		
#line 1601 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		{
#line 56 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected white space");
			{goto _st47;}}
		
#line 1609 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st29;
		_st29:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof29;
		st_case_29:
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
		{
			goto _ctr13;
		}
		_ctr78:
		{
#line 61 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected digit");
			{goto _st47;}}
		
#line 1644 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st30;
		_ctr77:
		{
#line 47 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			msg = msg_alloc_extra(sizeof(*log));
			msg->type = MSG_LOGD;
			log = msg->ptr;
		}
		
#line 1656 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st30;
		_st30:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof30;
		st_case_30:
		if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
			goto _ctr79;
		}
		{
			goto _ctr16;
		}
		_ctr79:
		{
#line 4 "/home/rich/qa/ltp-executor/parser-common.rl"
			n = (( (*( p)))) - '0'; }
		
#line 1681 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st31;
		_ctr82:
		{
#line 5 "/home/rich/qa/ltp-executor/parser-common.rl"
			n = n * 10 + ((( (*( p)))) - '0'); }
		
#line 1689 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st31;
		_ctr80:
		{
#line 61 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected digit");
			{goto _st47;}}
		
#line 1699 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		{
#line 56 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected white space");
			{goto _st47;}}
		
#line 1707 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st31;
		_st31:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof31;
		st_case_31:
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
		{
			goto _ctr38;
		}
		_ctr83:
		{
#line 61 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected digit");
			{goto _st47;}}
		
#line 1746 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st32;
		_ctr81:
		{
#line 13 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			/* TODO: Validate ID */
			id = id_to_addr(n);
		}
		
#line 1757 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st32;
		_st32:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof32;
		st_case_32:
		if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
			goto _ctr84;
		}
		{
			goto _ctr16;
		}
		_ctr87:
		{
#line 5 "/home/rich/qa/ltp-executor/parser-common.rl"
			n = n * 10 + ((( (*( p)))) - '0'); }
		
#line 1782 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st33;
		_ctr85:
		{
#line 61 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected digit");
			{goto _st47;}}
		
#line 1792 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		{
#line 56 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected white space");
			{goto _st47;}}
		
#line 1800 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st33;
		_ctr84:
		{
#line 53 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			buf = log->buf;
			buf_len = LEN_1024;
		}
		
#line 1811 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		{
#line 4 "/home/rich/qa/ltp-executor/parser-common.rl"
			n = (( (*( p)))) - '0'; }
		
#line 1817 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st33;
		_st33:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof33;
		st_case_33:
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
		{
			goto _ctr38;
		}
		_ctr90:
		{
#line 7 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			n++;
			actor_assert(n < buf_len - 1, "%zu >= %zu", n, buf_len);
			*(buf++) = (( (*( p))));
		}
		
#line 1858 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st34;
		_ctr88:
		{
#line 51 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected new line");
			{goto _st47;}}
		
#line 1868 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st34;
		_ctr86:
		{
#line 58 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			log->len = n;
			n = 0;
		}
		
#line 1879 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st34;
		_st34:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof34;
		st_case_34:
		if ( ( (*( p))) == 10 ) {
			_ck = 0;
			if ( ( n < log->len )
#line 1896 "/home/rich/qa/ltp-executor/driver-parser.c"
			)
			_ck += 1;
			if ( _ck > 0 ) {
				goto _ctr90;
			} else {
				goto _ctr91;
			}
			
		}
		{
			_ck = 0;
			if ( ( n < log->len )
#line 1909 "/home/rich/qa/ltp-executor/driver-parser.c"
			)
			_ck += 1;
			if ( _ck > 0 ) {
				goto _ctr90;
			} else {
				goto _ctr89;
			}
			
		}
		_ctr92:
		{
#line 28 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			DBG("Epected pong, +allc, +cmds, +exec, logd or tres.\nBuffer Dump: ");
			fwrite(str, 1, len, stderr);
		}
		
#line 1927 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st35;
		_st35:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof35;
		st_case_35:
		if ( ( (*( p))) == 79 ) {
			goto _st36;
		}
		{
			goto _ctr2;
		}
		_ctr94:
		{
#line 28 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			DBG("Epected pong, +allc, +cmds, +exec, logd or tres.\nBuffer Dump: ");
			fwrite(str, 1, len, stderr);
		}
		
#line 1955 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st36;
		_st36:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof36;
		st_case_36:
		if ( ( (*( p))) == 78 ) {
			goto _st37;
		}
		{
			goto _ctr2;
		}
		_ctr96:
		{
#line 28 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			DBG("Epected pong, +allc, +cmds, +exec, logd or tres.\nBuffer Dump: ");
			fwrite(str, 1, len, stderr);
		}
		
#line 1983 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st37;
		_st37:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof37;
		st_case_37:
		if ( ( (*( p))) == 71 ) {
			goto _st38;
		}
		{
			goto _ctr2;
		}
		_ctr98:
		{
#line 28 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			DBG("Epected pong, +allc, +cmds, +exec, logd or tres.\nBuffer Dump: ");
			fwrite(str, 1, len, stderr);
		}
		
#line 2011 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		{
#line 51 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected new line");
			{goto _st47;}}
		
#line 2019 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st38;
		_st38:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof38;
		st_case_38:
		if ( ( (*( p))) == 10 ) {
			goto _ctr100;
		}
		{
			goto _ctr99;
		}
		_ctr101:
		{
#line 28 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			DBG("Epected pong, +allc, +cmds, +exec, logd or tres.\nBuffer Dump: ");
			fwrite(str, 1, len, stderr);
		}
		
#line 2047 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st39;
		_st39:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof39;
		st_case_39:
		if ( ( (*( p))) == 82 ) {
			goto _st40;
		}
		{
			goto _ctr2;
		}
		_ctr103:
		{
#line 28 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			DBG("Epected pong, +allc, +cmds, +exec, logd or tres.\nBuffer Dump: ");
			fwrite(str, 1, len, stderr);
		}
		
#line 2075 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st40;
		_st40:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof40;
		st_case_40:
		if ( ( (*( p))) == 69 ) {
			goto _st41;
		}
		{
			goto _ctr2;
		}
		_ctr105:
		{
#line 28 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			DBG("Epected pong, +allc, +cmds, +exec, logd or tres.\nBuffer Dump: ");
			fwrite(str, 1, len, stderr);
		}
		
#line 2103 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st41;
		_st41:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof41;
		st_case_41:
		if ( ( (*( p))) == 83 ) {
			goto _st42;
		}
		{
			goto _ctr2;
		}
		_ctr107:
		{
#line 28 "/home/rich/qa/ltp-executor/driver-parser.rl"
			
			DBG("Epected pong, +allc, +cmds, +exec, logd or tres.\nBuffer Dump: ");
			fwrite(str, 1, len, stderr);
		}
		
#line 2131 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		{
#line 56 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected white space");
			{goto _st47;}}
		
#line 2139 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st42;
		_st42:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof42;
		st_case_42:
		switch( ( (*( p))) ) {
			case 9: {
				goto _st43;
			}
			case 32: {
				goto _st43;
			}
		}
		if ( 11 <= ( (*( p))) && ( (*( p))) <= 12 ) {
			goto _st43;
		}
		{
			goto _ctr13;
		}
		_ctr109:
		{
#line 61 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected digit");
			{goto _st47;}}
		
#line 2174 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st43;
		_st43:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof43;
		st_case_43:
		if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
			goto _ctr110;
		}
		{
			goto _ctr16;
		}
		_ctr110:
		{
#line 4 "/home/rich/qa/ltp-executor/parser-common.rl"
			n = (( (*( p)))) - '0'; }
		
#line 2199 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st44;
		_ctr113:
		{
#line 5 "/home/rich/qa/ltp-executor/parser-common.rl"
			n = n * 10 + ((( (*( p)))) - '0'); }
		
#line 2207 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st44;
		_ctr111:
		{
#line 61 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected digit");
			{goto _st47;}}
		
#line 2217 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		{
#line 56 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected white space");
			{goto _st47;}}
		
#line 2225 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st44;
		_st44:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof44;
		st_case_44:
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
		{
			goto _ctr38;
		}
		_ctr114:
		{
#line 61 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected digit");
			{goto _st47;}}
		
#line 2264 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st45;
		_ctr112:
		{
#line 13 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			/* TODO: Validate ID */
			id = id_to_addr(n);
		}
		
#line 2275 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st45;
		_st45:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof45;
		st_case_45:
		if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
			goto _ctr115;
		}
		{
			goto _ctr16;
		}
		_ctr115:
		{
#line 4 "/home/rich/qa/ltp-executor/parser-common.rl"
			n = (( (*( p)))) - '0'; }
		
#line 2300 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st46;
		_ctr116:
		{
#line 61 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected digit");
			{goto _st47;}}
		
#line 2310 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		{
#line 51 "/home/rich/qa/ltp-executor/parser-common.rl"
			
			error_msg(self, "Expected new line");
			{goto _st47;}}
		
#line 2318 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st46;
		_ctr118:
		{
#line 5 "/home/rich/qa/ltp-executor/parser-common.rl"
			n = n * 10 + ((( (*( p)))) - '0'); }
		
#line 2326 "/home/rich/qa/ltp-executor/driver-parser.c"
		
		goto _st46;
		_st46:
		if ( p == eof ) {
			if ( cs >= 47 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof46;
		st_case_46:
		if ( ( (*( p))) == 10 ) {
			goto _ctr117;
		}
		if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
			goto _ctr118;
		}
		{
			goto _ctr19;
		}
		st_out:
		_test_eof47: cs = 47; goto _test_eof; 
		_test_eof1: cs = 1; goto _test_eof; 
		_test_eof2: cs = 2; goto _test_eof; 
		_test_eof3: cs = 3; goto _test_eof; 
		_test_eof4: cs = 4; goto _test_eof; 
		_test_eof5: cs = 5; goto _test_eof; 
		_test_eof6: cs = 6; goto _test_eof; 
		_test_eof7: cs = 7; goto _test_eof; 
		_test_eof8: cs = 8; goto _test_eof; 
		_test_eof9: cs = 9; goto _test_eof; 
		_test_eof10: cs = 10; goto _test_eof; 
		_test_eof11: cs = 11; goto _test_eof; 
		_test_eof12: cs = 12; goto _test_eof; 
		_test_eof13: cs = 13; goto _test_eof; 
		_test_eof14: cs = 14; goto _test_eof; 
		_test_eof15: cs = 15; goto _test_eof; 
		_test_eof16: cs = 16; goto _test_eof; 
		_test_eof17: cs = 17; goto _test_eof; 
		_test_eof18: cs = 18; goto _test_eof; 
		_test_eof19: cs = 19; goto _test_eof; 
		_test_eof20: cs = 20; goto _test_eof; 
		_test_eof21: cs = 21; goto _test_eof; 
		_test_eof22: cs = 22; goto _test_eof; 
		_test_eof23: cs = 23; goto _test_eof; 
		_test_eof24: cs = 24; goto _test_eof; 
		_test_eof25: cs = 25; goto _test_eof; 
		_test_eof26: cs = 26; goto _test_eof; 
		_test_eof27: cs = 27; goto _test_eof; 
		_test_eof28: cs = 28; goto _test_eof; 
		_test_eof29: cs = 29; goto _test_eof; 
		_test_eof30: cs = 30; goto _test_eof; 
		_test_eof31: cs = 31; goto _test_eof; 
		_test_eof32: cs = 32; goto _test_eof; 
		_test_eof33: cs = 33; goto _test_eof; 
		_test_eof34: cs = 34; goto _test_eof; 
		_test_eof35: cs = 35; goto _test_eof; 
		_test_eof36: cs = 36; goto _test_eof; 
		_test_eof37: cs = 37; goto _test_eof; 
		_test_eof38: cs = 38; goto _test_eof; 
		_test_eof39: cs = 39; goto _test_eof; 
		_test_eof40: cs = 40; goto _test_eof; 
		_test_eof41: cs = 41; goto _test_eof; 
		_test_eof42: cs = 42; goto _test_eof; 
		_test_eof43: cs = 43; goto _test_eof; 
		_test_eof44: cs = 44; goto _test_eof; 
		_test_eof45: cs = 45; goto _test_eof; 
		_test_eof46: cs = 46; goto _test_eof; 
		
		_test_eof: {}
		if ( p == eof ) {
			switch ( cs ) {
				case 47: {
					break;
				}
				case 0: {
					break;
				}
				case 1: {
					break;
				}
				case 2: {
					break;
				}
				case 3: {
					break;
				}
				case 4: {
					break;
				}
				case 5: {
					break;
				}
				case 6: {
					break;
				}
				case 7: {
					break;
				}
				case 8: {
					break;
				}
				case 9: {
					break;
				}
				case 10: {
					break;
				}
				case 11: {
					break;
				}
				case 12: {
					break;
				}
				case 13: {
					break;
				}
				case 14: {
					break;
				}
				case 15: {
					break;
				}
				case 16: {
					break;
				}
				case 17: {
					break;
				}
				case 18: {
					break;
				}
				case 19: {
					break;
				}
				case 20: {
					break;
				}
				case 21: {
					break;
				}
				case 22: {
					break;
				}
				case 23: {
					break;
				}
				case 24: {
					break;
				}
				case 25: {
					break;
				}
				case 26: {
					break;
				}
				case 27: {
					break;
				}
				case 28: {
					break;
				}
				case 29: {
					break;
				}
				case 30: {
					break;
				}
				case 31: {
					break;
				}
				case 32: {
					break;
				}
				case 33: {
					break;
				}
				case 34: {
					break;
				}
				case 35: {
					break;
				}
				case 36: {
					break;
				}
				case 37: {
					break;
				}
				case 38: {
					break;
				}
				case 39: {
					break;
				}
				case 40: {
					break;
				}
				case 41: {
					break;
				}
				case 42: {
					break;
				}
				case 43: {
					break;
				}
				case 44: {
					break;
				}
				case 45: {
					break;
				}
				case 46: {
					break;
				}
			}
			switch ( cs ) {
			}
			switch ( cs ) {
				case 47:
				goto _st47;case 0:
				goto _st0;case 1:
				goto _ctr1;case 2:
				goto _ctr6;case 3:
				goto _ctr8;case 4:
				goto _ctr10;case 5:
				goto _ctr12;case 6:
				goto _ctr15;case 7:
				goto _ctr18;case 8:
				goto _ctr23;case 9:
				goto _ctr27;case 10:
				goto _ctr29;case 11:
				goto _ctr31;case 12:
				goto _ctr33;case 13:
				goto _ctr35;case 14:
				goto _ctr37;case 15:
				goto _ctr41;case 16:
				goto _ctr45;case 17:
				goto _ctr48;case 18:
				goto _ctr51;case 19:
				goto _ctr53;case 20:
				goto _ctr55;case 21:
				goto _ctr57;case 22:
				goto _ctr59;case 23:
				goto _ctr61;case 24:
				goto _ctr63;case 25:
				goto _ctr67;case 26:
				goto _ctr70;case 27:
				goto _ctr72;case 28:
				goto _ctr74;case 29:
				goto _ctr76;case 30:
				goto _ctr78;case 31:
				goto _ctr80;case 32:
				goto _ctr83;case 33:
				goto _ctr85;case 34:
				goto _ctr88;case 35:
				goto _ctr92;case 36:
				goto _ctr94;case 37:
				goto _ctr96;case 38:
				goto _ctr98;case 39:
				goto _ctr101;case 40:
				goto _ctr103;case 41:
				goto _ctr105;case 42:
				goto _ctr107;case 43:
				goto _ctr109;case 44:
				goto _ctr111;case 45:
				goto _ctr114;case 46:
				goto _ctr116;	}
		}
		
		if ( cs >= 47 )
			goto _out; _pop: {}
		_out: {}
	}
	
#line 118 "/home/rich/qa/ltp-executor/driver-parser.rl"
	
}

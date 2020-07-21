#line 1 "/home/rich/qa/runltp-ng/executor/parser.rl"
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
* graph e.g `ragel -V -p parser.rl | dot -Tsvg | display` */

#line 25 "/home/rich/qa/runltp-ng/executor/parser.c"
static const int parse_start = 33;

static const int parse_en_main = 33;


#line 142 "/home/rich/qa/runltp-ng/executor/parser.rl"


/* Holds the current state of the finite state machine
*
* TODO: Could put this in actor.priv
*/
static int cs;
static size_t n, id, buf_len;
static char *buf;
struct cmds *cmds;

void parser_init(void)
{
	
#line 46 "/home/rich/qa/runltp-ng/executor/parser.c"
	{
		cs = (int)parse_start;
	}
	
#line 157 "/home/rich/qa/runltp-ng/executor/parser.rl"
	
}

/* Feed the parsing FSM a, possibly incomplete, stream of command data. The
* state is retained between calls unless you call parser_init again
*/
void parser_feed(struct actor *self, char *str, size_t len)
{
	char *p = str, *pe = str + len;
	char *eof = NULL;
	struct msg *msg;
	
	
#line 65 "/home/rich/qa/runltp-ng/executor/parser.c"
	{
		if ( p == pe )
			goto _test_eof;
		switch ( cs ) {
			case 33:
			goto st_case_33;
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
			case 34:
			goto st_case_34;
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
		}
		goto st_out;
		_st33:
		if ( p == eof ) {
			if ( cs >= 33 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof33;
		st_case_33:
		switch( ( (*( p))) ) {
			case 65: {
				goto _st1;
			}
			case 67: {
				goto _st8;
			}
			case 69: {
				goto _st18;
			}
			case 80: {
				goto _st28;
			}
			case 97: {
				goto _st1;
			}
			case 99: {
				goto _st8;
			}
			case 101: {
				goto _st18;
			}
			case 112: {
				goto _st28;
			}
		}
		{
			goto _ctr2;
		}
		_ctr2:
		{
#line 107 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Epected ping, allc, exit, cmds, or exec");
			{goto _st33;}}
		
#line 189 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st0;
		_ctr9:
		{
#line 107 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Epected ping, allc, exit, cmds, or exec");
			{goto _st33;}}
		
#line 199 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		{
#line 87 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Expected white space");
			{goto _st33;}}
		
#line 207 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st0;
		_ctr12:
		{
#line 92 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Expected digit");
			{goto _st33;}}
		
#line 217 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st0;
		_ctr31:
		{
#line 92 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Expected digit");
			{goto _st33;}}
		
#line 227 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		{
#line 87 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Expected white space");
			{goto _st33;}}
		
#line 235 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st0;
		_ctr37:
		{
#line 97 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Expected symbol character");
			{goto _st33;}}
		
#line 245 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st0;
		_ctr40:
		{
#line 97 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Expected symbol character");
			{goto _st33;}}
		
#line 255 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		{
#line 87 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Expected white space");
			{goto _st33;}}
		
#line 263 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st0;
		_ctr43:
		{
#line 102 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Expected string character");
			{goto _st33;}}
		
#line 273 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st0;
		_ctr83:
		{
#line 107 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Epected ping, allc, exit, cmds, or exec");
			{goto _st33;}}
		
#line 283 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		{
#line 82 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Expected new line");
			{goto _st33;}}
		
#line 291 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st0;
		st_case_0:
		_st0:
		cs = 0;
		goto _pop;
		_ctr1:
		{
#line 107 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Epected ping, allc, exit, cmds, or exec");
			{goto _st33;}}
		
#line 305 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st1;
		_st1:
		if ( p == eof ) {
			if ( cs >= 33 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof1;
		st_case_1:
		switch( ( (*( p))) ) {
			case 76: {
				goto _st2;
			}
			case 108: {
				goto _st2;
			}
		}
		{
			goto _ctr2;
		}
		_ctr4:
		{
#line 107 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Epected ping, allc, exit, cmds, or exec");
			{goto _st33;}}
		
#line 337 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st2;
		_st2:
		if ( p == eof ) {
			if ( cs >= 33 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof2;
		st_case_2:
		switch( ( (*( p))) ) {
			case 76: {
				goto _st3;
			}
			case 108: {
				goto _st3;
			}
		}
		{
			goto _ctr2;
		}
		_ctr6:
		{
#line 107 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Epected ping, allc, exit, cmds, or exec");
			{goto _st33;}}
		
#line 369 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st3;
		_st3:
		if ( p == eof ) {
			if ( cs >= 33 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof3;
		st_case_3:
		switch( ( (*( p))) ) {
			case 67: {
				goto _st4;
			}
			case 99: {
				goto _st4;
			}
		}
		{
			goto _ctr2;
		}
		_ctr8:
		{
#line 107 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Epected ping, allc, exit, cmds, or exec");
			{goto _st33;}}
		
#line 401 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		{
#line 87 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Expected white space");
			{goto _st33;}}
		
#line 409 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st4;
		_st4:
		if ( p == eof ) {
			if ( cs >= 33 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof4;
		st_case_4:
		switch( ( (*( p))) ) {
			case 9: {
				goto _st5;
			}
			case 32: {
				goto _st5;
			}
		}
		if ( 11 <= ( (*( p))) && ( (*( p))) <= 12 ) {
			goto _st5;
		}
		{
			goto _ctr9;
		}
		_ctr11:
		{
#line 92 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Expected digit");
			{goto _st33;}}
		
#line 444 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st5;
		_st5:
		if ( p == eof ) {
			if ( cs >= 33 )
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
				goto _st5;
			}
			case 32: {
				goto _st5;
			}
		}
		if ( ( (*( p))) > 12 ) {
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto _ctr13;
			}
		} else if ( ( (*( p))) >= 11 ) {
			goto _st5;
		}
		{
			goto _ctr12;
		}
		_ctr14:
		{
#line 92 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Expected digit");
			{goto _st33;}}
		
#line 483 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st6;
		_ctr13:
		{
#line 25 "/home/rich/qa/runltp-ng/executor/parser.rl"
			n = (( (*( p)))) - '0'; }
		
#line 491 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st6;
		_ctr17:
		{
#line 26 "/home/rich/qa/runltp-ng/executor/parser.rl"
			n = n * 10 + ((( (*( p)))) - '0'); }
		
#line 499 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st6;
		_st6:
		if ( p == eof ) {
			if ( cs >= 33 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof6;
		st_case_6:
		switch( ( (*( p))) ) {
			case 10: {
				goto _ctr16;
			}
			case 32: {
				goto _ctr15;
			}
		}
		if ( ( (*( p))) > 12 ) {
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto _ctr17;
			}
		} else if ( ( (*( p))) >= 9 ) {
			goto _ctr15;
		}
		{
			goto _ctr12;
		}
		_ctr15:
		{
#line 34 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			/* TODO: Validate ID */
			id = id_to_addr(n);
		}
		
#line 539 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st7;
		_st7:
		if ( p == eof ) {
			if ( cs >= 33 )
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
				goto _ctr19;
			}
			case 32: {
				goto _st7;
			}
		}
		if ( 9 <= ( (*( p))) && ( (*( p))) <= 12 ) {
			goto _st7;
		}
		{
			goto _st0;
		}
		_ctr16:
		{
#line 34 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			/* TODO: Validate ID */
			id = id_to_addr(n);
		}
		
#line 575 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		{
#line 45 "/home/rich/qa/runltp-ng/executor/parser.rl"
			tester_start(id); }
		
#line 581 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st34;
		_ctr19:
		{
#line 45 "/home/rich/qa/runltp-ng/executor/parser.rl"
			tester_start(id); }
		
#line 589 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st34;
		_ctr45:
		{
#line 62 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			*buf = '\0';
			buf = NULL;
			
			msg = msg_alloc();
			msg->type = MSG_CMDS;
			msg->ptr = cmds;
			
			actor_say(self, id, msg);
		}
		
#line 606 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st34;
		_ctr59:
		{
#line 34 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			/* TODO: Validate ID */
			id = id_to_addr(n);
		}
		
#line 617 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		{
#line 73 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			msg = msg_alloc();
			msg->type = MSG_EXEC;
			
			actor_say(self, id, msg);
		}
		
#line 628 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st34;
		_ctr62:
		{
#line 73 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			msg = msg_alloc();
			msg->type = MSG_EXEC;
			
			actor_say(self, id, msg);
		}
		
#line 641 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st34;
		_ctr67:
		{
#line 80 "/home/rich/qa/runltp-ng/executor/parser.rl"
			shutdown(self); }
		
#line 649 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st34;
		_ctr76:
		{
#line 39 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			msg = msg_alloc();
			msg->type = MSG_PONG;
			actor_say(self, ADDR_WRITER, msg);
		}
		
#line 661 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st34;
		_st34:
		if ( p == eof ) {
			if ( cs >= 33 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof34;
		st_case_34:
		switch( ( (*( p))) ) {
			case 65: {
				goto _st1;
			}
			case 67: {
				goto _st8;
			}
			case 69: {
				goto _st18;
			}
			case 80: {
				goto _st28;
			}
			case 97: {
				goto _st1;
			}
			case 99: {
				goto _st8;
			}
			case 101: {
				goto _st18;
			}
			case 112: {
				goto _st28;
			}
		}
		{
			goto _ctr83;
		}
		_ctr20:
		{
#line 107 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Epected ping, allc, exit, cmds, or exec");
			{goto _st33;}}
		
#line 711 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st8;
		_st8:
		if ( p == eof ) {
			if ( cs >= 33 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof8;
		st_case_8:
		switch( ( (*( p))) ) {
			case 77: {
				goto _st9;
			}
			case 109: {
				goto _st9;
			}
		}
		{
			goto _ctr2;
		}
		_ctr22:
		{
#line 107 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Epected ping, allc, exit, cmds, or exec");
			{goto _st33;}}
		
#line 743 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st9;
		_st9:
		if ( p == eof ) {
			if ( cs >= 33 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof9;
		st_case_9:
		switch( ( (*( p))) ) {
			case 68: {
				goto _st10;
			}
			case 100: {
				goto _st10;
			}
		}
		{
			goto _ctr2;
		}
		_ctr24:
		{
#line 107 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Epected ping, allc, exit, cmds, or exec");
			{goto _st33;}}
		
#line 775 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st10;
		_st10:
		if ( p == eof ) {
			if ( cs >= 33 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof10;
		st_case_10:
		switch( ( (*( p))) ) {
			case 83: {
				goto _st11;
			}
			case 115: {
				goto _st11;
			}
		}
		{
			goto _ctr2;
		}
		_ctr26:
		{
#line 107 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Epected ping, allc, exit, cmds, or exec");
			{goto _st33;}}
		
#line 807 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		{
#line 87 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Expected white space");
			{goto _st33;}}
		
#line 815 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st11;
		_st11:
		if ( p == eof ) {
			if ( cs >= 33 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof11;
		st_case_11:
		switch( ( (*( p))) ) {
			case 9: {
				goto _st12;
			}
			case 32: {
				goto _st12;
			}
		}
		if ( 11 <= ( (*( p))) && ( (*( p))) <= 12 ) {
			goto _st12;
		}
		{
			goto _ctr9;
		}
		_ctr28:
		{
#line 92 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Expected digit");
			{goto _st33;}}
		
#line 850 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st12;
		_st12:
		if ( p == eof ) {
			if ( cs >= 33 )
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
				goto _st12;
			}
			case 32: {
				goto _st12;
			}
		}
		if ( ( (*( p))) > 12 ) {
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto _ctr29;
			}
		} else if ( ( (*( p))) >= 11 ) {
			goto _st12;
		}
		{
			goto _ctr12;
		}
		_ctr29:
		{
#line 25 "/home/rich/qa/runltp-ng/executor/parser.rl"
			n = (( (*( p)))) - '0'; }
		
#line 887 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st13;
		_ctr33:
		{
#line 26 "/home/rich/qa/runltp-ng/executor/parser.rl"
			n = n * 10 + ((( (*( p)))) - '0'); }
		
#line 895 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st13;
		_ctr30:
		{
#line 92 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Expected digit");
			{goto _st33;}}
		
#line 905 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		{
#line 87 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Expected white space");
			{goto _st33;}}
		
#line 913 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st13;
		_st13:
		if ( p == eof ) {
			if ( cs >= 33 )
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
				goto _ctr32;
			}
			case 32: {
				goto _ctr32;
			}
		}
		if ( ( (*( p))) > 12 ) {
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto _ctr33;
			}
		} else if ( ( (*( p))) >= 11 ) {
			goto _ctr32;
		}
		{
			goto _ctr31;
		}
		_ctr32:
		{
#line 34 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			/* TODO: Validate ID */
			id = id_to_addr(n);
		}
		
#line 953 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		{
#line 47 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			cmds = malloc(sizeof(*cmds));
			
			assert_perror(errno);
			assert(cmds);
			
			buf_len = sizeof(cmds->tid);
			buf = cmds->tid;
		}
		
#line 967 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st14;
		_ctr34:
		{
#line 97 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Expected symbol character");
			{goto _st33;}}
		
#line 977 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st14;
		_st14:
		if ( p == eof ) {
			if ( cs >= 33 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof14;
		st_case_14:
		switch( ( (*( p))) ) {
			case 10: {
				goto _ctr37;
			}
			case 13: {
				goto _ctr37;
			}
			case 32: {
				goto _st14;
			}
		}
		if ( 9 <= ( (*( p))) && ( (*( p))) <= 12 ) {
			goto _st14;
		}
		{
			goto _ctr35;
		}
		_ctr35:
		{
#line 28 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			n++;
			assert(n < buf_len - 1);
			*(buf++) = (( (*( p))));
		}
		
#line 1017 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st15;
		_ctr38:
		{
#line 97 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Expected symbol character");
			{goto _st33;}}
		
#line 1027 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		{
#line 87 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Expected white space");
			{goto _st33;}}
		
#line 1035 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st15;
		_st15:
		if ( p == eof ) {
			if ( cs >= 33 )
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
		{
			goto _ctr35;
		}
		_ctr39:
		{
#line 57 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			*buf = '\0';
			buf = cmds->cmds;
		}
		
#line 1074 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st16;
		_ctr41:
		{
#line 102 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Expected string character");
			{goto _st33;}}
		
#line 1084 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st16;
		_st16:
		if ( p == eof ) {
			if ( cs >= 33 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof16;
		st_case_16:
		if ( ( (*( p))) == 10 ) {
			goto _ctr43;
		}
		{
			goto _ctr42;
		}
		_ctr42:
		{
#line 28 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			n++;
			assert(n < buf_len - 1);
			*(buf++) = (( (*( p))));
		}
		
#line 1113 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st17;
		_ctr44:
		{
#line 102 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Expected string character");
			{goto _st33;}}
		
#line 1123 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st17;
		_st17:
		if ( p == eof ) {
			if ( cs >= 33 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof17;
		st_case_17:
		if ( ( (*( p))) == 10 ) {
			goto _ctr45;
		}
		{
			goto _ctr42;
		}
		_ctr46:
		{
#line 107 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Epected ping, allc, exit, cmds, or exec");
			{goto _st33;}}
		
#line 1150 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st18;
		_st18:
		if ( p == eof ) {
			if ( cs >= 33 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof18;
		st_case_18:
		switch( ( (*( p))) ) {
			case 88: {
				goto _st19;
			}
			case 120: {
				goto _st19;
			}
		}
		{
			goto _ctr2;
		}
		_ctr48:
		{
#line 107 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Epected ping, allc, exit, cmds, or exec");
			{goto _st33;}}
		
#line 1182 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st19;
		_st19:
		if ( p == eof ) {
			if ( cs >= 33 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof19;
		st_case_19:
		switch( ( (*( p))) ) {
			case 69: {
				goto _st20;
			}
			case 73: {
				goto _st25;
			}
			case 101: {
				goto _st20;
			}
			case 105: {
				goto _st25;
			}
		}
		{
			goto _ctr2;
		}
		_ctr51:
		{
#line 107 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Epected ping, allc, exit, cmds, or exec");
			{goto _st33;}}
		
#line 1220 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st20;
		_st20:
		if ( p == eof ) {
			if ( cs >= 33 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof20;
		st_case_20:
		switch( ( (*( p))) ) {
			case 67: {
				goto _st21;
			}
			case 99: {
				goto _st21;
			}
		}
		{
			goto _ctr2;
		}
		_ctr53:
		{
#line 107 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Epected ping, allc, exit, cmds, or exec");
			{goto _st33;}}
		
#line 1252 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st21;
		_st21:
		if ( p == eof ) {
			if ( cs >= 33 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof21;
		st_case_21:
		switch( ( (*( p))) ) {
			case 9: {
				goto _st22;
			}
			case 32: {
				goto _st22;
			}
		}
		if ( 11 <= ( (*( p))) && ( (*( p))) <= 12 ) {
			goto _st22;
		}
		{
			goto _ctr2;
		}
		_ctr55:
		{
#line 92 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Expected digit");
			{goto _st33;}}
		
#line 1287 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st22;
		_st22:
		if ( p == eof ) {
			if ( cs >= 33 )
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
				goto _st22;
			}
			case 32: {
				goto _st22;
			}
		}
		if ( ( (*( p))) > 12 ) {
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto _ctr56;
			}
		} else if ( ( (*( p))) >= 11 ) {
			goto _st22;
		}
		{
			goto _ctr12;
		}
		_ctr57:
		{
#line 92 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Expected digit");
			{goto _st33;}}
		
#line 1326 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st23;
		_ctr56:
		{
#line 25 "/home/rich/qa/runltp-ng/executor/parser.rl"
			n = (( (*( p)))) - '0'; }
		
#line 1334 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st23;
		_ctr60:
		{
#line 26 "/home/rich/qa/runltp-ng/executor/parser.rl"
			n = n * 10 + ((( (*( p)))) - '0'); }
		
#line 1342 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st23;
		_st23:
		if ( p == eof ) {
			if ( cs >= 33 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof23;
		st_case_23:
		switch( ( (*( p))) ) {
			case 10: {
				goto _ctr59;
			}
			case 32: {
				goto _ctr58;
			}
		}
		if ( ( (*( p))) > 12 ) {
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto _ctr60;
			}
		} else if ( ( (*( p))) >= 9 ) {
			goto _ctr58;
		}
		{
			goto _ctr12;
		}
		_ctr58:
		{
#line 34 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			/* TODO: Validate ID */
			id = id_to_addr(n);
		}
		
#line 1382 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st24;
		_st24:
		if ( p == eof ) {
			if ( cs >= 33 )
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
				goto _ctr62;
			}
			case 32: {
				goto _st24;
			}
		}
		if ( 9 <= ( (*( p))) && ( (*( p))) <= 12 ) {
			goto _st24;
		}
		{
			goto _st0;
		}
		_ctr63:
		{
#line 107 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Epected ping, allc, exit, cmds, or exec");
			{goto _st33;}}
		
#line 1417 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st25;
		_st25:
		if ( p == eof ) {
			if ( cs >= 33 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof25;
		st_case_25:
		switch( ( (*( p))) ) {
			case 84: {
				goto _st26;
			}
			case 116: {
				goto _st26;
			}
		}
		{
			goto _ctr2;
		}
		_ctr65:
		{
#line 107 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Epected ping, allc, exit, cmds, or exec");
			{goto _st33;}}
		
#line 1449 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st26;
		_st26:
		if ( p == eof ) {
			if ( cs >= 33 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof26;
		st_case_26:
		switch( ( (*( p))) ) {
			case 10: {
				goto _ctr67;
			}
			case 32: {
				goto _st27;
			}
		}
		if ( 9 <= ( (*( p))) && ( (*( p))) <= 12 ) {
			goto _st27;
		}
		{
			goto _ctr2;
		}
		_st27:
		if ( p == eof ) {
			if ( cs >= 33 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof27;
		st_case_27:
		switch( ( (*( p))) ) {
			case 10: {
				goto _ctr67;
			}
			case 32: {
				goto _st27;
			}
		}
		if ( 9 <= ( (*( p))) && ( (*( p))) <= 12 ) {
			goto _st27;
		}
		{
			goto _st0;
		}
		_ctr68:
		{
#line 107 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Epected ping, allc, exit, cmds, or exec");
			{goto _st33;}}
		
#line 1509 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st28;
		_st28:
		if ( p == eof ) {
			if ( cs >= 33 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof28;
		st_case_28:
		switch( ( (*( p))) ) {
			case 73: {
				goto _st29;
			}
			case 105: {
				goto _st29;
			}
		}
		{
			goto _ctr2;
		}
		_ctr70:
		{
#line 107 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Epected ping, allc, exit, cmds, or exec");
			{goto _st33;}}
		
#line 1541 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st29;
		_st29:
		if ( p == eof ) {
			if ( cs >= 33 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof29;
		st_case_29:
		switch( ( (*( p))) ) {
			case 78: {
				goto _st30;
			}
			case 110: {
				goto _st30;
			}
		}
		{
			goto _ctr2;
		}
		_ctr72:
		{
#line 107 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Epected ping, allc, exit, cmds, or exec");
			{goto _st33;}}
		
#line 1573 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st30;
		_st30:
		if ( p == eof ) {
			if ( cs >= 33 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof30;
		st_case_30:
		switch( ( (*( p))) ) {
			case 71: {
				goto _st31;
			}
			case 103: {
				goto _st31;
			}
		}
		{
			goto _ctr2;
		}
		_ctr74:
		{
#line 107 "/home/rich/qa/runltp-ng/executor/parser.rl"
			
			error_msg(self, "Epected ping, allc, exit, cmds, or exec");
			{goto _st33;}}
		
#line 1605 "/home/rich/qa/runltp-ng/executor/parser.c"
		
		goto _st31;
		_st31:
		if ( p == eof ) {
			if ( cs >= 33 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof31;
		st_case_31:
		switch( ( (*( p))) ) {
			case 10: {
				goto _ctr76;
			}
			case 32: {
				goto _st32;
			}
		}
		if ( 9 <= ( (*( p))) && ( (*( p))) <= 12 ) {
			goto _st32;
		}
		{
			goto _ctr2;
		}
		_st32:
		if ( p == eof ) {
			if ( cs >= 33 )
				goto _out;
			else
				goto _pop;
		}
		p+= 1;
		if ( p == pe )
			goto _test_eof32;
		st_case_32:
		switch( ( (*( p))) ) {
			case 10: {
				goto _ctr76;
			}
			case 32: {
				goto _st32;
			}
		}
		if ( 9 <= ( (*( p))) && ( (*( p))) <= 12 ) {
			goto _st32;
		}
		{
			goto _st0;
		}
		st_out:
		_test_eof33: cs = 33; goto _test_eof; 
		_test_eof1: cs = 1; goto _test_eof; 
		_test_eof2: cs = 2; goto _test_eof; 
		_test_eof3: cs = 3; goto _test_eof; 
		_test_eof4: cs = 4; goto _test_eof; 
		_test_eof5: cs = 5; goto _test_eof; 
		_test_eof6: cs = 6; goto _test_eof; 
		_test_eof7: cs = 7; goto _test_eof; 
		_test_eof34: cs = 34; goto _test_eof; 
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
		
		_test_eof: {}
		if ( p == eof ) {
			switch ( cs ) {
				case 33: {
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
				case 34: {
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
			}
			switch ( cs ) {
			}
			switch ( cs ) {
				case 33:
				goto _st33;case 0:
				goto _st0;case 1:
				goto _ctr1;case 2:
				goto _ctr4;case 3:
				goto _ctr6;case 4:
				goto _ctr8;case 5:
				goto _ctr11;case 6:
				goto _ctr14;case 7:
				goto _st7;case 34:
				goto _st34;case 8:
				goto _ctr20;case 9:
				goto _ctr22;case 10:
				goto _ctr24;case 11:
				goto _ctr26;case 12:
				goto _ctr28;case 13:
				goto _ctr30;case 14:
				goto _ctr34;case 15:
				goto _ctr38;case 16:
				goto _ctr41;case 17:
				goto _ctr44;case 18:
				goto _ctr46;case 19:
				goto _ctr48;case 20:
				goto _ctr51;case 21:
				goto _ctr53;case 22:
				goto _ctr55;case 23:
				goto _ctr57;case 24:
				goto _st24;case 25:
				goto _ctr63;case 26:
				goto _ctr65;case 27:
				goto _st27;case 28:
				goto _ctr68;case 29:
				goto _ctr70;case 30:
				goto _ctr72;case 31:
				goto _ctr74;case 32:
				goto _st32;	}
		}
		
		if ( cs >= 33 )
			goto _out; _pop: {}
		_out: {}
	}
	
#line 171 "/home/rich/qa/runltp-ng/executor/parser.rl"
	
}

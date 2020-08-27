# Protocol

Human readable protocal for communication between the simple
SUT-side test executor and host/controller-side driver.

TODO: Use some existing protocol and command set?

# Notation

Literal text is written verbatim as is whitespace. Arguments or values are
enclosed in '<' and '>'. The type of the value preceeds the values name,
seperated by a ':' e.g. <type:name>. Optional arguments are enclosed in '['
and ']'.

# Data types

Protocol is made up of literal characters, strings and integers

## Integers (int)

All numbers are unsigned integers, represented as a human readable string
of chars e.g. `12` is literally the integer twelve. Should not exceed
uint64_t.

### Identity (ID)

Used to identify a test or communication channel, so that multiple
tests/operations can be carried out at once. It is an integer N where N > 0
and N <= INT_MAX.

## Strings

None of the strings have quote marks around them!

### Symbols (sym)

Strings with no whitespace or special characters, much like C symbols
except they can also include '-'. They are delimited by whitespace

### Prefixed Strings <strn>

Binary safe strings, prefixed with the integer length. May contain any
character. Written like:

<Int:length> <char[length]:chars>

e.g. `7 foo bar` is the string "foo bar"

### Newline terminated strings <str>

A string terminated by a new line. e.g. `foo bar\n`.

# Executor Commands

TODO: Not all of these are implemented, see parse.rl.

Most commands `cmd` respond with `+<sym:cmd> ...` to acknowledge the command.

+ `PING\n` -> PONG\n
	- Heartbeat
+ `ALLC <ID:id>\n` -> `+ALLC <ID:id>\n`
	- Allocate a tester/worker with the given ID
	- e.g. `ALLC 1\n` creates a worker with ID 1
+ `CMDS <ID:id> <sym:tid> <str:cmds>` -> `+CMDS <ID:id> <sym:tid> ...`
	- Set the current test executable command line
	- e.g. `CMD 1 test01 test01 -i 10\n` sets worker 1's test command to `test01 -i 10` with TID `test01`
+ (TODO) `ENVE <ID:id> <sym:name> <str:value>` -> `+ENVE <ID:id> <sym:name> ...`
	- set an environment variable for the given worker
+ `EXEC <ID:id>\n` -> `+EXEC <ID:id>\n`
	- Execute the current test command on a given worker
	- e.g. `EXEC 1\n`
+ `EXIT\n` -> `+EXIT\n` then `eof` ofcourse.
	- Exit the executor

Generally you first send `allc` to allocate workers, then set the current tests with `cmds` and then `exec`.
After which you wait for the following messages.

# Driver Commands

The Driver does not acknowledge messages from the Executor.

+ `LOGD <ID:id> <strn:log>\n`
	- Test output from stdout or stderr from the given worker. If the string log length is zero then this
	  indicates EOF.
	- e.g. `LOGD 1 3 foo\n` or `LOGD 1 0 \n`, note the mandatory space between the length and new line.
+ `TRES <ID:id> <int:returned>\n`
	- Test result from a given worker, that is, the return value of the executable.
	- e.g. `TRES 1 0\n`
+ (TODO) `ERRD <ID:id> <str:message>`

When you have seen `LOGD 1 0 \n` and `TRES 1 0\n` the test is
finished and you can set another test with `cmds` or rerun the same
test with `exec`.

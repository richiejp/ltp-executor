# Ultra fancy remote test executor

Small executable which runs on the SUT, starts test executables and
multiplexes the test results/output.

It is transport agnostic, meaning it uses stdin and stdout. Just hook up stdio
and stdout to whatever SUT/host transport you are using e.g. SSH, ttyS0,
FireWire, CAN, Bluetooth, cups-and-string etc.

It is multithreaded and uses a message-passing actors system based on
liburcu. Output from the tests is weaved onto the output pipe by a single
writer thread.

### TODO

- for some transports it might make more sense to open a socket for each test
  case and let the kernel handle interleaving the data.

## Building

Required dependencies:
- C11 compatible compiler
- CMake (and GNU Make or Ninja etc)
- pthreads
- liburcu
- [libactors](https://gitlab.com/Palethorpe/libactors)(you will need to
  install this from source)

Optional:
- Ragel (used to regenerate parser.c)
- expect (Only used for the tests)
- libasan (disable `-fsanitize=address` if you don't want it)

Ragel is more rare (although it is in most distros), but the generated parser
is distributed with the code so it is only necessary for development. The ASAN
is only a debug tool and will be eventually disabled during production.

To build:

```sh
$ mkdir build
$ cd build
$ cmake ..
$ make
```

To run the tests:

```sh
$ make test
```

or

```sh
$ ctest -V
```

### TODO

- We probably want the option build statically, then we can copy&paste onto
  SUTS and even pipe the LTP tests onto the SUT removing the need to install
  LTP on the SUT.
- Configure development and production targets in CMake

## Usage

Realistically this is not usable yet, but you can just run the executor and
type stuff in manually.

```sh
$ ./executor
ping
PONG
exit
+EXIT
```

See `executor.c` for the available commands and protocol description. Note
that there is no error checking yet, so if you enter some bad input the parser
state machine will enter an *absorbing barrier*.

The Expect test scripts are informative:

```sh
$ expect test/tester-exec.exp
allc 1
+ALLC 1
cmds 1 true
+CMDS 1 true
exec 1
+EXEC 1
TRES 1 0
cmds 1 echo -n foobar
+CMDS 1 echo -n foobar
exec 1
+EXEC 1
LOGD 1 6 foobar
TRES 1 0
cmds 1 false
+CMDS 1 false
exec 1
+EXEC 1
TRES 1 1
```

# Ultra fancy concurrent test executor

Allows remote concurrent test execution with or without SSH and easier
integration of the LTP with any test automation framework.

Primarily includes a small executable which runs on the SUT, starts test
executables in parallel and multiplexes the test results/output.

A simple, human readable, protocol is used between SUT and host. You
can use this directly or use the provided host/controller side
`driver` executable to feed the `executor` and record the results.

The executor and driver are transport agnostic, meaning they use stdin
and stdout. Just hook up stdio to whatever SUT/host transport you are
using e.g. IPMI-SOL, SSH, ttyS0, FireWire, CAN, Bluetooth,
cups-and-string etc. (see Usage for how to do this).

It is multithreaded and uses a message-passing actors system based on
liburcu. Output from the tests is weaved onto the transport by a
single writer thread.

This is designed to be used with an existing test automation framework
or whatever you use to provision and control the SUT
(e.g. [runltp-ng](https://github.com/metan-ucw/runltp-ng)). However
there is a complete, [QEMU based test
runner](test/qemu-integration.sh) similar to
[Rapido](https://github.com/rapido-linux/rapido) included.

## Building

Required dependencies:
- C11 compatible compiler
- CMake (and GNU Make or Ninja etc)
- pthreads
- liburcu
- [libactors](https://gitlab.com/Palethorpe/libactors) (you will need to
  install this from source)

Optional:
- Ragel (used to regenerate parser.c)
- expect (Only used for the tests)
- socat, QEMU, dracut (Only used in the full-stack tests)
- libasan (disable `-fsanitize=address` if you don't want it)
- QEMU, dracut and the kernel (For the integration tests)

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

To run the tests (except QEMU):

```sh
$ make test
```

or

```sh
$ ctest -V
```

To run full-stack integration test:

```sh
$ export KERNEL_SRC=/path/to/linux
$ export LTP_DIR=/opt/ltp
$ ../test/qemu-integration.sh
```

See `test/qemu-dracut.sh` for the defaults. This works similar to
[Rapido](https://github.com/rapido-linux/rapido).

### TODO

- We probably want the option build statically, then we can copy&paste onto
  SUTS and even pipe the LTP tests onto the SUT removing the need to install
  LTP on the SUT.
- Configure development and production targets in CMake so we are not
  always running with libasan and debugging turned on.
- Fix various bugs

Also see source comments.

## Usage

*This is WIP so you may trip over some assertion errors and such.*

The executor takes no arguments, reads from stdin and writes to stdout. You
can redirect its IO using `sh` or `ssh`, `socat` etc.

### Basics

You can just run the executor and type stuff in manually.

```sh
$ ./executor
Executor v0.1
ping
PONG
allc 1
+ALLC 1
cmds 1 echo01 echo "An echo"
+CMDS 1 echo01 echo "An echo"
exec 1
+EXEC 1
LOGD 1 8 An echo

LOGD 1 0 
TRES 1 0
exit
+EXIT
```

See `executor.c` for the available commands and protocol description.

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

### With the driver and tstctl

The `tstctl` command can create and query a test plan which the
`driver` executes.

```sh
$ ./tstctl init
$ ./tstctl set NRPOC 4
$ ./tstctl add-tests /opt/ltp/runtest/syscalls
$ while [ $(./tstctl status) = TODO ]; do
>    ./script-to-restart-qemu.sh
>    socat EXEC:../driver UNIX-CONNECT:transport,retry=3
> done
```

When the `driver` receives `TBROK` from a test, or similar, it updates
the test plan and exits. You may then use `tstctl` to query the plan
and decide what to do next e.g. continue with or without reseting the
SUT.

### Running in a VM

It's possible to use a virtio serial port as the host-SUT transport. For
example on SUT startup the following script can be executed (assumes the first
`vport` is used by the console).

```sh
exec 3<>/dev/vport1p1
executor >&3 <&3
```

QEMU can direct this through a socket

```sh
...
-device virtio-serial \
-chardev socket,server,id=transport,path=transport \
-device virtserialport,chardev=transport \
...
```

You can then pipe commands through the socket

```sh
$ socat STDIO UNIX-CONNECT:transport
```

See `test/qemu-integration.sh` for a complete example of how to do this.

## Further Documentation

Documentation is located in `./docs` and in some source comments.

+ [protocol](doc/protocol.md)

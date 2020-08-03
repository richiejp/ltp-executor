#!/usr/bin/sh -eu

. ../test/push-test-dir.sh

../../tstctl init
../../tstctl set NPROC 1
../../tstctl add-tests ../../test/runtest-file

. ../../test/qemu-dracut.sh
. ../../test/qemu-start.sh

echo "Running tests with one worker"
time {
while [ $(../../tstctl status) = TODO ]; do
    echo "More tests; (re)starting driver"
    socat EXEC:../driver UNIX-CONNECT:transport,retry=3
done
}

echo "Running test with 4 workers"
../../tstctl init
../../tstctl set NPROC 4
../../tstctl add-tests ../../test/runtest-file

time {
while [ $(../../tstctl status) = TODO ]; do
    echo "More tests; (re)starting driver"
    socat EXEC:../driver UNIX-CONNECT:transport,retry=3
done
}

echo "All done!"

# expect ../../test/tester-concurrent.exp ${TEST_DIR}/transport || {
#     echo -e "Final SUT console output was:\n"
#     tail tty.log
#     exit 123
# }

# . ../../test/pop-test-dir.sh

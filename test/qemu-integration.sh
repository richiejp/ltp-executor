#!/usr/bin/sh -eu

echo "Using Test dir" ${TEST_DIR:=$(pwd)/test}

mkdir $TEST_DIR || true
cd $TEST_DIR

. ../../test/qemu-dracut.sh
. ../../test/qemu-start.sh

expect ../../test/tester-concurrent.exp ${TEST_DIR}/transport || {
    echo -e "Final SUT console output was:\n"
    tail tty.log
    exit 123
}

cd ..
rm -r $TEST_DIR

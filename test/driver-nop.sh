#!/usr/bin/sh -eu

. ../test/push-test-dir.sh

echo NPROC 1 > test-plan
echo DONE not-a-test 0 false >> test-plan

expect ../../test/driver-mock-run-once.exp




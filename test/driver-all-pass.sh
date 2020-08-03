#!/usr/bin/sh -eu

. ../test/push-test-dir.sh

echo NPROC 1 > test-plan

echo TODO true true >> test-plan
echo DONE foo 1 bar >> test-plan
echo DONE baz 127 foo >> test-plan
echo TODO echo echo echo >> test-plan

expect ../../test/driver-mock-run-once.exp

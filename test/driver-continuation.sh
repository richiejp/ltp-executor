#!/usr/bin/sh -eu

. ../test/push-test-dir.sh

echo NPROC 1 > test-plan

echo TODO pass pass >> test-plan
echo TODO fail fail >> test-plan
echo TODO pass pass >> test-plan
echo TODO pass pass >> test-plan

expect ../../test/driver-mock-run-twice.exp

[ $(../../tstctl status) = DONE ] || false

. ../../test/pop-test-dir.sh

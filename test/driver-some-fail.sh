#!/usr/bin/sh -eu

. ../test/push-test-dir.sh

echo NPROC 1 > test-plan

echo TODO never run >> test-plan
echo TODO false false >> test-plan
echo TODO true true >> test-plan
echo TODO echo echo echo >> test-plan

expect ../../test/driver-mock-run-once.exp


#!/usr/bin/sh -eu

nproc=4

. ../test/push-test-dir.sh

echo NPROC $nproc > test-plan

for i in $(seq 0 $nproc); do
    echo TODO true-$i true >> test-plan
    echo TODO echo-$i echo echo $i >> test-plan
done

mkfifo a b

../executor < b | tee executor.log > a &
../driver < a | tee driver.log > b

echo EXIT > b
wait

. ../../test/pop-test-dir.sh

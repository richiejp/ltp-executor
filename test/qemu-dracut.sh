#!/usr/bin/sh -eu
# Largely copied from rapido

echo "Using kernel dir" ${KERNEL_SRC:=~/kernel/linux}
echo "Using LTP dir"  ${LTP_DIR:=/opt/ltp}

kver="$(cat ${KERNEL_SRC}/include/config/kernel.release)"
test_cases=$(cat ../../test/runtest-file | awk "{ FS = \" \"; print \"$LTP_DIR/testcases/bin/\"\$2 }")

mkdir initrds || true

dracut \
    --no-compress --no-hostonly --no-early-microcode --no-hostonly-cmdline \
    --no-kernel \
    --force --tmpdir initrds \
    --kver $kver \
    --install "$test_cases" \
    --include ../executor /usr/bin/executor \
    --include ../../test/run-executor-on-vsport.sh /.profile \
    --modules "bash base" \
    myinitrd

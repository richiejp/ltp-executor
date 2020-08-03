#!/bin/bash

ip addr add 127.0.0.1/8 dev lo
ip addr add ::1 dev lo
ip link set lo up

export PATH=$PATH:/opt/ltp/testcases/bin

echo "Opening transport /dev/vport1p1"
exec 3<>/dev/vport1p1

echo "Running executor"

executor >&3 <&3

echo "Executor finished"

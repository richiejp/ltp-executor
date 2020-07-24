#!/bin/bash

echo "Opening transport /dev/vport1p1"
exec 3<>/dev/vport1p1

echo "Running executor"

executor >&3 <&3

echo "Executor finished"

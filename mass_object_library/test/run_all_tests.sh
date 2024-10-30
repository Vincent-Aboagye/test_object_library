#!/bin/bash

# *******************************************************************
# Copyright (c) University of Luxembourg 2023.
# Created by Enrico VIGANO, enrico.vigano@uni.lu, SnT, 2023.
# ********************************************************************

deco="#######################################################"

pushd .. || exit 1

echo $deco
echo "compiling the library..."
echo $deco

make clean && make
popd || exit 1

echo $deco
echo "compiling the test suite..."
echo $deco

make clean && make
echo $deco
echo "executing the test suite..."
echo $deco

failures=0

#RUNALL for test_case in  circle-s square-s rectangle-s triangle-s example-s circle-p square-p rectangle-p triangle-p triangle-p-a example-p triangle-p-e triangle-s-e triangle-p-a-e; do
for test_case in  circle-s square-s rectangle-s triangle-s example-s circle-p square-p rectangle-p triangle-p triangle-p-a example-p triangle-p-e triangle-s-e triangle-p-a-e; do
    echo " "
    echo $deco
    echo "# $test_case"
    echo $deco

    ./run_test $test_case
    if [ $? -ne 0 ]; then
	failures=1
    fi
done

if [ $failures -ne 0 ]; then
    echo "!!! TEST FAILURES were reported above !!!"
fi

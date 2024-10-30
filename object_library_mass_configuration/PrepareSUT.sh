#!/bin/bash

#
# Copyright (c) University of Luxembourg 2021.
# Created by Oscar Eduardo CORNEJO OLIVARES, oscar.cornejo@uni.lu, SnT, 2021.
# Modified by Enrico VIGANO, enrico.vigano@uni.lu, SnT, 2023
#

cd $HOME/mass_workspace || exit 1
. ./mass_conf.sh

############################################################################
# 0. removing previous files if needed
############################################################################
pushd $PROJ || exit 1
make clean
popd || exit 1

pushd $PROJ_TST || exit 1
make clean
popd || exit 1

############################################################################
# 1. Compile SUT
# generate compile_commands.json and delete build, then compile SUT
############################################################################
pushd $PROJ || exit 1

bear_version=$(bear --version)
if [ ! -n "$bear_version" ]; then
    echo "bear is not installed"
    exit 2
fi

bear_version_number=$(echo "$bear_version" | awk -F'[ .]' '{print $2}')
if [ "$bear_version_number" -ge 3 ]; then
    bear -- make
    mv compile_commands.json $MUTANTS_DIR && make clean
else
    src_absolute_path=$(realpath src)
    bear make && sed -i "s:src:$src_absolute_path:" compile_commands.json
    mv compile_commands.json $MUTANTS_DIR && make clean
fi

eval "${COMPILATION_CMD[@]}" || exit 2
popd || exit 1
############################################################################
# 2. Execute test cases
# Note: execution time for each test case should be measured and passed as
# argument to FAQAS-CollectCodeCoverage.sh
############################################################################

#RUNALL for tst in  circle-s square-s rectangle-s triangle-s example-s circle-p square-p rectangle-p triangle-p triangle-p-a example-p triangle-p-e triangle-s-e triangle-p-a-e; do
for tst in circle-s square-s rectangle-s triangle-s example-s circle-p square-p rectangle-p triangle-p triangle-p-a example-p; do

	pushd $PROJ_TST || exit 1
	make clean && make
	popd || exit 1

	echo "Test: $tst"
	pushd $PROJ_TST || exit 1
	start_test=$(date +%s)
	./run_test $tst
	end_test=$(date +%s)
	popd || exit 1

	########################################################################
	# 3. call to FAQAS-CollectCodeCoverage.sh
	# the parameters should be test case name and the execution time
	############################################################################
	source $MASS/FAQAS-GenerateCodeCoverageMatrixes/FAQAS-CollectCodeCoverage.sh $tst "$(($end_test-$start_test))"

done




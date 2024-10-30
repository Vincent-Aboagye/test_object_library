#
# Copyright (c) University of Luxembourg 2021.
# Created by Oscar Eduardo CORNEJO OLIVARES, oscar.cornejo@uni.lu, SnT, 2021.
#

# implementation of the bash function run_tst_case
# run_tst_case receives the test case name, executes the test case,
# and returns 0 if the test case passes, otherwise returns 1
#
# example of the MLFS library

run_tst_case() {

	tst=$1

	pushd $PROJ_TST > /dev/null
	./run_test $tst
	return_value=$?
	popd > /dev/null

	if [ "$return_value" != "0" ]; then
		return 1
	else
		return 0
	fi

}

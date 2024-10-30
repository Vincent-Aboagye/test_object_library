#!/bin/bash

#
# Copyright (c) University of Luxembourg 2021.
# Created by Oscar Eduardo CORNEJO OLIVARES, oscar.cornejo@uni.lu, SnT, 2021.
#

# set SRCIROR path
# example: $HOME/FAQAS/MASS
export SRCIROR=$HOME/FAQAS/MASS

export LLVM_BUILD=${SRCIROR}/llvm-build
export SRCIROR_SRC_MUTATOR=${SRCIROR}/SRCMutation/build/mutator
export SRCIROR_LLVM_BIN=${LLVM_BUILD}/Release+Asserts/bin/
export SRCIROR_LLVM_INCLUDES=${LLVM_BUILD}/Release+Asserts/lib/clang/3.8.0/include/
export SRCIROR_COMPILER=$SRCIROR/PythonWrappers/mutationClang
export MASS=$SRCIROR/MASS

####

# set directory path where MASS files can be stored
# example: APP_RUN_DIR=/opt/example
export APP_RUN_DIR=

# specifies the building system, available options are Makefile and waf
# example: BUILD_SYSTEM=Makefile
export BUILD_SYSTEM=Makefile

# directory root path of the software under test
# example: PROJ=$HOME/mlfs
export PROJ=$HOME/mass-testing-library

# directory src path of the SUT
# example: PROJ_SRC=$PROJ/libm
export PROJ_SRC=$PROJ/src

# directory test path of the SUT
# example: PROJ_TST=$HOME/unit-test-suite
export PROJ_TST=$PROJ/test

# directory coverage path of the SUT
# example: PROJ_COV=$HOME/blts_workspace
export PROJ_COV=$PROJ/src

# directory path of the compiled binary
# example: PROJ_BUILD=$PROJ/build-host/bin
export PROJ_BUILD=$PROJ/bin

# list of folders not to be included during the analysis
# example: COVERAGE_NOT_INCLUDE=tst\|libutil\|libgscsp\|libparam_client
export COVERAGE_NOT_INCLUDE=

# filename of the compiled file/library
# example: COMPILED=libmlfs.a
export COMPILED=libmasstesting.a

# path to original Makefile
# example: ORIGINAL_MAKEFILE=$PROJ/Makefile
export ORIGINAL_MAKEFILE=$PROJ/Makefile

# compilation command of the SUT
# example: COMPILATION_CMD=(make all ARCH=host EXTRA_CFLAGS=-DNDEBUG \&\& make all COVERAGE=true ARCH=host_cov EXTRA_CFLAGS=-DNDEBUG)
export COMPILATION_CMD=(make)

# compilation additional commands of the SUT (e.g., setup of workspace)
# example ADDITIONAL_CMD=(cd $HOME/blts/BLTSConfig \&\& make clean install INSTALL_PATH=$HOME/blts_install \&\& cd $HOME/blts_workspace \&\& $HOME/blts_install/bin/blts_app --init)
export ADDITIONAL_CMD=(cd $PROJ \&\& make clean \&\& make \&\& cd $PROJ_TST \&\& make clean \&\& make)

# command to be executed after each test case (optional)
# example: ADDITIONAL_CMD_AFTER=(rm -rf $HOME/blts_workspace/*)
export ADDITIONAL_CMD_AFTER=

# compilation command for TCE analysis
# example TCE_COMPILE_CMD=(make all ARCH=host EXTRA_CFLAGS=-DNDEBUG)
export TCE_COMPILE_CMD=(make)

# command to clean installation of the SUT
# example CLEAN_CMD=(make cleanall)
export CLEAN_CMD=(make clean)

# relative path to location of gcov files (i.e., gcda and gcno files)
# example GC_FILES_RELATIVE_PATH=Reports/Coverage/Data
export GC_FILES_RELATIVE_PATH=

### MASS variables

# specify if MASS will be executed on a HPC, possible values are true or false
# example: HPC=true
export HPC="false"

# TCE flags to be tested
#example FLAGS=("-O0" "-O1" "-O2" "-O3" "-Ofast" "-Os")
export FLAGS=("-O0" "-O1" "-O2" "-O3" "-Ofast" "-Os")

# set if MASS should be executed with a prioritized and reduced test suite
# example PRIORITIZED="true"
export PRIORITIZED="true"

# set sampling technique, possible values are "uniform", "stratified", and "fsci"
# note: if "uniform" or "stratified" is set, $PRIORITIZED must be "false"
# example SAMPLING="fsci"
export SAMPLING="fsci"

# set sampling rate if whether "uniform" or "stratified" sampling has been selected
#example RATE="0.003"
export RATE=

# if "true", the pipeline uses the new mode of collecting coverage instead of the legacy one
export NEW_COVERAGE_MODE="true"

# options to execute the pipeline focusing on a single file:
# FOCUS_ON_FILE should be set to "true" to enable this option
# FILE_PATH should contain the absolute path to the file
export FOCUS_ON_FILE="false"
export FILE_PATH=


# option to execute the pipeline split between two containers, one for the SUT
# and one for the more advanced requirements of MASS
export MASS_SPLIT="false"

####

export MUTANTS_DIR=$APP_RUN_DIR/src-mutants
mkdir -p $MUTANTS_DIR

export MUTATION_DIR=$APP_RUN_DIR/MUTATION
export COV_FILES=$APP_RUN_DIR/COV_FILES

export MASS_LIVE_MUTANTS_SORTING_STRATEGY=s1
# uncomment the following in case you are interested in sorting live mutants based on cyclomatic complexity 
# 	mutants of functions with higher "cyclomatic complexity/number of lines in the function" will be first
#	it requires the python package "metrixpp" 
#export MASS_LIVE_MUTANTS_SORTING_STRATEGY="code_metrics"

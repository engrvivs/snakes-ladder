#!/bin/bash

rm -rf build*/

# Configure
# <CXX=g++> cmake -S . -B build <-G"Unix Makefiles"> <-DBUILD_TESTING=ON> <-DCMAKE_INSTALL_PREFIX:PATH=install> <-DCMAKE_BUILD_TYPE=Debug> <--trace OR --trace-source="filename" <--trace-expand>>
CXX=g++ cmake -S . -B buildMake -G"Unix Makefiles"

# make
# cmake --build buildMake -j 4 -v 2> make.out
cmake --build buildMake -j 4 -v

# check 
./buildMake/snakes-ladders

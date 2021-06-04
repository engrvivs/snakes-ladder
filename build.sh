#!/bin/bash

rm -rf build*/
#cmake --build buildMake --target clean

# Configure
# <CXX=g++> cmake -S . -B build <-G"Unix Makefiles"> <-DBUILD_TESTING=ON> <-DCMAKE_INSTALL_PREFIX:PATH=install> <-DCMAKE_BUILD_TYPE=Debug> <--trace OR --trace-source="filename" <--trace-expand>>
CXX=g++ cmake -S . -B buildMake -G"Unix Makefiles" -DBUILD_TESTING=ON -DENABLE_COVERAGE=ON

# make
# cmake --build buildMake -j 4 -v 2> make.out
cmake --build buildMake -j 4 -v

# check
#./buildMake/test_snakes-ladders
#./buildMake/snakes-ladders

cd buildMake; ctest . -j 4; 

lcov_file=code_coverage.info
lcov --capture --directory . --output-file=${lcov_file}
# remove unwarranted system files
lcov --remove ${lcov_file} '/usr/*' -o ${lcov_file}

lcov --list ${lcov_file}
lcov --summary ${lcov_file}
# genhtml ${lcov_file} --title=snakes-ladders --output-directory=res --show-details --legend --demangle-cpp --missed
cd ..

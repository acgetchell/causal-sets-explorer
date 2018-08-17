#!/usr/bin/env bash
rm -rf build/
mkdir build && cd build
#cmake -DCMAKE_BUILD_TYPE=Debug ..
#cmake --build .
#cmake --build . --target test

conan install .. -pr default
conan build ..
ctest
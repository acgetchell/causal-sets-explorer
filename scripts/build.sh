#!/usr/bin/env bash

cd ..
rm -rf build/
cmake -G Ninja -D CMAKE_BUILD_TYPE=Release -D ENABLE_IPO=ON -S . -B build
cmake --build build
cd build/src || exit
ctest --output-on-failure
# ./causal_sets_explorer --success --exit
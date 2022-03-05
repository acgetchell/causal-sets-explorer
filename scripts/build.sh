#!/usr/bin/env bash

cd ..
rm -rf build/
cmake -G Ninja -D CMAKE_BUILD_TYPE=Release -S . -B build
cmake --build build
cd build || exit
ctest --output-on-failure -j2
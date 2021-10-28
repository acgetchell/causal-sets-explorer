#!/usr/bin/env bash
cd ..
rm -rf build/
cmake -D CMAKE_BUILD_TYPE=Release -S . -B build
cmake --build build
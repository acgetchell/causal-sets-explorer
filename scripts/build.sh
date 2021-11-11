#!/usr/bin/env bash
spack load boost
spack load catch2
cd ..
rm -rf build/
cmake -D CMAKE_BUILD_TYPE=Release -S . -B build
cmake --build build
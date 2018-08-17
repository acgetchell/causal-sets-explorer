#!/usr/bin/env bash
rm -rf build/
mkdir build && cd build
cmake --G Ninja -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .
cmake --build . --target test
#!/bin/bash

rm -rf build && mkdir -p build && cd build
conan install ../ --build=missing
cmake -G Ninja -DCMAKE_BUILD_TYPE=Release ..
cmake --build .

ls -la build/bin
cd build/bin && ./causal_sets_explorer
cd build/bin && ./unittests
#!/usr/bin/env bash
rm -rf build/
mkdir build && cd build
conan install .. --build=missing --profile apple-clang
conan build ..
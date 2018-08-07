#!/usr/bin/env bash
rm -rf build/
mkdir build && cd build
conan install .. --build=missing -s compiler=apple-clang -s compiler.version=9.1 -s compiler.libcxx=libc++
conan build ..
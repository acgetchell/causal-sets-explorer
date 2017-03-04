cmake_minimum_required(VERSION 3.7)
project(causal_sets_explorer)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/main.cpp)
add_executable(causal_sets_explorer ${SOURCE_FILES})
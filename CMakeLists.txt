cmake_minimum_required(VERSION 3.11)

project(causal_sets_explorer VERSION 0.1.2 LANGUAGES CXX)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(FATAL_ERROR "Do not build in-source.
                       Please remove CMakeCache.txt and the CMakeFiles/ directory. Then build out-of-source.")
endif()

#Activate C++ 17 support
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#Disable CLion generation of RelWithDebInfo and MinSizeRel, et.al
set(CMAKE_CONFIGURATION_TYPES "Release" "Debug" CACHE STRING "" FORCE)

#Extra warnings
#add_definitions(-Wall)

find_package(Boost REQUIRED COMPONENTS graph)
include_directories( ${Boost_INCLUDE_DIRS} )

#Build our project
add_executable(causal_sets_explorer ${PROJECT_SOURCE_DIR}/src/main.cpp)
#target_include_directories(causal_sets_explorer BEFORE PUBLIC ${Boost_INCLUDE_DIRS})
target_compile_features(causal_sets_explorer PRIVATE cxx_std_17)

#Now enable our tests
enable_testing()
add_subdirectory(tests)

#CTest Integration tests
include(CTest)

#Does the causal_sets_explorer run ?
add_test(NAME causal_sets_explorer-Run COMMAND $<TARGET_FILE:causal_sets_explorer>)
set_tests_properties(causal_sets_explorer-Run
        PROPERTIES
        PASS_REGULAR_EXPRESSION "digraph")

cmake_minimum_required(VERSION 3.10)

project(causal_sets_explorer VERSION 0.1.1 LANGUAGES CXX)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(FATAL_ERROR "Do not build in-source.
                       Please remove CMakeCache.txt and the CMakeFiles/ directory. Then build out-of-source.")
endif()

if (EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, running conan install.")
    execute_process(COMMAND conan install .. --build=missing)
endif()

# Activate C++17 support
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Disable CLion generation of RelWithDebInfo and MinSizeRel, et. al
set(CMAKE_CONFIGURATION_TYPES "Release" "Debug" CACHE STRING "" FORCE)

#include_directories(src)
#file(GLOB_RECURSE PROJECT_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

#Extra warnings
#add_definitions(-Wall)

# Exclude main file for library generation, only use it in the final
# executable. This lets us test everything without compiling twice.
#set(PROJECT_MAIN "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")
#list(REMOVE_ITEM PROJECT_SOURCE ${PROJECT_MAIN})

# Build our project with the help of conan.
#include_directories(${CONAN_INCLUDE_DIRS})
#add_library(causal_sets_explorerlib STATIC ${PROJECT_SOURCE})
add_library(causal_sets_explorer_testlib STATIC src/main.cpp)
add_executable(causal_sets_explorer ${PROJECT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(causal_sets_explorer causal_sets_explorer_testlib ${CONAN_LIBS})
target_compile_features(causal_sets_explorer PRIVATE cxx_std_17)

# Now enable our tests
enable_testing()
add_subdirectory(tests)

#CTest Integration tests
include(CTest)

# Does the causal_sets_explorer run?
add_test(NAME causal_sets_explorer-Run
         COMMAND causal_sets_explorer)
#         --config $<CONFIGURATION>)
#         --exe $<TARGET_FILE:causal_sets_explorer>)
set_tests_properties(causal_sets_explorer-Run
        PROPERTIES
        PASS_REGULAR_EXPRESSION "digraph")


cmake_minimum_required(VERSION 3.11)

project(causal_sets_explorer VERSION 0.1.2 LANGUAGES CXX)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(FATAL_ERROR "Do not build in-source.
                       Please remove CMakeCache.txt and the CMakeFiles/ directory. Then build out-of-source.")
endif()

# Run Conan from CMake
# Download automatically, you can also just copy the conan.cmake file
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.12/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_cmake_run(CONANFILE conanfile.py  # or relative build/conanfile.txt
        BASIC_SETUP CMAKE_TARGETS
        BUILD missing)

#Activate C++ 17 support
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#Disable CLion generation of RelWithDebInfo and MinSizeRel, et.al
set(CMAKE_CONFIGURATION_TYPES "Release" "Debug" CACHE STRING "" FORCE)

#Extra warnings
#add_definitions(-Wall)

#Build our project with the help of conan.
add_executable(causal_sets_explorer ${PROJECT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(causal_sets_explorer CONAN_PKG::boost CONAN_PKG::catch2)
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

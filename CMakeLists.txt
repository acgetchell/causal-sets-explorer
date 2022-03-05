cmake_minimum_required(VERSION 3.16)

# vcpkg settings must be set before project()
if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  set(CMAKE_TOOLCHAIN_FILE
      "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
      CACHE STRING "")
endif()

# In Manifest mode CMake invokes vcpkg automatically This makes setup easier, however, in CI or Docker we may want to
# turn this off
option(VCPKG_MANIFEST_MODE "Build vcpkg ports from manifest" ON)

# Ensure we install vcpkg ports in the same place so they can be reused between builds
set(_VCPKG_INSTALLED_DIR
    "${CMAKE_CURRENT_LIST_DIR}/vcpkg_installed"
    CACHE STRING "")

project(causal_sets_explorer VERSION 0.1.2 LANGUAGES CXX)

cmake_policy(SET CMP0127 NEW)

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

if(ENABLE_CLANG_TIDY)
  find_program(CLANGTIDY clang-tidy)
  if(CLANGTIDY)
    set(CMAKE_CXX_CLANG_TIDY ${CLANGTIDY} -extra-arg=-Wno-unknown-warning-option)
    message(STATUS "Clang-tidy enabled.")
  else()
    message(SEND_ERROR "clang-tidy requested but executable not found")
  endif()
endif()

#Extra warnings
add_definitions(-Wall)

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

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

# Project settings
include(cmake/StandardProjectSettings.cmake)

# Prevent in source builds
include(cmake/PreventInSourceBuilds.cmake)

# Link this 'library' to set the c++ standard / compile-time options requested
add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_17)

if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
  option(ENABLE_BUILD_WITH_TIME_TRACE "Enable -ftime-trace to generate time tracing .json files on clang" OFF)
  if(ENABLE_BUILD_WITH_TIME_TRACE)
    add_compile_definitions(project_options INTERFACE -ftime-trace)
  endif()
endif()

# Link this 'library' to use the warnings specified in CompilerWarnings.cmake
add_library(project_warnings INTERFACE)

# enable cache system
include(cmake/Cache.cmake)

# standard compiler warnings
include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

# sanitizer options if supported by compiler
include(cmake/Sanitizers.cmake)
enable_sanitizers(project_options)

# allow for static analysis options
include(cmake/StaticAnalyzers.cmake)

# Options ##
option(BUILD_SHARED_LIBS "Enable compilation of shared libraries" OFF)
option(ENABLE_TESTING "Enable building of tests" ON)

# Modules and scripts ##
include(CTest)
include(CMakeDependentOption)

# Project vcpkg dependencies

find_package(Boost REQUIRED COMPONENTS graph)
include_directories( ${Boost_INCLUDE_DIRS} )

find_package(doctest CONFIG REQUIRED)

# Header files
include_directories(BEFORE ${PROJECT_SOURCE_DIR}/include)

# Doctest
#if (ENABLE_TESTING)
enable_testing()
message(STATUS "Building tests. Look at /tests for unit tests.")
add_subdirectory(tests)
#endif()

add_subdirectory(src)

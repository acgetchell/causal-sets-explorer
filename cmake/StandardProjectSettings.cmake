# Disable CLion generation of MinSizeRel to avoid conflicts with CGAL_SetupFlags.cmake
set(CMAKE_CONFIGURATION_TYPES
    "Release" "Debug" "RelWithDebInfo"
    CACHE STRING "" FORCE)

# Set a default build type if none was specified
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to 'RelWithDebInfo' as none was specified.")
  set(CMAKE_BUILD_TYPE
      RelWithDebInfo
      CACHE STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui, ccmake
  set_property(
    CACHE CMAKE_BUILD_TYPE
    PROPERTY STRINGS
             "Debug"
             "Release"
             "RelWithDebInfo")
endif()

# Compile commands for ClangTidy et. al
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Link time optimization
# Turning this on disables debugging
option(ENABLE_IPO "Enable Interprocedural Optimization, aka Link Time Optimization (LTO)" OFF)
if(ENABLE_IPO)
  include(CheckIPOSupported)
  check_ipo_supported(RESULT result OUTPUT output)
  if(result)
    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
    message(STATUS "IPO enabled.")
  else()
    message(WARNING "IPO is not supported: ${output}")
  endif()
endif()

# Set minimum Boost version
set(BOOST_MIN_VERSION "1.78.0")

# Use C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Threads
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)

# Turn off CMake dev warnings
cmake_policy(SET CMP0127 OLD)

# Easier navigation in an IDE when projects are organized in folders.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
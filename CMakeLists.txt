project(causal_sets_explorer)

cmake_minimum_required(VERSION 3.9.0)

if (EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, running conan install.")
    execute_process(COMMAND conan install .. --build=missing)
endif ()

# Activate C++17 support
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Disable CLion generation of RelWithDebInfo and MinSizeRel, et. al
set(CMAKE_CONFIGURATION_TYPES "Release" "Debug" CACHE STRING "" FORCE)

include_directories(src)
file(GLOB_RECURSE PROJECT_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

#Extra warnings
#add_definitions(-Wall)

# Exclude main file for library generation, only use it in the final
# executable. This lets us test everything without compiling twice.
set(PROJECT_MAIN "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")
list(REMOVE_ITEM PROJECT_SOURCE ${PROJECT_MAIN})

# Build our project with the help of conan.
include_directories(${CONAN_INCLUDE_DIRS})
add_library(causal_sets_explorerlib STATIC ${PROJECT_SOURCE})
add_executable(causal_sets_explorer ${PROJECT_MAIN})
target_link_libraries(causal_sets_explorer causal_sets_explorerlib ${CONAN_LIBS})

# Now enable our tests
enable_testing()
add_subdirectory(tests)

# Toggle GoogleMock
#option(GMOCK_TESTS OFF)
## Set minimum Boost
#set(BOOST_MIN_VERSION  "1.65.1")
#
#set(SOURCE_FILES src/main.cpp)
#add_executable(causal_sets_explorer ${SOURCE_FILES})
#target_link_libraries(causal_sets_explorer ${CONAN_LIBS})
#
##GMock Tests executable
################################################################################
#if (GMOCK_TESTS)
#    set(UT_EXECUTABLE_NAME "unittests")
#
#    #Test files
#    file(GLOB TEST_FILES "unittests/*.cpp")
#    add_executable("${UT_EXECUTABLE_NAME}" ${TEST_FILES} ${SRC_FILES})
#
#    #Set link libraries(order matters)
#    target_link_libraries("${UT_EXECUTABLE_NAME}"
#                            gmock gtest pthread)
#
#    #Include root directory
#    include_directories(BEFORE ".")
#    include_directories(BEFORE "src/")
#endif()

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


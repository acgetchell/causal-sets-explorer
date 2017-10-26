project(causal_sets_explorer)

cmake_minimum_required(VERSION 3.9.4)

if (EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, running conan install.")
    execute_process(COMMAND conan install .. --build=missing)
endif ()


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#Extra warnings
#add_definitions(-Wall)

# Toggle GoogleMock
option(GMOCK_TESTS OFF)

set(SOURCE_FILES src/main.cpp)
add_executable(causal_sets_explorer ${SOURCE_FILES})
target_link_libraries(causal_sets_explorer ${CONAN_LIBS})

#GMock Tests executable
###############################################################################
if (GMOCK_TESTS)
    set(UT_EXECUTABLE_NAME "unittests")

    #Test files
    file(GLOB TEST_FILES "unittests/*.cpp")
    add_executable("${UT_EXECUTABLE_NAME}" ${TEST_FILES} ${SRC_FILES})

    #Set link libraries(order matters)
    target_link_libraries("${UT_EXECUTABLE_NAME}"
                            gmock gtest pthread)

    #Include root directory
    include_directories(BEFORE ".")
    include_directories(BEFORE "src/")
endif()

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


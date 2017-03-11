cmake_minimum_required(VERSION 3.2)
project(causal_sets_explorer)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/main.cpp)
add_executable(causal_sets_explorer ${SOURCE_FILES})
target_link_libraries(causal_sets_explorer ${CONAN_LIBS})

#GMock Tests executable
###############################################################################
set(GMOCK_TESTS TRUE)
if (GMOCK_TESTS)

    set(UT_EXECUTABLE_NAME "unittests")

    #Test files
    file(GLOB TEST_FILES "unittests/*.cpp")

    add_executable("${UT_EXECUTABLE_NAME}" ${TEST_FILES} ${SRC_FILES})

    #Set link libraries(order matters)
    target_link_libraries("${UT_EXECUTABLE_NAME}"
            ${TBB_LIBRARIES} gmock gtest pthread)

    #Include root directory
    include_directories(BEFORE ".")
    include_directories(BEFORE "src/")

endif()
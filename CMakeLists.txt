project(causal_sets_explorer)

cmake_minimum_required(VERSION 3.8.0)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

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
            ${TBB_LIBRARIES} gmock gtest pthread)

    #Include root directory
    include_directories(BEFORE ".")
    include_directories(BEFORE "src/")

endif()
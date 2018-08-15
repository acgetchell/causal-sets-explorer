cmake_minimum_required(VERSION 3.5)

file(GLOB_RECURSE TEST_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(causal_sets_explorer_test ${TEST_SOURCE})
target_link_libraries(causal_sets_explorer_test causal_sets_explorer_testlib ${CONAN_LIBS})
# We run our test from the source directory, so we can consistently
# load files with known paths.
# I also like color in my verbose output, so I put in a --force-colour flag.
add_test(NAME causal_sets_explorer_tests
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMAND ${CMAKE_BINARY_DIR}/bin/causal_sets_explorer_test --force-colour)

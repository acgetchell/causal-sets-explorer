add_executable(causal_sets_explorer ${PROJECT_SOURCE_DIR}/src/main.cpp)
#target_include_directories(causal_sets_explorer BEFORE PUBLIC ${Boost_INCLUDE_DIRS})
target_link_libraries(causal_sets_explorer PRIVATE doctest::doctest)
target_compile_features(causal_sets_explorer PRIVATE cxx_std_20)

#Now enable our tests
enable_testing()
# add_subdirectory(tests)

#CTest Integration tests
include(CTest)

#Does the causal_sets_explorer executable run ?
add_test(NAME CommandLine COMMAND $<TARGET_FILE:causal_sets_explorer>)
set_tests_properties(CommandLine
        PROPERTIES
        PASS_REGULAR_EXPRESSION "digraph")

# Run DocTests
add_test(NAME UnitTests COMMAND $<TARGET_FILE:causal_sets_explorer> --success --exit)
add_executable(causal_sets_test ${PROJECT_SOURCE_DIR}/tests/main.cpp
    Graph_test.cpp Make_graph_test.cpp)
target_link_libraries(causal_sets_test PRIVATE project_options project_warnings fmt::fmt-header-only)
target_compile_features(causal_sets_test PRIVATE cxx_std_20)

# Run the tests
add_test(NAME causal_sets_tests COMMAND $<TARGET_FILE:causal_sets_test>)

cmake_minimum_required(VERSION 3.10)

add_executable(causal_sets_explorer_test ${PROJECT_SOURCE_DIR}/tests/main.cpp GraphTest.cpp)
target_link_libraries(causal_sets_explorer_test CONAN_PKG::boost CONAN_PKG::catch2)

add_test(NAME causal_sets_explorer-Graph COMMAND $<TARGET_FILE:causal_sets_explorer_test>)

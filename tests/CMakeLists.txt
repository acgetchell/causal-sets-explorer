cmake_minimum_required(VERSION 3.11)

find_package(Catch2 CONFIG REQUIRED)
include_directories( ${Catch2_DIR} )

add_executable(causal_sets_explorer_test ${PROJECT_SOURCE_DIR}/tests/main.cpp GraphTest.cpp)
target_link_libraries(causal_sets_explorer_test Catch2::Catch2)

add_test(NAME causal_sets_explorer-Graph COMMAND $<TARGET_FILE:causal_sets_explorer_test>)

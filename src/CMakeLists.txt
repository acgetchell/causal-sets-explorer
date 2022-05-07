add_executable(causal_sets_explorer ${PROJECT_SOURCE_DIR}/src/main.cpp)
# target_include_directories(causal_sets_explorer BEFORE PUBLIC
# ${Boost_INCLUDE_DIRS})
target_link_libraries(causal_sets_explorer
                      PRIVATE project_options project_warnings fmt::fmt-header-only)
target_compile_features(causal_sets_explorer PRIVATE cxx_std_20)

#
# Tests    ##
#

# Does the causal_sets_explorer executable run ?
add_test(NAME UnitTests COMMAND $<TARGET_FILE:causal_sets_explorer> --success
                                --exit)

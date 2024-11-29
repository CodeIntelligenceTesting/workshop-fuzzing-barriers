add_fuzzing_example_current_dir()

# Disable assert() statements for the SUT
set_source_files_properties(sut.cpp PROPERTIES COMPILE_FLAGS "-DNDEBUG")
# or
target_compile_options(assert_statements_fuzztest PUBLIC "-DNDEBUG")
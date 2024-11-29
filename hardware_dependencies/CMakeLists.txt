add_fuzzing_example_current_dir()

# We compile the test without optimization to avoid the
# function we want to mock getting inlined by the compiler
target_compile_options(hardware_dependencies_fuzztest PUBLIC "-O0")

# Wrap an internal function within the SUT
target_link_options(hardware_dependencies_fuzztest PUBLIC "-Wl,--defsym,get_hardware_flags=__wrap_get_hardware_flags")

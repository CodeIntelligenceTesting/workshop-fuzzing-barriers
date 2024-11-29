add_fuzzing_example_current_dir()

# Wrap exit() calls
target_link_options(exit_statements_fuzztest PUBLIC "-Wl,--wrap=exit")

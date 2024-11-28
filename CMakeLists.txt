cmake_minimum_required(VERSION 3.19)
project(fuzzing_barriers)

# Export build flags
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include cifuzz
find_package(cifuzz NO_SYSTEM_ENVIRONMENT_PATH)
enable_fuzz_testing()

# For each fuzzing example, we build a fuzz test
# running into a code barrier
function(add_fuzzing_example name dir)
    add_fuzz_test(${name}_fuzztest "${dir}/fuzztest.cpp" "${dir}/sut.cpp")
endfunction()

# Add the current directory as an example
function(add_fuzzing_example_current_dir)
    if("${CMAKE_CURRENT_LIST_DIR}" MATCHES "^/.*/([a-zA-Z_]+)$")
        add_fuzzing_example(${CMAKE_MATCH_1} "${CMAKE_CURRENT_LIST_DIR}")
    else()
        error("Cannot find example name from directory: ${CMAKE_CURRENT_LIST_DIR}")
    endif()
endfunction()

# Add the examples
add_subdirectory(assert_statements)
add_subdirectory(checksum)
add_subdirectory(complex_conditions)
add_subdirectory(exit_statements)
add_subdirectory(hardware_dependencies)
add_subdirectory(hashing)
add_subdirectory(initialization)
add_subdirectory(statefulness)

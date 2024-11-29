#include <cifuzz/cifuzz.h>

#include "sut.h"

/**
 * SOLUTION
 *
 * assert() statements in the SUT are usually very helpful for
 * finding bugs with fuzzing as they can indicate places in the
 * code where the assumptions that the developer made can be
 * violated, which can lead to severe bugs.
 *
 * However, in some cases, assert() statements can be a hindrance.
 * For example, if properties of user input are verified with
 * assert statements instead of proper error handling, the fuzzer
 * will most likely find inputs very quickly that cause those
 * assert() statements to terminate the program, which stops the
 * fuzzer very early and prevents it from gaining more code
 * coverage beyond the failing assertion.
 *
 * It is possible to compile the project and run the fuzzer
 * with assert() statements disabled by using the -DNDEBUG
 * compilation flag (see CMakeLists.txt). However, note that
 * this is usually not recommended and the assert() statements
 * in the SUT should be adjusted instead.
 */

/* 
# Disable assert() statements for the SUT
#target_compile_options(assert_statements_fuzztest PUBLIC "-DNDEBUG")
set_source_files_properties(sut.cpp PROPERTIES COMPILE_FLAGS "-DNDEBUG")
*/
FUZZ_TEST(const uint8_t *data, size_t size) {
    process_data(data, size);
}

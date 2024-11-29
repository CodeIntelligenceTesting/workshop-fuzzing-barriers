#include <cifuzz/cifuzz.h>
#include <setjmp.h>

#include "sut.h"

/**
 * SOLUTION
 *
 * To mock specific functions that the SUT uses, the linker flag
 * --wrap=<function name> can be used. In this example, we wrap
 * the function exit() to avoid that the client terminates the
 * process when the fuzzer generates an invalid input.
 *
 * Within the wrapped function, we use a longjump to jump out
 * of the SUT back to the fuzz test. The reason for this is
 * that we cannot assume that the SUT will continue to function
 * correctly after a call to exit(), which is assumed to never
 * return.
 */

jmp_buf jump_buffer;

// Wraps exit() calls done by the SUT.
// This requires the linker flag --wrap=exit.
// See CMakeLists.txt.
extern "C" _Noreturn void __wrap_exit(int _status) {
    longjmp(jump_buffer, 1);
}

FUZZ_TEST(const uint8_t *data, size_t size) {
    // When setjmp is called the first time for setting the execution
    // context, it returns 0 and we continue testing the SUT.
    // If the SUT jumps here on an exit() call, setjmp returns 1 and
    // we stop processing this test case.
    if(setjmp(jump_buffer))
        return;

    process_data(data, size);
}

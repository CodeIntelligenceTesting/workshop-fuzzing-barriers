#include <cifuzz/cifuzz.h>

#include "sut.h"

/**
 * SOLUTION
 *
 * To find out why a fuzz test is stuck with very little code coverage,
 * it can be helpful to have a look at a code coverage report. The
 * report can be generated with the command:
 * cifuzz coverage initialization_fuzztest
 *
 * In the coverage report we can see that the function mylib_dostuff
 * always returns immediately because its initilization function was
 * never called. To fix this, we can use the FUZZ_TEST_SETUP macro to
 * perform any necessary initializations before FUZZ_TEST is executed.
 */

FUZZ_TEST_SETUP() {
    mylib_init();
}

FUZZ_TEST(const uint8_t *data, size_t size) {
    mylib_dostuff(data, size);
}

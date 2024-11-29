#include <cifuzz/cifuzz.h>

#include "sut.h"

/**
 * SOLUTION
 *
 * In this test case, the fuzzer cannot find any more coverage
 * after the state machine enters into the error state as
 * there is no transition out of it. This is just one example
 * why it is challenging to test stateful applications. Another
 * issue is that if we find a bug, we may not be able to
 * reproduce it with the fuzzer input alone since the
 * application may have been in a specific state when the
 * input was tested.
 *
 * To mitigate those problems, we need to ensure that the
 * application state is the same at the beginning of every
 * test iteration. In this example, we do this by resetting
 * the state machine before testing a new input.
 */

FUZZ_TEST(const uint8_t *data, size_t size) {
    state_machine_reset();
    state_machine_process_input(data, size);
}

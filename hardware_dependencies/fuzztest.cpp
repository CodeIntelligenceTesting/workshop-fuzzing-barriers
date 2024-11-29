#include <cifuzz/cifuzz.h>
#include <cstddef>
#include <cstdint>
#include <fuzzer/FuzzedDataProvider.h>

#include "sut.h"

/**
 * SOLUTION
 *
 * The function get_hardware_flags() in the SUT tries to access
 * a specific memory address to read some data. This is commonly
 * done in embedded systems to interact with hardware. However,
 * doing this in our test case (which runs in a user process)
 * would produce a segfault as the memory address is not mapped.
 * A common solution is to mock such functions for testing.
 *
 * Mocking specific functions within the SUT can be done by
 * using the following linker argument (see CMakeLists.txt):
 * -Wl,--defsym,<function name>=__wrap_<function name>
 * In this example, we wrap the internal SUT function
 * get_hardware_flags() to return a fuzzer generated value
 * for testing. Note that we declare the function as extern "C"
 * to avoid issues with C++ name mangling.
 */

FuzzedDataProvider *fdp_ptr;

extern "C" uint32_t __wrap_get_hardware_flags() {
    return fdp_ptr->ConsumeIntegral<uint32_t>();
}

FUZZ_TEST(const uint8_t *data, size_t size) {
    FuzzedDataProvider fdp(data, size);
    fdp_ptr = &fdp;
    do_sth();
}

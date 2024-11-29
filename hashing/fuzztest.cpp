#include <cifuzz/cifuzz.h>
#include <cstdint>

#include "sut.h"

/**
 * SOLUTION
 *
 * The fuzzer is unable to mutate inputs effectively that are
 * passed through a hashing function, for example when accessing
 * a hashmap. If specific, known keys are being used, they can
 * be assembled in a dictionary to aid the fuzzer with generating
 * valid messages. For this example, we could start the fuzzer
 * with the dictionary as follows:
 * cifuzz run --dict=example_hashing/dictionary.txt \
 *   hashing_fuzztest_fix
 */

FUZZ_TEST(const uint8_t *data, size_t size) {
    std::string input = std::string((const char *) data, size);
    process_string(input);
}

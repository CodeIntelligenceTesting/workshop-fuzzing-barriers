#include <cifuzz/cifuzz.h>
#include <fuzzer/FuzzedDataProvider.h>

#include "sut.h"

/**
 * SOLUTIONS
 *
 * 1. Narrow down the input domain
 *    If we know for example that valid inputs for the second
 *    argument are values in the range [1000, 1200), we can use
 *    the FuzzedDataProvider to only generate values in that
 *    range (see fuzz test below).
 *
 * 2. Use value profiles
 *    Instrumentation of integer comparisons in the code can be
 *    used to guide the fuzzer more easily towards finding very
 *    specific values, such as magic bytes. This works very well
 *    for this example where many specific input arguments are
 *    required. However, it also causes the fuzzer to record and
 *    mutate many more inputs, which can slow down fuzzing as not
 *    all of them will result in more code coverage. To enable
 *    value profiles, start the fuzzer as follows:
 *    cifuzz run --engine-arg="-use_value_profile=1" \
 *      complex_conditions_fuzztest_fix
 *
 * 3. Use a dictionary
 *    If the function that is being tested recognizes specific
 *    strings or byte sequences, we can tell the fuzzer to
 *    include such sequences in the inputs it generates by
 *    providing a dictionary file. For this example, we could
 *    hint the fuzzer to include the value "ABCD" by creating
 *    a dictionary file `complex_conditions.dict` and running
 *    the fuzzer like this:
 *    cifuzz run --dict=example_complex_conditions/dictionary.txt \
 *      complex_conditions_fuzztest_fix
 *
 * Final command:
 * cifuzz run --engine-arg="-use_value_profile=1" \
 *   --dict=example_complex_conditions/dictionary.txt \
 *   complex_conditions_fuzztest_fix
 */

FUZZ_TEST(const uint8_t *data, size_t size) {
    FuzzedDataProvider fdp(data, size);
    explore_me(fdp.ConsumeIntegral<unsigned int>(),
               fdp.ConsumeIntegralInRange<unsigned int>(1000, 1200),
               fdp.ConsumeIntegralInRange<unsigned int>(1042, 1242),
               fdp.ConsumeRemainingBytesAsString());
}
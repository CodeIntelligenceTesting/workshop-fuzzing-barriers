#include <cifuzz/cifuzz.h>
#include <fuzzer/FuzzedDataProvider.h>

#include "sut.h"

FUZZ_TEST(const uint8_t *data, size_t size) {
    FuzzedDataProvider fdp(data, size);
    explore_me(fdp.ConsumeIntegral<unsigned int>(),
               fdp.ConsumeIntegralInRange<unsigned int>(1000, 1200),
               fdp.ConsumeIntegralInRange<unsigned int>(1042, 1242),
               fdp.ConsumeRemainingBytesAsString());
}

#include <cifuzz/cifuzz.h>
#include <fuzzer/FuzzedDataProvider.h>
#include <cstdint>

#include "sut.h"

FUZZ_TEST(const uint8_t *data, size_t size) {
    FuzzedDataProvider fuzzed_data(data, size);
    std::string input = fuzzed_data.ConsumeRandomLengthString();
    process_string(input);
}

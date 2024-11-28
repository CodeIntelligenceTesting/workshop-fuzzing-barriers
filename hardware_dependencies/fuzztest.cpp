#include <cifuzz/cifuzz.h>
#include <cstddef>
#include <cstdint>

#include "sut.h"

FUZZ_TEST(const uint8_t *data, size_t size) {
    do_sth();
}

#include <cifuzz/cifuzz.h>

#include "sut.h"

FUZZ_TEST(const uint8_t *data, size_t size) {
    mylib_dostuff(data, size);
}

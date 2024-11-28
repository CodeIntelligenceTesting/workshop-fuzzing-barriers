#include <cifuzz/cifuzz.h>
#include <cstring>

#include "sut.h"

FUZZ_TEST(const uint8_t *data, size_t size) {
    if(size < sizeof(packet)) {
        return;
    }
    packet p;
    memcpy(&p, data, sizeof(packet));
    process_packet(&p);
}

#include <cstdint>
#include <cstdio>

#include "sut.h"

#define HARDWARE_ADDR 0xFF00AABB
#define HARDWARE_FLAG_ABC (1 << 3)

extern "C" uint32_t get_hardware_flags() {
    return *((uint32_t *) HARDWARE_ADDR);
}

void do_sth() {
    uint32_t flags = get_hardware_flags();
    if(flags & HARDWARE_FLAG_ABC) {
        // Simulate a page fault
        *((char *) 1) = 0;
    }
}

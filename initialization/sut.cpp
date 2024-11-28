#include "sut.h"

static bool is_initialized = false;

void mylib_init() {
    is_initialized = true;
}

void mylib_dostuff(const uint8_t *data, size_t size) {
    // Do nothing if not initialized
    if(!is_initialized)
        return;

    // Some program logic
    if(size >= 10) {
        if((data[4] << 8 | data[9]) == 1337) {
            // Simulate a page fault
            *((char *) 1) = 0;
        }
    }
}

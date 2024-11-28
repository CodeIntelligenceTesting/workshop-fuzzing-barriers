#include <cstdlib>

#include "sut.h"

void process_data(const uint8_t *data, size_t size) {
    if(size < 10)
        return;

    if(data[0] == 42)
        exit(1);

    if(data[3] + 5 - data[7] == 143) {
        // Simulate a page fault
        *((char *) 1) = 0;
    }
}

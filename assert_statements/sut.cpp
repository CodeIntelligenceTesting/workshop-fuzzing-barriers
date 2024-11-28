#include <cassert>

#include "sut.h"

void process_data(const uint8_t *data, size_t size) {
    if(size < 10)
        return;

    // This assert is unrelated to the rest
    // of the logic in this function.
    assert(data[0] > 123 && data[1] == 15);
    
    if(data[3] + 5 - data[7] == 143) {
        // Simulate a page fault
        *((char *) 1) = 0;
    }
}

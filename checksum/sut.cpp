#include "sut.h"

// ----------------------------- crc32b --------------------------------
// Based on:
// https://web.archive.org/web/20190108202303/http://www.hackersdelight.org/hdcodetxt/crc.c.txt
// https://stackoverflow.com/questions/21001659/crc32-algorithm-implementation-in-c-without-a-look-up-table-and-with-a-public-li
unsigned int crc32b(uint8_t *data, unsigned int size) {
    unsigned int crc = 0xFFFFFFFF;
    for(int i = 0; i < size; i++) {
        crc = crc ^ data[i];
        for (int j = 7; j >= 0; j--) {    // Do eight times.
            unsigned int mask = -(crc & 1);
            crc = (crc >> 1) ^ (0xEDB88320 & mask);
        }
    }
    return ~crc;
}
// ---------------------------------------------------------------------

void process_packet(packet *p) {

    if(crc32b(p->data, 32) != p->crc32) {
        // Invalid checksum
        return;
    }

    if(p->data[3] == 15) {
        // Simulate a page fault
        *((char *) 1) = 0;
    }
}

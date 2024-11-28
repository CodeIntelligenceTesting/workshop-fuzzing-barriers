#pragma once

#include <cstdint>

typedef struct {
    unsigned int crc32;
    uint8_t data[32];
} packet;

unsigned int crc32b(uint8_t *data, unsigned int size);
void process_packet(packet *p);

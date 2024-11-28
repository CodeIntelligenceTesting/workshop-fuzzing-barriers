#pragma once

#include <cstddef>
#include <cstdint>

void state_machine_reset();
void state_machine_process_input(const uint8_t *data, size_t size);

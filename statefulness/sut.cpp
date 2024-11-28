#include "sut.h"

static void state_initial(uint8_t input);
static void state_process1(uint8_t input);
static void state_process2(uint8_t input);
static void state_buggy(uint8_t input);
static void state_error(uint8_t input);


typedef void (*state_fn)(uint8_t input);
static volatile state_fn current_state = state_initial;

void state_machine_process_input(const uint8_t *data, size_t size) {
    for(size_t i = 0; i < size; i++) {
        current_state(data[i]);
    }
}

static void state_initial(uint8_t input) {
    if(input == 42) {
        current_state = state_process1;
    } else {
        current_state = state_error;
    }
}

static void state_process1(uint8_t input) {
    if(input == 0) {
        current_state = state_initial;
    } else if(input >= 100 && input < 120) {
        current_state = state_process2;
    } else {
        current_state = state_error;
    }
}

static void state_process2(uint8_t input) {
    if(input == 0) {
        current_state = state_initial;
    } else if(input < 100) {
        current_state = state_process1;
    } else if(input % 33 == 5) {
        current_state = state_buggy;
    } else {
        current_state = state_error;
    }
}

static void state_buggy(uint8_t input) {
    // Simulate a page fault
    *((char *) 1) = 0;
}

static void state_error(uint8_t input) {
    // Cannot recover from error
}

void state_machine_reset() {
    current_state = state_initial;
}
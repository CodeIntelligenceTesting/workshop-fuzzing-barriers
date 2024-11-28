#include <stdexcept>
#include <unordered_map>

#include "sut.h"

std::unordered_map<std::string, int> get_hashmap() {
    std::unordered_map<std::string, int> map;
    for(int i = 0; i < 20; i++) {
        std::string key = std::string("something") + std::to_string(i);
        map[key] = i;
        if(i == 10) {
            map["fuubafu"] = -1;
        }
    }
    return map;
}

void process_string(std::string &input) {
    // Get the hashmap
    static std::unordered_map<std::string, int> hashmap = get_hashmap();
    
    try {
        if(hashmap.at(input) < 0) {
            // Simulate a page fault
            *((char *) 1) = 0;
        }
    } catch(std::out_of_range &ex) {}
}

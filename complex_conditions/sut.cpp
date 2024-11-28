#include "sut.h"

void explore_me(unsigned int a, unsigned int b, unsigned int c, std::string d) {
    if(a == 42) {
        if(b >= 1000 && b < 1200) {
            if(c == (a+b)) {
                if(d.find("{'key':'-#*aBcD3FGH1JKL.-.MNoePQR5TuVWXYZ!?'}, 'cat':'=^.^='") == 3) {
                    // Simulate a page fault
                    *((char *) 1) = 0;
                }
            }
        }
    }
}

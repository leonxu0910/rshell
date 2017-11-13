#include "../header/And.h"
#include <iostream>

void And::execute() {
    prev->execute();
    if (prev->getStatus() == 1) {
        if (next == 0) {
            std::cout << "error: incomplete argument" << std::endl;
        }
        else {
            next->execute();
            if (next->getStatus() == 1) {
                status = 1;
            }
            else if (next->getStatus() == -1) {
                status = -1;
            }
        }
    }
    else if (prev->getStatus() == -1) {
        status = -1;
    }
    else {
        std::cout << "error: incomplete argument" << std::endl;
    }
}
#include "../header/Or.h"
#include <iostream>

void Or::execute() {
    if (prev != 0) {
        prev->execute();
        if (prev->getStatus() == -1) {
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
        else if (prev->getStatus() == 1) {
            status = 1;
        }
        else {
            std::cout << "error: incomplete argument" << std::endl;
        }
    }
    else {
        std::cout << "error: incomplete argument" << std::endl;
    }
}
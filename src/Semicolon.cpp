#include "../header/Semicolon.h"
#include <iostream>

void Semicolon::execute() {
    if (prev == 0) {
        std::cout << "error: incomplete argument" << std::endl;
        return;
    }
    prev->execute();
    if (next != 0) {
        next->execute();
        if (next->getStatus() == 1) {
            status = 1;
        }
    }
}
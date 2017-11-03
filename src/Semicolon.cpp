#include "../header/Semicolon.h"

void Semicolon::execute() {
    if (next != 0) {
        next->execute();
        status = next->getStatus();
    }
    else {
        // no right operand, dont execute
    }
}
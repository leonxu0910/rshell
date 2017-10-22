#include "../header/And.h"

void And::execute() {
    if (status == 1) {
        if (next != 0) {
            next->execute();
            status = next->getStatus();
        }
        else {
            // error: no right operand
        }
    }
    else {
        // previous is false, dont execute
    }
}
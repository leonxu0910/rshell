#include "../header/Or.h"

void Or::execute() {
    if (status == -1) {
        if (next != 0) {
            next->execute();
            status = next->getStatus();
        }
        else {
            // error: no right operand
        }
    }
    else {
        // previous is true, dont execute
    }
}
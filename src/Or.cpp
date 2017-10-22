#include "../header/Or.h"

bool Or::execute() {
    bool done;
    if (status == false) {
        if (next != 0) {
            next->execute();
        }
        else {
            // error: no right operand
        }
    }
    else {
        // previous is true, dont execute
    }
    
    return done;
}
#include "../header/And.h"

bool And::execute() {
    bool done = false;
    if (status == true) {
        if (next != 0) {
            done = next->execute();
        }
        else {
            // error: no right operand
        }
    }
    else {
        // previous is false, dont execute
    }
    return done;
}
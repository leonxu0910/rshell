#include "../header/Semicolon.h"

bool Semicolon::execute() {
    bool done = false;
    if (next != 0) {
        done next->execute();
    }
    else {
        // no right operand, dont execute
    }
    
    return done;
}
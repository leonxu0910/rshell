#include "../header/Semicolon.h"

void Semicolon::execute() {
    if (prev == 0) {
        cout << "error: incomplete argument" << endl;
        return;
    }
    prev->execute();
    if (next != 0) {
        next->execute();
    }
    status = 1;
}
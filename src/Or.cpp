#include "../header/Or.h"

void Or::execute() {
    if (prev == 0 || next == 0) {
        cout << "error: incomplete argument" << endl;
        return;
    }
    prev->execute();
    if (prev->getStatus() == -1) {
        next->execute();
        if (next->getStatus() == 1) {
            status = 1;
        }
        else if (next->getStatus() == -1) {
            status = -1;
        }
        else {
            cout << "error: incomplete argument" << endl;
        }
    }
    else if (prev->getStatus() == 1) {
        status = 1;
    }
    else {
        cout << "error: incomplete argument" << endl;
    }
}
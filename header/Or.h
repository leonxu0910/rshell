#ifndef __OR_H__
#define __OR_H__
#include "Connector.h"

class Or : public Connector {
  public:
    Or(ShellComponent* left, ShellComponent* right) : Connector(left, right) {}
    ~Or() {
        if (next != 0) {
            delete next;
            next = 0; 
        }
        if (prev != 0) {
            delete prev;
            prev = 0;
        }
    }
    void execute();
    
};

#endif
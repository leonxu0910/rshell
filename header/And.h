#ifndef __AND_H__
#define __AND_H__
#include "Connector.h"

class And : public Connector {
  public:
    And(ShellComponent* left, ShellComponent* right) : Connector(left, right) {}
    ~And() {
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
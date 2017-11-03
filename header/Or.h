#ifndef __OR_H__
#define __OR_H__
#include "Connector.h"

class Or : public Connector {
  public:
    Or(ShellComponent* component) : Connector(component) {}
    ~Or() {
        if (next != 0) {
            delete next;
            next = 0; 
        }
    }
    void execute();
    
};

#endif
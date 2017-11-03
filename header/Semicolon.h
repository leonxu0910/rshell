#ifndef __SEMICOLON_H__
#define __SEMICOLON_H__
#include "Connector.h"

class Semicolon : public Connector {
  public:
    Semicolon(ShellComponent* component) : Connector(component) {}
    ~Semicolon() {
        if (next != 0) {
            delete next;
            next = 0; 
        }
    }
    void execute();
    
};

#endif
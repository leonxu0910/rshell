#ifndef __SEMICOLON_H__
#define __SEMICOLON_H__
#include "Connector.h"

class Semicolon : public Connector {
  public:
    Semicolon(ShellComponent* left, ShellComponent* right) : Connector(left, right) {}
    ~Semicolon() {
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
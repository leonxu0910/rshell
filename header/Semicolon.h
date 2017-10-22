#ifndef __SEMICOLON_H__
#define __SEMICOLON_H__
#include "Connector.h"

class Semicolon : public Connector {
  public:
    Semicolon(ShellComponent* component) : Connector(component) {}
    bool execute();
    
};

#endif
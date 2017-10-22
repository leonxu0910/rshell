#ifndef __AND_H__
#define __AND_H__
#include "Connector.h"

class And : public Connector {
  public:
    And(ShellComponent* component) : Connector(component) {}
    bool execute();
    
};

#endif
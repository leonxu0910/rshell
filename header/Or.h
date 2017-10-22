#ifndef __OR_H__
#define __OR_H__
#include "Connector.h"

class Or : public Connector {
  public:
    Or(ShellComponent* component) : Connector(component) {}
    void execute();
    
};

#endif
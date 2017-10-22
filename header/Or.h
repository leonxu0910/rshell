#ifndef __OR_H__
#define __OR_H__
#include "Connector.h"

class Or : public Connector {
  public:
    Or() : Connector() {}
    bool execute();
    
};

#endif
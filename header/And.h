#ifndef __AND_H__
#define __AND_H__
#include "Connector.h"

class And : public Connector {
    public:
        And() : Connector() {}
        bool execute() { return true;}
    
    
};

#endif
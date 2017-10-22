#ifndef __SEMICOLON_H__
#define __SEMICOLON_H__
#include "Connector.h"

class Semicolon : public Connector {
    public:
        Semicolon() : Connector() {}
        bool execute() { return true;}
    
};

#endif
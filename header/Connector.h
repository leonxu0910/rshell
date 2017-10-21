#ifndef __CONNECTOR_H__
#define __CONNECTOR_H__
#include "ShellComponent.h"

class Connector : public ShellComponent {
    private:
        bool status;
    protected:
        Connector(bool s) : status(s) {}
    
};

#endif
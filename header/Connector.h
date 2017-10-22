#ifndef __CONNECTOR_H__
#define __CONNECTOR_H__
#include "ShellComponent.h"

class Connector : public ShellComponent {
    public:
        bool status;
        Connector() : ShellComponent() {
            status = true;
        }
    private:
        virtual bool execute() = 0;
};

#endif
#ifndef __CONNECTOR_H__
#define __CONNECTOR_H__
#include "ShellComponent.h"

class Connector : public ShellComponent {
  protected:
    ShellComponent* next;
    
  public:
    Connector(ShellComponent* component = 0) : ShellComponent() {
        this->next = component;
        status = -1;
    }
    virtual void execute() = 0;
};

#endif
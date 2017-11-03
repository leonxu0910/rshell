#ifndef __CONNECTOR_H__
#define __CONNECTOR_H__
#include "ShellComponent.h"

class Connector : public ShellComponent {
  protected:
    ShellComponent* next; // the command following the connector
    
  public:
    Connector(ShellComponent* component = 0) : ShellComponent() {
        this->next = component;
        status = -1;
    }
    virtual ~Connector() {}
    virtual void execute() = 0;
};

#endif
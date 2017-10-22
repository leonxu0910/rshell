#ifndef __CONNECTOR_H__
#define __CONNECTOR_H__
#include "ShellComponent.h"

class Connector : public ShellComponent {
  protected:
    bool status;
    
  public:
    Connector() : ShellComponent() {
        status = false;
    }
    void setStatus(bool done) {
        this->status = done;
    }
    virtual bool execute() = 0;
};

#endif
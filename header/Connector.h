#ifndef __CONNECTOR_H__
#define __CONNECTOR_H__
#include "ShellComponent.h"

class Connector : public ShellComponent {
  protected:
    ShellComponent* prev; // the command in front of the connector
    ShellComponent* next; // the command following the connector
    
  public:
    Connector() : ShellComponent() {
        this->prev = 0;
        this->next = 0;
        status = -1;
    }
    void setLeft(ShellComponent* left) {
        prev = left;
    }
    void setRight(ShellComponent* right) {
        next = right;
    }
    ShellComponent* getLeft() const {
        return prev;
    }
    ShellComponent* getRight() const {
        return next;
    }
    virtual ~Connector() {}
    virtual void execute() = 0;
};

#endif
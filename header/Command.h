#ifndef __COMMAND_H__
#define __COMMAND_H__
#include "ShellComponent.h"
#include <string>
#include <vector>

class Command : public ShellComponent {
  protected:
    std::vector<std::string> argsVec;

  public:
    Command(std::vector<std::string> v) : ShellComponent() {
        this->argsVec = v;
    }
    virtual ~Command() {}
    virtual void execute() = 0;
    
};

#endif
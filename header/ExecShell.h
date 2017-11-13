#ifndef __EXECSHELL__
#define __EXECSHELL__
#include <queue>
#include <string>
#include "ShellComponent.h"

class ExecShell {
  private:
    ShellComponent* shellTree;
    
  public:
    ExecShell();
    ~ExecShell();
    void execute(std::string);
    
  private:
    void parseLine(std::string);
    
    
};

#endif
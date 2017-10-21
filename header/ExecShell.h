#ifndef __EXECSHELL__
#define __EXECSHELL__
#include <queue>
#include <string>
#include "ShellComponent.h"

class ExecShell {
  private:
    std::string userInput;
    std::queue<ShellComponent*> cmdQ;
    
  public:
    ExecShell();
    ExecShell(std::string input);
    void execute();
    
  private:
    void parseLine();
    
    
};

#endif
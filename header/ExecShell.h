#ifndef __EXECSHELL__
#define __EXECSHELL__
#include <queue>
#include "ShellComponent.h"

class ExecShell {
  private:
    string userInput;
    std::queue<ShellComponent*> cmdQ;
    
  public:
    ExecShell();
    ExecShell(string input);
    void execute();
    
  private:
    void parseLine();
    
    
}

#endif
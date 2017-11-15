#ifndef __EXECSHELL__
#define __EXECSHELL__
#include <vector>
#include <string>
#include "ShellComponent.h"

class ExecShell {
  private:
    ShellComponent* shellTree;
    
  public:
    ExecShell();
    ~ExecShell();
    
    /*
      Take user input and execute the command
    */
    void execute(std::string);
    
  private:
    /*
      Parse user input into program readable format
    */
    void parseLine(std::string);
    
    /*
      The initial user input is infix. Return postfix for building tree
    */
    std::vector<std::vector<std::string> > infixToPostfix(std::vector<std::vector<std::string> >);
    
    /*
      Construct the tree using postfix notation
    */
    void buildTree(std::vector<std::vector<std::string> >);
    
    
};

#endif
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
      Take the user input and execute a tree of command
    */
    void execute(std::string);
    
  private:
    /*
      Parse the user input into program readable format
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
    
    bool isCharOperator(char c);
    
    bool isOperator(std::string str);
    
    int getPrecedence(std::vector<std::string> str);
    
};

#endif
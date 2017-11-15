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
    
    
    /*
      Count number of quotes in command and return true if there are a balanced
      (even) number of quotes and false if not.
    */
    
    bool quoteCheck(std::string);

    /*
      Count number of parantheses in command and return true if there a balanced
      (even) number of parantheses and false if not.
    */
    bool paranthesesCheck(std::string);

    /*
      Count number of brackets in command and return true if there are a balanced
      (even) number of brackets and false if not.
    */
    bool bracketCheck(std::string);
    
    bool isCharOperator(char c);
    
    bool isOperator(std::string str);
    
    int getPrecedence(std::vector<std::string> str);
    
};

#endif
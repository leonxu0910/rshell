#ifndef __EXIT_H__
#define __EXIT_H__
#include "Command.h"

class Exit : public Command {
  public:
    Exit(std::vector<std::string> v) : Command(v) {}
    bool execute();
    
    
};

#endif
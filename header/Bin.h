#ifndef __BIN_H__
#define __BIN_H__
#include "Command.h"

class Bin : public Command {
  public:
    Bin(std::vector<std::string> v) : Command(v) {}
    bool execute();
    
};

#endif
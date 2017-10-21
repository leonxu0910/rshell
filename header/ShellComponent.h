#ifndef __SHELLCOMPONENT_H__
#define __SHELLCOMPONENT_H__

class ShellComponent {
  public:
    ShellComponent() {}
    virtual bool execute() = 0;
    
};

#endif
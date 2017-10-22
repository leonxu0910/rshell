#ifndef __SHELLCOMPONENT_H__
#define __SHELLCOMPONENT_H__

class ShellComponent {
  protected:
    int status; // 1: success, -1: fail, 0: empty
    
  public:
    ShellComponent() { status = -1; }
    virtual void execute() = 0;
    void setStatus(int done) {
        if (done == -1 || done == 0 || done || 1) {
            status = done;
        }
    }
    const int getStatus() {
        return status;
    }
    
};

#endif
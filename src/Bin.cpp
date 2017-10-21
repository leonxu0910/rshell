#include "../header/Bin.h"
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <vector>
#include <string>
using std::vector;
using std::string;

bool Bin::execute() {
    bool done = true;
    char* args[argsVec.size()+1];
    
    for (unsigned i = 0; i < argsVec.size(); i++) {
        args[i] = (char*)argsVec.at(i).c_str();
    }
    args[argsVec.size()] = NULL;
    
    pid_t pid = fork();
    
    if (pid == 0) {
        //cout << "child: " << pid << endl;
        if (execvp(args[0], args) == -1) {
            done = false;
            perror("exec");
        }
    }
    if (pid > 0) {
        if (wait(0) == -1) {
            perror("wait");
        }
        //cout << "parent" << pid << endl;
    }
    
    return done;
}
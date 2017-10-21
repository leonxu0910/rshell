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
    bool done = true;   // return value
    char* args[argsVec.size()+1];
    
    // Convert string to char* in argsVec
    for (unsigned i = 0; i < argsVec.size(); i++) {
        args[i] = (char*)argsVec.at(i).c_str();
    }
    args[argsVec.size()] = NULL;
    
    pid_t pid = fork(); // initialize pid
    
    if (pid == 0) {     // child process
        //cout << "child: " << pid << endl;
        //cout << endl << argsVec.at(0) << ": " << endl;
        if (execvp(args[0], args) == -1) {
            perror("exec");
        }
    }
    if (pid > 0) {      // parent process
        int status;
        waitpid(pid, &status, 0);

        if (status > 0) {   
            done = false;
        }
        else if (WEXITSTATUS(status) == 0) {
            done = true;
        }
        else if (WEXITSTATUS(status) == 1) {
            done = false;
        }
        //cout << "parent: " << pid << endl;
    }
    
    return done;
}
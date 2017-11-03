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

    
void Bin::execute() {
    if (argsVec.empty()) {  // no command (reaches the end)
        status = 0;
        return;
    }
    if (argsVec.at(0) == "exit") {  // exit command
        exit(0);
    }
    
    status = 1;
    vector<char*> args;
    args.resize(argsVec.size()+1);
    
    // Convert string to char* in argsVec
    for (unsigned i = 0; i < argsVec.size(); i++) {
        args[i] = (char*)argsVec.at(i).c_str();
    }
    args[argsVec.size()] = NULL;
    
    pid_t pid = fork(); // initialize pid
    
    if (pid == -1) {
        //fork failed to execute
        perror("fork");
        exit(1);
    }
    if (pid == 0) {     // child process
        //cout << "child: " << pid << endl;
        //cout << endl << argsVec.at(0) << ": " << endl;
        if (execvp(args[0], args.data()) == -1) {
            perror("exec");
            exit(1);
        }
    }
    if (pid > 0) {      // parent process
        int flag;
        waitpid(pid, &flag, 0);

        if (flag > 0) {   
            status = -1;
        }
        else if (WEXITSTATUS(flag) == 0) {
            status = 1;
        }
        else if (WEXITSTATUS(flag) == 1) {
            status = -1;
        }
        //cout << "parent: " << pid << endl;
    }
}
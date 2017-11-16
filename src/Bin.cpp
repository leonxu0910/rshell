#include "../header/Bin.h"
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <vector>
#include <string>
using std::vector;
using std::string;
using std::cout;
using std::endl;

    
void Bin::execute() {
    if (argsVec.empty()) {  // no command (reaches the end)
        status = 0;
        return;
    }
    if (argsVec.front() == "exit") {  // exit command
        exit(0);
    }
    if (argsVec.front().front() == '[' && argsVec.back().back() == ']') {
        vector<string> newArgs;
        argsVec.front().erase(0, 1);
        argsVec.back().pop_back();
        newArgs.push_back("[");
        for (unsigned i = 0; i < argsVec.size(); i++) {
            if (argsVec.at(i) != "") {
                newArgs.push_back(argsVec.at(i));
            }
        }
        newArgs.push_back("]");
        argsVec = newArgs;
        
    } 
    if (argsVec.front() == "test" || argsVec.front() == "[") {  // test command
        char* path_char;
        bool is_flag = true;
        
        // Check if the input is valid
        if (argsVec.front() == "[" && argsVec.back() == "]" && argsVec.size() > 2) {
            if (argsVec.size() == 3) {
                is_flag = false;
                path_char = (char*)argsVec.at(1).c_str();
            }
            else if (argsVec.size() == 4 && (argsVec.at(1) == "-e" || argsVec.at(1) == "-f" || argsVec.at(1) == "-d")) {
                path_char = (char*)argsVec.at(2).c_str();
            }
            else {
                status = -1;
                cout << "error: invalid input" << endl;
                return;
            }
        }
        else if (argsVec.front() == "test" && argsVec.size() > 1) {
            if (argsVec.size() == 2) {
                is_flag = false;
                path_char = (char*)argsVec.at(1).c_str();
            }
            else if (argsVec.at(1) == "-e" || argsVec.at(1) == "-f" || argsVec.at(1) == "-d") {
                path_char = (char*)argsVec.at(2).c_str();
            }
            else {
                status = -1;
                cout << "error: invalid input" << endl;
                return;
            }
        }
        else {
            status = -1;
            cout << "error: invalid input" << endl;
            return;
        }
        // Perform stat() command
        struct stat buf;
        if (stat(path_char, &buf) == 0) {
            if (argsVec.at(1) == "-e" || !is_flag) {    // check file existance
                status = 1;
                cout << "(true)" << endl;
            }
            else if (S_ISREG(buf.st_mode) != 0 && argsVec.at(1) == "-f") {  // check regular file
                status = 1;
                cout << "(true)" << endl; 
            }
            else if (S_ISDIR(buf.st_mode) != 0 && argsVec.at(1) == "-d") {  // check directory
                status = 1;
                cout << "(true)" << endl;
            }
            else {
                status = -1;
                cout << "(false)" << endl;
            }
        }
        else {
            status = -1;
            cout << "(false)" << endl;
        }
        return;
    }
    
    // Regular bin command
    status = 1;
    vector<char*> args;
    args.resize(argsVec.size()+1);
    
    // Convert string to char* in argsVec
    for (unsigned i = 0; i < argsVec.size(); i++) {
        args[i] = (char*)argsVec.at(i).c_str();
    }
    args[argsVec.size()] = NULL;
    
    pid_t pid = fork(); // initialize pid
    
    if (pid == -1) {    // fork failed
        perror("fork");
        exit(1);
    }
    if (pid == 0) {     // child process
        if (execvp(args[0], args.data()) == -1) {
            perror("exec");
            exit(1);
        }
    }
    if (pid > 0) {      // parent process
        int flag;
        waitpid(pid, &flag, 0);

        if (flag > 0) {   // execute failed
            status = -1;
        }
        else if (WEXITSTATUS(flag) == 0) {
            status = 1;
        }
        else if (WEXITSTATUS(flag) == 1) {  // execute failed
            status = -1;
        }
    }
}
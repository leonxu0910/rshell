#include "../header/ExecShell.h"
#include "../header/Bin.h"
#include "../header/And.h"
#include "../header/Or.h"
#include "../header/Semicolon.h"
#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::endl;

ExecShell::ExecShell() {}

void ExecShell::execute(string userInput) {
    this->parseLine(userInput);
    
    ShellComponent* exec = 0;
    while (!cmdQ.empty()) {
        exec = cmdQ.front();
        cmdQ.pop();
        exec->execute();
        if (!cmdQ.empty()) {
            cmdQ.front()->setStatus(exec->getStatus());
        }
    }
    
    
}

void ExecShell::parseLine(string userInput) {
    vector<string> vToken;
    std::size_t findComment = userInput.find("#");
    
    // Ignore everything after comment sign
    if(findComment != string::npos) {
        userInput = userInput.substr(0, findComment);
    }
    
    char* cstr = new char [userInput.length() + 1];
    cstr = strcpy(cstr, userInput.c_str());
    char* tok = strtok(cstr, " ");
    
    while(tok != NULL) {
        string element = tok;
        string semiColon = "";
        if(element.at(element.size()-1) == ';') {
            element = element.substr(0, element.size()-1);
            semiColon = ";";
        }
        vToken.push_back(element);
        if(semiColon == ";") {
            vToken.push_back(semiColon);
        }
        tok = strtok(NULL, " ");
    }
    
    // test
    // for(unsigned i = 0; i < vToken.size(); ++i) {
    //     cout << vToken.at(i) << " " << std::endl;
    // }
    
    // Insert shell command from vector to queue
    vector<string> temp;
    string buffer = "";
    for (unsigned i = 0; i < vToken.size(); ++i) {
        if (buffer == "" && !(vToken.at(i) == "||" || vToken.at(i) == "&&" || vToken.at(i) == ";")) {
            temp.push_back(vToken.at(i));
        }
        else {
            if (buffer == "") {
                cmdQ.push(new Bin(temp));
                buffer = vToken.at(i);
                temp.clear();
            }
            if (buffer != "") {
                unsigned offset = 0;
                for (unsigned j = i+1; j < vToken.size(); ++j) {
                    if (!(vToken.at(j) == "||" || vToken.at(j) == "&&" || vToken.at(j) == ";")) {
                        temp.push_back(vToken.at(j));
                        offset++;
                    }
                    else {
                        break;
                    }
                }
                
                if (vToken.at(i) == "||") {
                    cmdQ.push(new Or(new Bin(temp)));
                    buffer = "||";
                }
                else if (vToken.at(i) == "&&") {
                    cmdQ.push(new And(new Bin(temp)));
                    buffer = "&&";
                } 
                else if (vToken.at(i) == ";") {
                    cmdQ.push(new Semicolon(new Bin(temp)));
                    buffer = ";";
                }
                i += offset;
            }
        }
        
        if (buffer != "") {
            temp.clear();
        }
    }
    
    if (buffer == "" && !temp.empty()) {
        cmdQ.push(new Bin(temp));
    }
}

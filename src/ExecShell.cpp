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

ExecShell::ExecShell() { this->userInput = ""; }

ExecShell::ExecShell(string input) {
    this->userInput = input;
}

void ExecShell::execute() {
    this->parseLine();
}

void ExecShell::parseLine() {
    vector<string> vToken;
    std::size_t found = userInput.find("#");
    if(found != string::npos) {
        userInput = userInput.substr(0, found);
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
    for(int i = 0; i < vToken.size(); ++i) {
        cout << vToken.at(i) << " " << std::endl;
    }
    
    vector<string> temp;
    for(i = 0; i < vToken.size(); ++i) {
        
    }
    
    
    
    
    
}
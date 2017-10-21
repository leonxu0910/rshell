#include "../header/ExecShell.h"
#include <string>
#include <vector>
#include <cstring>

using std::string;
using std::vector;

ExecShell::ExecShell() { this->userInput = ""; }

ExecShell::ExecShell(string input) {
    this->userInput = input;
}

void ExecShell::execute() {
    
}

void ExecShell::parseLine() {
    vector<string> vToken;
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
}
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
using std::queue;
using std::cout;
using std::endl;

ExecShell::ExecShell() {}
ExecShell::~ExecShell() {}

void ExecShell::execute(string userInput) {
    this->parseLine(userInput);
    
    // Pop the queue and execute each command
    ShellComponent* exec = 0;
    while (!cmdQ.empty()) {
        exec = cmdQ.front();
        cmdQ.pop();
        exec->execute();    // execute command
        if (!cmdQ.empty()) {
            cmdQ.front()->setStatus(exec->getStatus()); // set status from previous command
        }
        delete exec;
        exec = 0;
    }
    exec = 0;
    
}

void ExecShell::parseLine(string userInput) {
    vector<string> vToken;
    std::size_t findComment = userInput.find("#");
    
    // Ignore everything after comment sign
    if (findComment != string::npos) {
        userInput = userInput.substr(0, findComment);
    }
    
    char* cstr = new char [userInput.length() + 1];
    cstr = strcpy(cstr, userInput.c_str());
    char* tok = strtok(cstr, " ");
    
    // Add tokens to vector
    while (tok != NULL) {
        string element = tok;
        string semiColon = "";
        string quote = "";
        if (element.at(element.size()-1) == ';') {
            element = element.substr(0, element.size()-1);
            semiColon = ";";
        }
        if (element.at(0) == '\"') {
            element = element.substr(1, element.size());
            vToken.push_back("\"");
        }
        if (element.at(element.size()-1) == '\"') {
            element = element.substr(0, element.size()-1);
            quote = "\"";
        }
        vToken.push_back(element);
        if (quote == "\"") {
            vToken.push_back(quote);
        }
        if (semiColon == ";") {
            vToken.push_back(semiColon);
        }
        tok = strtok(NULL, " ");
    }
    delete[] cstr;
    cstr = 0;
    tok = 0;
    
    // Insert shell command from vector to queue
    vector<string> temp;
    string buffer = "";
    bool isQuote = false;
    for (unsigned i = 0; i < vToken.size(); i++) {
        if (isQuote == false && (vToken.at(i) == "||" || vToken.at(i) == "&&" || vToken.at(i) == ";")) {
            if (buffer == "") { // first command
                cmdQ.push(new Bin(temp));
                temp.clear();
            }
            else if (buffer == "&&") {  // command after and
                cmdQ.push(new And(new Bin(temp)));
                temp.clear();
            }
            else if (buffer == "||") {  // command after or
                cmdQ.push(new Or(new Bin(temp)));
                temp.clear();
            }
            else if (buffer == ";") {   // command after semicolon
                cmdQ.push(new Semicolon(new Bin(temp)));
                temp.clear();
            }
            buffer = vToken.at(i);
        }
        else {
            if (vToken.at(i) == "\"" && isQuote == false) { // if command is in the quote
                isQuote = true;
            }
            else if (vToken.at(i) == "\"" && isQuote == true) { // quote ends
                isQuote = false;
            }
            else {
                temp.push_back(vToken.at(i));
            }
            
        }
    }
    if (buffer == "" && !temp.empty()) { // single command
        cmdQ.push(new Bin(temp));
        temp.clear();
    }
    if (!temp.empty()) {    // last command
        if (buffer == "&&") {
            cmdQ.push(new And(new Bin(temp)));
        }
        else if (buffer == "||") {
            cmdQ.push(new Or(new Bin(temp)));
        }
        else if (buffer == ";") {
            cmdQ.push(new Semicolon(new Bin(temp)));
        }
        temp.clear();
    }
}

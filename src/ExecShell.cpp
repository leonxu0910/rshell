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
}

void ExecShell::parseLine(string userInput) {
    cout << "call parseLine" << endl;
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
    for(unsigned i = 0; i < vToken.size(); ++i) {
        cout << vToken.at(i) << " " << std::endl;
    }
    
    // Insert shell command from vector to queue
    vector<string> temp;
    string buffer = "";
    Bin* newBin = 0;
    for (unsigned i = 0; i < vToken.size(); ++i) {
        if (!(vToken.at(i) == "||" || vToken.at(i) == "&&" || vToken.at(i) == ";")) {
            temp.push_back(vToken.at(i));
        }
        else {
            if (buffer == "") {
                newBin = new Bin(temp);
                cmdQ.push(newBin);
                buffer = vToken.at(i);
            }
            else {
                for (unsigned j = i+1; j < vToken.size(); ++j) {
                    if (!(vToken.at(j) == "||" || vToken.at(j) == "&&" || vToken.at(j) == ";")) {
                        temp.push_back(vToken.at(j));
                    }
                }
                
                newBin = new Bin(temp);
                if(vToken.at(i) == "||") {
                    Or* newOr = new Or(newBin);
                    cmdQ.push(newOr);
                    buffer = "||";
                }
                else if (vToken.at(i) == "&&") {
                    And* newAnd = new And(newBin);
                    cmdQ.push(newAnd);
                    buffer = "&&";
                } 
                else if (vToken.at(i) == ";") {
                    Semicolon* newSemi = new Semicolon(newBin);
                    cmdQ.push(newSemi);
                    buffer = ";";
                }
            }
        }
        
        if (buffer != "") {
            temp.clear();
        }
        newBin = 0;
    }
}
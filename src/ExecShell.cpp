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

ExecShell::ExecShell() {
    shellTree = 0;
}
ExecShell::~ExecShell() {
    delete shellTree;
    shellTree = 0;
}

void ExecShell::execute(string userInput) {
    this->parseLine(userInput);
    
    shellTree->execute();
    delete shellTree;
    shellTree = 0;
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
    
    // test
    // for(unsigned i = 0; i < vToken.size(); ++i) {
    //     cout << vToken.at(i) << " " << endl;
    // }
    // cout << "-----------------------------------" << endl;
    
    // Insert shell command from vector to queue
    vector<vector<string> > shellVec;
    vector<string> temp;
    vector<string> temp_cnt;
    string buffer = "";
    bool isQuote = false;
    for (unsigned i = 0; i < vToken.size(); i++) {
        if (isQuote == false && (vToken.at(i) == "||" || vToken.at(i) == "&&" || vToken.at(i) == ";")) {
            if (buffer == "") { // first command
                shellVec.push_back(temp);
                temp.clear();
            }
            else {
                if (buffer == "&&") {  // command after and
                    temp_cnt.push_back("&&");
                }
                else if (buffer == "||") {  // command after or
                    temp_cnt.push_back("||");
                }
                else if (buffer == ";") {   // command after semicolon
                    temp_cnt.push_back(";");
                }
                shellVec.push_back(temp_cnt);
                shellVec.push_back(temp);
                temp_cnt.clear();
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
        shellVec.push_back(temp);
        temp.clear();
    }
    if (!temp.empty()) {    // last command
        if (buffer == "&&") {
            temp_cnt.push_back("&&");
        }
        else if (buffer == "||") {
            temp_cnt.push_back("||");
        }
        else if (buffer == ";") {
            temp_cnt.push_back(";");
        }
        shellVec.push_back(temp_cnt);
        shellVec.push_back(temp);
        temp.clear();
    }
    if (vToken.at(vToken.size()-1) == "&&") {
        temp_cnt.push_back("&&");
        shellVec.push_back(temp_cnt);
    }
    else if (vToken.at(vToken.size()-1) == "||") {
        temp_cnt.push_back("||");
        shellVec.push_back(temp_cnt);
    }
    else if (vToken.at(vToken.size()-1) == ";") {
        temp_cnt.push_back(";");
        shellVec.push_back(temp_cnt);
    }
    
    // test
    // for (unsigned i = 0; i < shellVec.size(); i++) {
    //     for (unsigned j = 0; j < shellVec.at(i).size(); j++) {
    //         cout << shellVec.at(i).at(j) << " ";
    //     }
    //     cout << endl;
    // }
    
    Bin* bin = 0;
    Connector* cnt = 0;
    Connector* root = 0;
    string cnt_tok = "";
    if (shellVec.size() == 1) {
        shellTree = new Bin(shellVec.at(0));
        return;
    }
    else {
        for (unsigned i = 0; i < shellVec.size(); i++) {
            if (i == 0) {
                bin = new Bin(shellVec.at(i));
            }
            else {
                if (bin != 0) {
                    if (shellVec.at(i).at(0) == "&&") {
                        cnt = new And(bin, 0);
                        cnt_tok = "&&";
                    }
                    else if (shellVec.at(i).at(0) == "||") {
                        cnt = new Or(bin, 0);
                        cnt_tok = "||";
                    }
                    else if (shellVec.at(i).at(0) == ";") {
                        cnt = new Semicolon(bin, 0);
                        cnt_tok = ";";
                    }
                    root = cnt;
                    cnt = 0;
                    bin = 0;
                }
                else if (cnt_tok != "") {
                    root->setRight(new Bin(shellVec.at(i)));
                    cnt_tok = "";
                }
                else {
                    if (shellVec.at(i).at(0) == "&&") {
                        cnt = new And(root, 0);
                        cnt_tok = "&&";
                    }
                    else if (shellVec.at(i).at(0) == "||") {
                        cnt = new Or(root, 0);
                        cnt_tok = "||";
                    }
                    else if (shellVec.at(i).at(0) == ";") {
                        cnt = new Semicolon(root, 0);
                        cnt_tok = ";";
                    }
                    root = cnt;
                    cnt = 0;
                }
                
            }
        }
        shellTree = root;
        root = 0;
        cnt = 0;
        bin = 0;
    }
}

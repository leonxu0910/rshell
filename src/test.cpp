#include <iostream>
#include "../header/ExecShell.h"

using std::cin;
using std::string;


int main() {
    string userInput;
    getline(cin, userInput);
    ExecShell* test = new ExecShell(userInput);
    test->execute();
    
    return 0;
}


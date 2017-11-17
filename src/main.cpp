#include <iostream>
#include "../header/ExecShell.h"
using namespace std;

int main (int argc, char *argv[]) {
    string userInput;
    ExecShell* exec = new ExecShell();
    do {
        cout << "$ ";
        getline(cin, userInput);
        exec->execute(userInput);
        
    } while (1);
    
    delete exec;
    exec = 0;
 
    return 0;
}
#include <iostream>
#include "../header/ExecShell.h"
using namespace std;

int main (int argc, char *argv[]) {
    string userInput;
    ExecShell exec;
    do {
        cout << "$ ";
        getline(cin, userInput);
        exec.execute(userInput);
        
    } while (userInput != "Exit");
 
 
    return 0;
}
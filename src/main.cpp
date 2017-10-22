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
        
    } while (1);
 
 
    return 0;
}
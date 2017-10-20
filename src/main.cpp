#include <iostream>
using namespace std;

int main (int argc, char *argv[]) {
    string userInput;
    
    do {
        cout << "$ ";
        getline(cin, userInput);
        
        
    } while (userInput != "Exit");
 
 
    return 0;   
}
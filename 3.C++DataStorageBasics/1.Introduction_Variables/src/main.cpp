#include<iostream>
using namespace std;

// Global variable
int globalVar = 100;

void displayGlobal() {
    cout << "Global variable value: " << globalVar << endl;
}

int main() {
    displayGlobal();
    globalVar = 200;
    displayGlobal();
    return 0;
}
// main.cpp

#include <iostream>   // For input-output stream operations

// Global variable (File/Global Scope)
int globalVar = 20;



int func2(int x) {
    // Local variable (Function/Local Scope)
    int localVar = 20;
    return x + localVar;
}

int func1(int x) {
    
    int localfunc1= 10;

    return func2(x) + localfunc1;
}

int main() {
 

    std::cout << "Global variable: " << globalVar << std::endl;
    std::cout << "func1: " << func1(5) << std::endl;
    return 0;
}

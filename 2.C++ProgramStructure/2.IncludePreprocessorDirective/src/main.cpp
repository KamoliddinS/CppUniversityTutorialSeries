// Including standard library header
#include <iostream>

// Including user-defined header
#include "myHeader.h"

// Definition of the function declared in myHeader.h
void greet() {
    std::cout << "Hello from the greet() function defined in myHeader.h!" << std::endl;
}

int main() {
    // Using the standard library's functionality
    std::cout << "Hello from the main function!" << std::endl;

    // Using the function from the user-defined header
    greet();

    return 0;
}
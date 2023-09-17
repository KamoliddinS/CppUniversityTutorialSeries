// Including standard library header
#include <iostream>

// Including user-defined header
#include "greeting.h"

int main() {
    // Using the standard library's functionality
    std::cout << "Hello from the main function!" << std::endl;

    // Using the function from the user-defined header and  greeting.cpp file
    greet();

    return 0;
}
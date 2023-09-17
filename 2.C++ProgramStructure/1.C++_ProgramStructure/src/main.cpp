// Including necessary headers
#include <iostream>

// Global variable declaration
int globalVariable = 10;

// Class definition
class MyClass {
    int data;
public:
    void setData(int d) {
        data = d;
    }

    int getData() {
        return data;
    }
};

// Function definition
void displayMessage() {
    std::cout << "Hello, C++!" << std::endl;
}

// Main function - the entry point of the program
int main() {
    // Local variable declaration
    int localVariable = 5;

    // Using the global variable
    std::cout << "Global Variable: " << globalVariable << std::endl;

    // Using the local variable
    std::cout << "Local Variable: " << localVariable << std::endl;

    // Calling the function
    displayMessage();

    // Using the class
    MyClass obj;
    obj.setData(20);
    std::cout << "Class Data: " << obj.getData() << std::endl;

    // Control structure example
    if (localVariable < globalVariable) {
        std::cout << "Local variable is less than global variable." << std::endl;
    } else {
        std::cout << "Local variable is greater than or equal to global variable." << std::endl;
    }

    return 0;  // Indicating successful completion
}



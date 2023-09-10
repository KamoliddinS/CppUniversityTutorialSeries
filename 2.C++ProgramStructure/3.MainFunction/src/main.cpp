#include <iostream>

// Function to demonstrate calling from within the program
void displayArguments(int argc, char* argv[]) {
    std::cout << "Number of arguments: " << argc << std::endl;
    std::cout << "Arguments are:" << std::endl;
    for (int i = 0; i < argc; i++) {
        std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
    }
}

// Main function with command-line arguments
int main(int argc, char* argv[]) {
    std::cout << "Starting the program..." << std::endl;

    // Displaying command-line arguments
    displayArguments(argc, argv);

    std::cout << "Ending the program..." << std::endl;

    // Return 0 to indicate successful execution
    return 0;
}

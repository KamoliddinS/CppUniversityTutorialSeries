#include <iostream>

// Function prototypes for the arithmetic operations
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b == 0) {
        std::cout << "Error: Division by zero is undefined." << std::endl;
        return 0;
    }
    return a / b;
}

int main() {
    // Array of function pointers
    int (*operations[4])(int, int) = {add, subtract, multiply, divide};

    int choice, x, y;
    bool running = true;

    while (running) {
        std::cout << "Select the arithmetic operation:" << std::endl;
        std::cout << "1. Add" << std::endl;
        std::cout << "2. Subtract" << std::endl;
        std::cout << "3. Multiply" << std::endl;
        std::cout << "4. Divide" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cin >> choice;

        if (choice == 5) {
            running = false;
            continue;
        }

        if (choice < 1 || choice > 4) {
            std::cout << "Invalid choice. Please try again." << std::endl;
            continue;
        }

        std::cout << "Enter two numbers: ";
        std::cin >> x >> y;

        // Call the selected function via the function pointer array
        int result = (*operations[choice - 1])(x, y);
        std::cout << "Result: " << result << std::endl;
    }

    return 0;
}

#include <iostream>

// Define a few functions to point to
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
    // Ensure we don't divide by zero
    if(b == 0) {
        std::cerr << "Error: Division by zero!" << std::endl;
        return 0;
    }
    return a / b;
}

// This function will take a function pointer and use it
void useFunctionPointer(int (*operation)(int, int), int a, int b) {
    std::cout << "The result of the operation is: " << operation(a, b) << std::endl;
}

int main() {
    // Declare and assign a function pointer for 'add' function
    int (*operation_ptr)(int, int) = add;
    std::cout << "Using the 'add' function through a pointer: " << operation_ptr(5, 3) << std::endl;

    // Point to the 'subtract' function and use it
    operation_ptr = subtract;
    std::cout << "Using the 'subtract' function through a pointer: " << operation_ptr(5, 3) << std::endl;

    // You can also assign and use the pointer directly
    useFunctionPointer(multiply, 4, 3);

    // Or pass in an array of function pointers
    int (*operations[4])(int, int) = {add, subtract, multiply, divide};

    // Iterate over the array and use each function
    for (auto& func : operations) {
        useFunctionPointer(func, 10, 5);
    }

    return 0;
}

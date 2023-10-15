// main.cpp

#include <iostream>   // For input-output stream operations

// Recursive function to calculate factorial of a number
int factorial(int n) {
    // Base case
    if (n <= 1) return 1;
    
    // Recursive case
    return n * factorial(n-1);
}

// Recursive function to generate nth Fibonacci number
int fibonacci(int n) {
    // Base cases
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    // Recursive case
    return fibonacci(n-1) + fibonacci(n-2);
}

// Function to demonstrate direct recursion by a function calling itself
void directRecursion(int count) {
    if (count <= 0) return;  // Base case
    std::cout << "Direct Recursion Call: " << count << std::endl;
    directRecursion(count-1);  // Recursive call
}

int main() {
    // Introduction
    std::cout << "Demonstrating Recursive Functions in C++\n" << std::endl;

    // Factorial example
    int num = 5;
    std::cout << "Factorial of " << num << ": " << factorial(num) << "\n" << std::endl;

    // Fibonacci example
    int fib_index = 7;
    std::cout << fib_index << "th Fibonacci number: " << fibonacci(fib_index) << "\n" << std::endl;

    // Direct Recursion example
    directRecursion(3);

    return 0;
}
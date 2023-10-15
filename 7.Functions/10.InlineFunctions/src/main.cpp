// main.cpp

#include <iostream>   // For input-output stream operations

// Inline function declaration and definition
inline int add(int a, int b) {
    return a + b;
}

inline int square(int n) {
    return n * n;
}

// A function that's not suitable for inlining due to its size
inline void largeFunction() {
    for (int i = 0; i < 1000; i++) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Introduction
    std::cout << "Demonstrating Inline Functions in C++\n" << std::endl;

    // Simple inline function example
    int sum = add(5, 3);
    std::cout << "Sum of 5 and 3: " << sum << std::endl;  // Outputs: 8

    // Another inline function
    int result = square(5);
    std::cout << "Square of 5: " << result << std::endl;  // Outputs: 25

    // Although largeFunction is declared as inline, 
    // it's not a good candidate for inlining due to its size
    // The compiler might ignore the inline request for such functions
    std::cout << "Displaying numbers from 0 to 999:\n";
    largeFunction();

    return 0;
}

#include <iostream>

int main() {
    // Demonstrating Mixed Expressions and Implicit Type Conversion
    int a = 5;
    double b = 2.5;
    double result = a + b;  // Implicit conversion of 'a' to double
    std::cout << "Result of mixed expression (a + b): " << result << std::endl;

    // Demonstrating C-style Casting
    double c = 3.14;
    int d = (int)c;  // Explicit conversion of 'c' to int
    std::cout << "Result after C-style casting: " << d << std::endl;

    // Demonstrating Functional Casting
    double e = 3.14;
    int f = int(e);  // Explicit conversion of 'e' to int using functional style
    std::cout << "Result after functional casting: " << f << std::endl;

    // Demonstrating static_cast
    double g = 3.14;
    int h = static_cast<int>(g);  // Explicit conversion of 'g' to int using static_cast
    std::cout << "Result after static_cast: " << h << std::endl;

    return 0;
}


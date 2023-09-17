#include <iostream>

int main() {
    // Variables for demonstration
    int a = 5;
    int b = 3;

    // Addition
    int sum = a + b;
    std::cout << "The sum of " << a << " and " << b << " is: " << sum << std::endl;

    // Subtraction
    int difference = a - b;
    std::cout << "The difference between " << a << " and " << b << " is: " << difference << std::endl;

    // Multiplication
    int product = a * b;
    std::cout << "The product of " << a << " and " << b << " is: " << product << std::endl;

    // Division (integer division)
    int quotient = a / b;
    std::cout << "The quotient of " << a << " divided by " << b << " (integer division) is: " << quotient << std::endl;

    // Division (floating-point division)
    float a_float = static_cast<float>(a); // we use static_cast to convert a to a float
    float b_float = static_cast<float>(b);
    float quotient_float = a_float / b_float;
    std::cout << "The quotient of " << a << " divided by " << b << " (floating-point division) is: " << quotient_float << std::endl;

    // Modulus
    int remainder = a % b;
    std::cout << "The remainder of " << a << " divided by " << b << " is: " << remainder << std::endl;

    return 0;
}

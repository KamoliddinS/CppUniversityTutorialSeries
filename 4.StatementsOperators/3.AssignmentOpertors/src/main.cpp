
#include <iostream>

int main() {
    // Variables for demonstration
    int a, b;

    // Assign (=)
    a = 10;
    std::cout << "After assignment, a = " << a << std::endl;

    // Add and Assign (+=)
    a += 5;  // equivalent to a = a + 5;
    std::cout << "After add and assign, a = " << a << std::endl;

    // Subtract and Assign (-=)
    a -= 3;  // equivalent to a = a - 3;
    std::cout << "After subtract and assign, a = " << a << std::endl;

    // Multiply and Assign (*=)
    a *= 2;  // equivalent to a = a * 2;
    std::cout << "After multiply and assign, a = " << a << std::endl;

    // Divide and Assign (/=)
    a /= 4;  // equivalent to a = a / 4;
    std::cout << "After divide and assign, a = " << a << std::endl;

    // Modulus and Assign (%=)
    b = 15;
    b %= 4;  // equivalent to b = b % 4;
    std::cout << "After modulus and assign, b = " << b << std::endl;

    return 0;
}

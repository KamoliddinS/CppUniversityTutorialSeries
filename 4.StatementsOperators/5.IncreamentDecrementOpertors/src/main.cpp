#include <iostream>

int main() {
    // Variables for demonstration
    int a, b;

    // Prefix Increment
    a = 5;
    b = ++a;
    std::cout << "After prefix increment, a = " << a << " and b = " << b << std::endl;

    // Postfix Increment
    a = 5;
    b = a++;
    std::cout << "After postfix increment, a = " << a << " and b = " << b << std::endl;

    // Prefix Decrement
    a = 5;
    b = --a;
    std::cout << "After prefix decrement, a = " << a << " and b = " << b << std::endl;

    // Postfix Decrement
    a = 5;
    b = a--;
    std::cout << "After postfix decrement, a = " << a << " and b = " << b << std::endl;

    return 0;
}

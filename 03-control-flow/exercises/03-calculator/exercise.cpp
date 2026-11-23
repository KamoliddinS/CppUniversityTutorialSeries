// Exercise 3: Calculator
// Reads a whole number, an operator and another whole number, for example
//     7 * 6
// and prints the result. The case for + is done. Complete the other cases.
#include <iostream>

int main() {
    int a = 0;
    int b = 0;
    char op = ' ';
    std::cin >> a >> op >> b;

    switch (op) {
    case '+':
        std::cout << a + b << '\n';
        break;
    // TODO: add a case for '-'.
    // TODO: add one block for '*' and 'x'. Both mean "times".
    // TODO: add a case for '/'. When b is 0, print: Cannot divide by zero
    default:
        // TODO: print: Unknown operator
        break;
    }
}

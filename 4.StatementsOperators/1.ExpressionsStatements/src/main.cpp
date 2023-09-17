#include <iostream>

int main() {
    // Introduction
    std::cout << "C++ Statements and Expressions\n";
    std::cout << "==============================\n\n";

    // Expression: It evaluates to a value and does not necessarily cause any side effect.
    int x = 5;  // '5' is an expression that evaluates to the value 5.
    int y = x + 3;  // 'x + 3' is an expression that evaluates to the value 8.

    std::cout << "Expressions:\n";
    std::cout << "x = " << x << "\n";  // '<<' is an operator, and the whole is an expression.
    std::cout << "y = x + 3 = " << y << "\n\n";

    // Statement: It performs an action and typically consists of an expression followed by a semicolon.
    x = 10;  // This is a statement. It assigns the value 10 to x.
    if (y > x) {  // This is a statement. It's an if statement that checks a condition.
        std::cout << "y is greater than x.\n";  // This is also a statement.
    } else {
        std::cout << "y is not greater than x.\n";  // This is also a statement.
    }

    std::cout << "\nStatements:\n";
    std::cout << "x = 10;  // This is a statement.\n";
    std::cout << "if (y > x) { ... }  // This is a statement.\n";

    return 0;  // This is a return statement.
}


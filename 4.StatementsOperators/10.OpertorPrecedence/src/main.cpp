#include <iostream>

namespace MyNamespace {
    int x = 10;
}

int main() {
    // Example 1: Scope resolution
    int x = MyNamespace::x;  // Uses the scope resolution operator
    std::cout << "Value of x using scope resolution: " << x << std::endl;

    // Example 2: Postfix vs Prefix
    int a = 5;
    int b = a++;  // b = 5, a = 6
    int c = ++a;  // c = 7, a = 7
    std::cout << "Postfix increment: b = " << b << ", a = " << a << std::endl;
    std::cout << "Prefix increment: c = " << c << ", a = " << a << std::endl;

    // Example 3: Multiplication before Addition
    int result = 3 + 4 * 2;  // result = 11, not 14
    std::cout << "Multiplication before addition: " << result << std::endl;

    // Example 4: Logical AND before Logical OR
    bool logicResult = true || false && false;  // result = true, because && has higher precedence than ||
    std::cout << "Logical AND before OR: " << logicResult << std::endl;

    // Example 5: Using Parentheses to Override Precedence
    int overriddenResult = (3 + 4) * 2;  // result = 14, parentheses override the default precedence
    std::cout << "Using parentheses to override precedence: " << overriddenResult << std::endl;

    return 0;
}

// Exercise 4: Calculator
// Read lines such as "6 * 7" until the input ends. Print each result on its own line.
// For an operator that is not + - or *, print: unknown operator
// Choose the operation with a function pointer (see the exercise text).
#include <iostream>

using Operation = int (*)(int, int);

// TODO: write the functions add, subtract and multiply.

// TODO: write the function
//     Operation choose(char symbol)
// It returns a pointer to the function for '+', '-' or '*',
// and nullptr for any other symbol.

int main() {
    int left = 0;
    int right = 0;
    char symbol = ' ';
    while (std::cin >> left >> symbol >> right) {
        // TODO: call choose(symbol). Print the result, or "unknown operator".
        std::cout << "TODO\n";
    }
}

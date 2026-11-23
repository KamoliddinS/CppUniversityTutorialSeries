#include <iostream>

int factorial(int n) {
    if (n <= 1) {
        return 1;                       // base case: no further call
    }
    return n * factorial(n - 1);        // recursive case: a smaller problem
}

int main() {
    std::cout << "3! = " << factorial(3) << '\n';
    std::cout << "5! = " << factorial(5) << '\n';
}

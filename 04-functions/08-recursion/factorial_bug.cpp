#include <iostream>

int factorial(int n) {
    return n * factorial(n - 1);        // no base case
}

int main() {
    std::cout << "3! = " << factorial(3) << '\n';
}

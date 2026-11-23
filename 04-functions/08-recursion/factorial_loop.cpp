#include <iostream>

int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    std::cout << "3! = " << factorial(3) << '\n';
    std::cout << "5! = " << factorial(5) << '\n';
}

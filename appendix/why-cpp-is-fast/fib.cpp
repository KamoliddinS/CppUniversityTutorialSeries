#include <iostream>

int fib(int n) {
    if (n < 2) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int main() {
    constexpr int n = 27;   // raise this to 35 when you measure the time
    std::cout << "fib(" << n << ") = " << fib(n) << '\n';
}

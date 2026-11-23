#include <iostream>

int twice(int x) {
    return 2 * x;
}

int square(int x) {
    return x * x;
}

int applyTwice(int (*f)(int), int value) {
    return f(f(value));
}

int main() {
    std::cout << applyTwice(twice, 3) << ' ' << applyTwice(square, 3) << '\n';
}

#include <iostream>

int difference(int a, int b) {
    return a - b;
}

int main() {
    int a = 2;
    int b = 10;
    std::cout << difference(a, b) << '\n';
    std::cout << difference(b, a) << '\n';
    std::cout << difference(b, difference(b, a)) << '\n';
}

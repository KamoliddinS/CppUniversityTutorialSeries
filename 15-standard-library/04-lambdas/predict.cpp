#include <iostream>

int main() {
    int x = 1;
    auto byCopy = [x]() { return x * 10; };
    auto byReference = [&x]() { return x * 10; };

    x = 5;
    std::cout << byCopy() << ' ' << byReference() << '\n';
}

#include <iostream>

int main() {
    std::cout << 2 + 3 * 4 << '\n';         // * before +
    std::cout << (2 + 3) * 4 << '\n';       // brackets first
    std::cout << 8 / 4 * 2 << '\n';         // left to right: (8 / 4) * 2
}

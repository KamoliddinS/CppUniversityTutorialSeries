#include <iostream>

int main() {
    int x = 50;
    bool isFive = x = 5;        // meant: x == 5
    std::cout << std::boolalpha << isFive << ' ' << x << '\n';
}

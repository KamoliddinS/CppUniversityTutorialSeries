#include <iostream>

int main() {
    int x = 50;
    bool inRange = 1 < x < 10;
    bool isFive = x = 5;
    std::cout << std::boolalpha << inRange << ' ' << isFive << '\n';
}

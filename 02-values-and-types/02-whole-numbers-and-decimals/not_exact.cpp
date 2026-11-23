#include <iostream>

int main() {
    double sum = 0.1 + 0.2;
    std::cout << sum << '\n';           // looks like 0.3
    std::cout << sum - 0.3 << '\n';     // but it is not exactly 0.3
}

#include <cmath>
#include <iostream>

int main() {
    int base = 2;
    std::cout << (base ^ 3) << '\n';            // not "2 to the power of 3"
    std::cout << std::pow(base, 3) << '\n';     // this is
}

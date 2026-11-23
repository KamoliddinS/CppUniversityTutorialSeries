#include <iomanip>
#include <iostream>

int main() {
    std::cout << std::setw(5) << 42 << 7 << '\n';
    std::cout << std::setfill('*') << std::setw(5) << 42 << std::setw(3) << 7 << '\n';
}

#include <cmath>
#include <iostream>

int main() {
    double sum = 0.1 + 0.2;

    bool equal = sum == 0.3;
    bool close = std::abs(sum - 0.3) < 0.000001;    // std::abs removes the minus sign
    std::cout << std::boolalpha << "equal: " << equal << ", close: " << close << '\n';
}

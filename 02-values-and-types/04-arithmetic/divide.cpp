#include <iostream>

int main() {
    int minutes = 135;
    std::cout << minutes / 60 << " h " << minutes % 60 << " min\n";

    std::cout << 7 / 2 << '\n';         // the fraction is cut off
    std::cout << -7 / 2 << '\n';        // cut toward zero, not down to -4
    std::cout << -7 % 2 << '\n';        // the remainder keeps the sign of -7
    std::cout << 7.0 / 2.0 << '\n';     // two doubles keep the fraction
}

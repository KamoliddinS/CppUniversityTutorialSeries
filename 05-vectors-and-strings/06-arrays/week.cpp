#include <array>
#include <iostream>

int main() {
    std::array<int, 7> visitors = {120, 95, 130, 110, 160, 240, 210};   // Monday to Sunday

    int total = 0;
    for (int count : visitors) {
        total += count;
    }
    std::cout << visitors.size() << " days, " << total << " visitors\n";
    std::cout << "Sunday: " << visitors.at(6) << '\n';

    std::array<int, 7> copy = visitors;         // copies all seven elements
    copy[0] = 0;
    std::cout << "Monday: " << visitors[0] << ", in the copy: " << copy[0] << '\n';
}

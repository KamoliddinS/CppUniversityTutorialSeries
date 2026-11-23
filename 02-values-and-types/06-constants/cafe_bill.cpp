#include <iostream>

int main() {
    // A fixed fact: known when the program is built.
    constexpr int servicePercent = 15;

    std::cout << "Bill: ";
    int bill = 0;
    std::cin >> bill;

    // Worked out from what the user types: known only when the program runs.
    const int service = bill * servicePercent / 100;

    std::cout << "Service: " << service << " so'm\n";
    std::cout << "To pay:  " << bill + service << " so'm\n";
}

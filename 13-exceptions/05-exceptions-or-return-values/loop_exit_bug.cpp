#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
    const std::vector<int> prices = {35000, 30000, 9000};
    int total = 0;
    try {
        for (std::size_t i = 0; true; ++i) {
            total += prices.at(i);      // the loop "ends" when at() throws
        }
    } catch (const std::out_of_range&) {
    }
    std::cout << "Total: " << total << " so'm\n";
}

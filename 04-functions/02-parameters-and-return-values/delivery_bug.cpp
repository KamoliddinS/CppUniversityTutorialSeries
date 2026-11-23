#include <iostream>

int deliveryFee(int amount) {
    if (amount >= 50000) {
        return 0;
    }
    // BUG: no return for a smaller amount
}

int main() {
    std::cout << deliveryFee(80000) << '\n';
    std::cout << deliveryFee(36000) << '\n';
}

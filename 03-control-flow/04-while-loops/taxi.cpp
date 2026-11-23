#include <iostream>

int main() {
    constexpr int pricePerKm = 3000;    // so'm

    while (true) {
        std::cout << "Kilometres (0 to stop): ";
        int km = 0;
        std::cin >> km;
        if (km <= 0) {
            break;                      // leave the loop from the middle
        }
        std::cout << "Fare: " << km * pricePerKm << " so'm\n";
    }
    std::cout << "Have a good trip!\n";
}

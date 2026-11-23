#include <iostream>

int main() {
    constexpr int nights = 5;
    std::cout << "Temperatures of " << nights << " nights: ";

    int warmest = 0;
    std::cin >> warmest;                // the first value is the warmest so far

    for (int night = 2; night <= nights; ++night) {
        int temperature = 0;
        std::cin >> temperature;
        if (temperature > warmest) {
            warmest = temperature;      // a warmer one: remember it
        }
    }
    std::cout << "Warmest night: " << warmest << " degrees\n";
}

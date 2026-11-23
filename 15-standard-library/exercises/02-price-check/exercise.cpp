// Exercise 2: Price check
// The program reads product names and prints the price of each one,
// then the number of products the shop sells.
// It builds and runs, but its output is wrong in two places. Fix it.
#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> prices = {{"non", 4000}, {"choy", 12000}, {"suv", 0}};

    std::string product;
    while (std::cin >> product) {
        if (prices[product] == 0) {
            std::cout << product << ": not sold here\n";
        } else {
            std::cout << product << ": " << prices[product] << " so'm\n";
        }
    }
    std::cout << prices.size() << " products\n";
}

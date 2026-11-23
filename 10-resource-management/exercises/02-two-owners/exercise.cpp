// Exercise 2: Two owners
// This program builds, but it prints wrong prices and usually crashes at the end.
// PriceList owns heap memory, and main copies it. Give the class what it
// needs to be copied correctly. Do not change main.
#include <cstddef>
#include <iostream>

class PriceList {
public:
    explicit PriceList(std::size_t count) : count_(count), prices_(new int[count]{}) {}
    ~PriceList() { delete[] prices_; }

    int& operator[](std::size_t index) { return prices_[index]; }

private:
    std::size_t count_ = 0;
    int* prices_ = nullptr;     // in so'm
};

int main() {
    PriceList shop(3);
    std::cin >> shop[0] >> shop[1] >> shop[2];
    PriceList sale = shop;          // a copy for the sale
    sale[0] -= 500;
    PriceList backup(1);
    backup = shop;                  // keep the prices as they are now
    PriceList& sameBackup = backup;
    backup = sameBackup;            // assigning an object to itself must change nothing
    shop[0] = 0;

    std::cout << "shop: " << shop[0] << ' ' << shop[1] << ' ' << shop[2] << '\n';
    std::cout << "sale: " << sale[0] << ' ' << sale[1] << ' ' << sale[2] << '\n';
    std::cout << "backup: " << backup[0] << ' ' << backup[1] << ' ' << backup[2] << '\n';
}

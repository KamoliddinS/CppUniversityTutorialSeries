#include <compare>
#include <iostream>

class Money {
public:
    Money(long long soms, long long tiyin) : amount_(soms * 100 + tiyin) {}

    bool operator==(const Money&) const = default;
    auto operator<=>(const Money&) const = default;

private:
    long long amount_ = 0;      // in tiyin: 1 so'm = 100 tiyin
};

int main() {
    Money bread(4200, 50);
    Money milk(11800, 75);
    Money coins(0, 420050);     // the same amount as bread, given in tiyin

    if (bread == coins) {
        std::cout << "bread == coins\n";
    }
    if (bread != milk) {
        std::cout << "bread != milk\n";
    }
    if (bread < milk) {
        std::cout << "bread < milk\n";
    }
    if (milk >= coins) {
        std::cout << "milk >= coins\n";
    }
}

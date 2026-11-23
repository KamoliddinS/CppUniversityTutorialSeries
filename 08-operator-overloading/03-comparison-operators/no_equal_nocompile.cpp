#include <iostream>

class Money {
public:
    Money(long long soms, long long tiyin) : amount_(soms * 100 + tiyin) {}

private:
    long long amount_ = 0;      // in tiyin: 1 so'm = 100 tiyin
};

int main() {
    Money bread(4200, 50);
    Money coins(0, 420050);     // the same amount, given in tiyin

    if (bread == coins) {
        std::cout << "The same amount.\n";
    }
}

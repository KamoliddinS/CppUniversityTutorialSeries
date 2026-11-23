#include <iostream>

class Money {
public:
    Money(long long soms, long long tiyin) : amount_(soms * 100 + tiyin) {}

    long long soms() const { return amount_ / 100; }
    long long tiyin() const { return amount_ % 100; }

    Money operator+(const Money& other) const {
        return Money(soms() + other.soms(), tiyin() + other.tiyin());
    }

    void print() const { std::cout << soms() << " so'm " << tiyin() << " tiyin\n"; }

private:
    long long amount_ = 0;      // in tiyin: 1 so'm = 100 tiyin
};

int main() {
    Money water(21900, 60);
    Money gas(38400, 70);

    Money bills = water + gas;              // the usual way
    Money same = water.operator+(gas);      // the same call, written out

    bills.print();
    same.print();
}

#include <iostream>

class Money {
public:
    Money(long long soms, long long tiyin) : amount_(soms * 100 + tiyin) {}

    long long soms() const { return amount_ / 100; }
    long long tiyin() const { return amount_ % 100; }

    void print() const { std::cout << soms() << " so'm " << tiyin() << " tiyin\n"; }

private:
    long long amount_ = 0;      // in tiyin: 1 so'm = 100 tiyin
};

Money operator+(const Money& a, const Money& b) {
    return Money(a.soms() + b.soms(), a.tiyin() + b.tiyin());
}

int main() {
    Money water(21900, 60);
    Money gas(38400, 70);

    Money bills = water + gas;              // the usual way
    Money same = operator+(water, gas);     // the same call, written out

    bills.print();
    same.print();
}

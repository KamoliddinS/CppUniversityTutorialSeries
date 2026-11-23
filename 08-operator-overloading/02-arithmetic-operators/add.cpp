#include <iostream>

class Money {
public:
    Money(long long soms, long long tiyin) : amount_(soms * 100 + tiyin) {}

    Money& operator+=(const Money& other) {
        amount_ += other.amount_;
        return *this;                       // the object itself, not a copy
    }

    Money operator-() const {               // unary minus: no parameter
        return Money(0, -amount_);          // 0 so'm and -amount_ tiyin
    }

    void print() const {
        std::cout << amount_ / 100 << " so'm " << amount_ % 100 << " tiyin\n";
    }

private:
    long long amount_ = 0;      // in tiyin: 1 so'm = 100 tiyin
};

Money operator+(const Money& a, const Money& b) {
    Money sum = a;      // a copy: a itself must not change
    sum += b;
    return sum;
}

int main() {
    Money bread(4200, 50);
    Money milk(11800, 75);

    Money total = bread + milk;     // a new Money: bread and milk stay as they are
    total += bread;                 // total itself changes
    total.print();

    Money paid(25000, 0);
    Money change = paid + -total;   // unary minus first, then +
    change.print();
}

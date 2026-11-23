#include <iostream>

class Money {
public:
    Money(long long soms, long long tiyin) : amount_(soms * 100 + tiyin) {}

    friend std::ostream& operator<<(std::ostream& out, const Money& m);

private:
    long long amount_ = 0;      // in tiyin: 1 so'm = 100 tiyin
};

std::ostream& operator<<(std::ostream& out, const Money& m) {
    out << m.amount_ / 100 << " so'm " << m.amount_ % 100 << " tiyin";
    return out;
}

std::istream& operator>>(std::istream& in, Money& m) {
    long long soms = 0;
    long long tiyin = 0;
    if (in >> soms >> tiyin) {      // change m only when both numbers were read
        m = Money(soms, tiyin);
    }
    return in;
}

int main() {
    Money price(0, 0);

    std::cout << "Price (so'm and tiyin): ";
    if (!(std::cin >> price)) {
        std::cout << "That is not a price.\n";
        return 1;
    }
    std::cout << "You pay " << price << ".\n";
}

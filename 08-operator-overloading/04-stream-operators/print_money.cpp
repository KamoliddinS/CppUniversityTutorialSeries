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
    return out;                 // give the stream back for the next <<
}

int main() {
    Money bread(4200, 50);
    Money milk(11800, 75);

    std::cout << "Bread: " << bread << '\n';
    std::cout << "Both:  " << bread << " and " << milk << '\n';
}

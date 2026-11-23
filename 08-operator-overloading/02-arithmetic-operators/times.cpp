#include <iostream>

class Money {
public:
    Money(long long soms, long long tiyin) : amount_(soms * 100 + tiyin) {}

    Money& operator*=(int count) {
        amount_ *= count;
        return *this;
    }

    void print() const {
        std::cout << amount_ / 100 << " so'm " << amount_ % 100 << " tiyin\n";
    }

private:
    long long amount_ = 0;      // in tiyin: 1 so'm = 100 tiyin
};

Money operator*(const Money& m, int count) {
    Money result = m;
    result *= count;
    return result;
}

Money operator*(int count, const Money& m) {
    return m * count;               // the same result: let the first function work
}

int main() {
    Money notebook(12500, 50);

    Money three = notebook * 3;
    Money same = 3 * notebook;
    three.print();
    same.print();
}

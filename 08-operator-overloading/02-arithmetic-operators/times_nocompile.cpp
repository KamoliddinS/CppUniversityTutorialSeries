#include <iostream>

class Money {
public:
    Money(long long soms, long long tiyin) : amount_(soms * 100 + tiyin) {}

    Money operator*(int count) const { return Money(0, amount_ * count); }

    void print() const {
        std::cout << amount_ / 100 << " so'm " << amount_ % 100 << " tiyin\n";
    }

private:
    long long amount_ = 0;      // in tiyin: 1 so'm = 100 tiyin
};

int main() {
    Money notebook(12500, 50);

    Money three = notebook * 3;     // notebook.operator*(3)
    Money same = 3 * notebook;      // 3.operator*(notebook)? An int has no member functions.
    three.print();
    same.print();
}

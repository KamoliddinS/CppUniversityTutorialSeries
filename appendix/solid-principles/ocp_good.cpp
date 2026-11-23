#include <iostream>

class Discount {
public:
    virtual ~Discount() = default;
    virtual int apply(int price) const = 0;
};

class NoDiscount : public Discount {
public:
    int apply(int price) const override { return price; }
};

class StudentDiscount : public Discount {
public:
    int apply(int price) const override { return price / 2; }
};

// This function is finished. A new discount is a new class; nothing here changes.
void printPrice(const Discount& discount, int price) {
    std::cout << discount.apply(price) << " so'm\n";
}

int main() {
    NoDiscount none;
    StudentDiscount student;
    printPrice(none, 3000);
    printPrice(student, 3000);
}

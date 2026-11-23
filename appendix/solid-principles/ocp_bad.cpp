#include <iostream>

enum class Discount { none, student };

// Breaks open/closed: every new discount means editing this function,
// although it already works.
void printPrice(Discount discount, int price) {
    int toPay = price;
    if (discount == Discount::student) {
        toPay = price / 2;
    }
    std::cout << toPay << " so'm\n";
}

int main() {
    printPrice(Discount::none, 3000);
    printPrice(Discount::student, 3000);
}

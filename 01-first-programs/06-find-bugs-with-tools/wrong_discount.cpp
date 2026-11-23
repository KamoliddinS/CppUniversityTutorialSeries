#include <iostream>

int main() {
    int price = 12000;      // one notebook, in so'm
    int quantity = 3;
    int discount = 10;      // percent

    int total = price * quantity;
    int saved = discount / 100 * total;
    total = total - saved;

    std::cout << "To pay: " << total << " so'm\n";
}

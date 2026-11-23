#include <iostream>

int main() {
    int price = 12000;          // type, name, starting value
    int quantity = 3;
    std::cout << "To pay: " << price * quantity << " so'm\n";

    price = 15000;              // the old value is replaced
    quantity = quantity + 1;    // read the old value, store the new one
    std::cout << "To pay: " << price * quantity << " so'm\n";
}

#include <iostream>

int main() {
    int* price = new int(12000);
    delete price;
    std::cout << *price << '\n';    // price still holds the old address
}

// Exercise 2: Ticket price
// This program reads an age and should print the price of a museum ticket:
//     younger than 7, or 65 and older    Free entry
//     7 to 17                            Price: 10000 so'm
//     18 to 64                           Price: 25000 so'm
// It builds, but it has three mistakes. Find them and fix them.
#include <iostream>

int main() {
    int age = 0;
    std::cin >> age;

    int price = 25000;
    if (age < 7 && age >= 65) {
        price = 0;
    } else if (age <= 64) {
        price = 25000;
    } else if (age <= 17) {
        price = 10000;
    }

    if (price = 0) {
        std::cout << "Free entry\n";
    } else {
        std::cout << "Price: " << price << " so'm\n";
    }
}

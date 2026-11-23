#include <iostream>

int main() {
    int price = 20000;
    bool isStudent = true;

    if (isStudent) {
        int price = 10000;          // a second variable with the same name
        std::cout << "Student price: " << price << " so'm\n";
    }
    std::cout << "To pay: " << price << " so'm\n";
}

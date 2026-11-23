#include <iostream>

int main() {
    int place = 2;

    switch (place) {
    case 1:
        std::cout << "gold\n";
        break;
    case 2:
        std::cout << "silver\n";
    case 3:
        std::cout << "bronze\n";
        break;
    default:
        std::cout << "no medal\n";
        break;
    }
}

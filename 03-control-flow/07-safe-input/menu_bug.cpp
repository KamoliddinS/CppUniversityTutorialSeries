#include <iostream>

int main() {
    while (true) {
        std::cout << "1 = greet, 2 = quit: ";
        int choice = 0;
        std::cin >> choice;
        if (choice == 2) {
            break;
        }
        if (choice == 1) {
            std::cout << "Salom!\n";
        } else {
            std::cout << "Unknown choice.\n";
        }
    }
}

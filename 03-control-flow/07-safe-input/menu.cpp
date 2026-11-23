#include <iostream>
#include <limits>

int main() {
    while (true) {
        std::cout << "1 = greet, 2 = quit: ";
        int choice = 0;
        if (!(std::cin >> choice)) {            // the read failed
            if (std::cin.eof()) {
                break;                          // the input has ended: stop
            }
            std::cin.clear();                   // make std::cin work again
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');   // drop the line
            std::cout << "Please type a number.\n";
            continue;                           // ask again
        }
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

#include <iostream>

int main() {
    int count = 3;
    while (count > 0) {                 // tested before every round
        std::cout << count << '\n';
        count = count - 1;
    }
    std::cout << "Go!\n";
}

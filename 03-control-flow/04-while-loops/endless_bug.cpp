#include <iostream>

int main() {
    int count = 3;
    while (count > 0) {
        std::cout << count << '\n';     // count never changes: the loop never ends
    }
    std::cout << "Go!\n";
}

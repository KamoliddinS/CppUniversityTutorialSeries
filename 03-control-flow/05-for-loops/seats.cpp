#include <iostream>

int main() {
    for (int row = 1; row <= 2; ++row) {
        for (int seat = 1; seat <= 4; ++seat) {
            std::cout << row << '-' << seat << ' ';
        }
        std::cout << '\n';              // after every row
    }
}

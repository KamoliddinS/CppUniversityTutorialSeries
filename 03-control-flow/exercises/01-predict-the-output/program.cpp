// Exercise 1: Predict the output
// Do not run this program yet. Write what it prints into prediction.txt.
#include <iostream>

int main() {
    for (int i = 1; i <= 8; ++i) {
        if (i == 3) {
            continue;
        }
        if (i > 5) {
            break;
        }
        std::cout << i << '\n';
    }

    int n = 20;
    while (n > 3) {
        n = n / 2;
    }
    std::cout << "n = " << n << '\n';

    for (int row = 1; row <= 3; ++row) {
        for (int column = 1; column <= row; ++column) {
            std::cout << row * column << ' ';
        }
        std::cout << '\n';
    }
}

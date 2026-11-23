#include <iostream>

void step(int n) {
    if (n == 0) {
        return;                         // base case: nothing to do
    }
    std::cout << "down " << n << '\n';
    step(n - 1);
    std::cout << "up " << n << '\n';
}

int main() {
    step(2);
}

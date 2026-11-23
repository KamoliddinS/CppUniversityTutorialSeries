#include <iostream>

int larger(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

double larger(double a, double b) {
    if (a > b) {
        return a;
    }
    return b;
}

int larger(int a, int b, int c) {
    return larger(larger(a, b), c);
}

int main() {
    std::cout << larger(3, 8) << '\n';          // two int values
    std::cout << larger(2.5, 1.5) << '\n';      // two double values
    std::cout << larger(4, 9, 6) << '\n';       // three int values
    std::cout << larger(3, 4.5) << '\n';        // an int and a double
}

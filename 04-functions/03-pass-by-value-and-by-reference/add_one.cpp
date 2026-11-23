#include <iostream>

void addOne(int a, int& b) {
    a = a + 1;
    b = b + 1;
    std::cout << "inside: " << a << ' ' << b << '\n';
}

int main() {
    int x = 5;
    int y = 5;
    addOne(x, y);
    std::cout << "after:  " << x << ' ' << y << '\n';
    addOne(y, x);
    std::cout << "after:  " << x << ' ' << y << '\n';
}

#include <iostream>

int main() {
    int x = 5;
    int y = 8;
    int& r = x;
    int* p = &y;

    r = y;
    *p = 3;
    p = &r;
    *p = *p + 1;

    std::cout << x << ' ' << y << '\n';
}

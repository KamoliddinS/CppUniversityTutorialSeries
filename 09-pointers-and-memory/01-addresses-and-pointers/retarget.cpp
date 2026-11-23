#include <iostream>

int main() {
    int a = 1;
    int b = 2;
    int* p = &a;

    *p = 10;
    p = &b;
    *p = *p + 20;

    std::cout << a << ' ' << b << '\n';
}

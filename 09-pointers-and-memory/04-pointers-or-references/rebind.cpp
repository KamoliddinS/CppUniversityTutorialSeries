#include <iostream>

int main() {
    int a = 1;
    int b = 2;

    int& r = a;         // r is another name for a
    r = b;              // r still means a: this copies the value of b into a
    std::cout << "a = " << a << ", b = " << b << '\n';

    int* p = &a;        // p points to a
    p = &b;             // now p points to b
    *p = 9;
    std::cout << "a = " << a << ", b = " << b << '\n';
}

#include <iostream>

#include "int_buffer.h"

int main() {
    IntBuffer a(3);
    a[0] = 7;

    IntBuffer b = a;        // b is created from a: copy constructor
    b[0] = 99;

    IntBuffer c(5);
    c = a;                  // c exists already: copy assignment

    std::cout << "a[0] = " << a[0] << ", b[0] = " << b[0] << ", c[0] = " << c[0] << '\n';
}

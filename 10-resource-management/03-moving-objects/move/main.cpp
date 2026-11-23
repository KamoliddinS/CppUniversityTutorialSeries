#include <iostream>
#include <utility>

#include "int_buffer.h"

IntBuffer makeBuffer() {
    IntBuffer result(1000);
    result[0] = 7;
    return result;                  // plain return: no std::move
}

int main() {
    IntBuffer a(1000);

    std::cout << "1\n";
    IntBuffer b = a;                // a keeps its block: copy
    std::cout << "2\n";
    IntBuffer c = std::move(a);     // a gives its block away: move
    std::cout << "3\n";
    IntBuffer d = makeBuffer();     // result is built directly in d
    std::cout << "4\n";
    b = makeBuffer();               // the returned buffer is a temporary: move
    std::cout << "a has " << a.size() << " ints, c has " << c.size() << '\n';
}

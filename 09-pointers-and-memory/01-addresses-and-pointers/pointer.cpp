#include <iostream>

int main() {
    int count = 42;
    int* p = &count;        // p holds the address of count

    std::cout << "count:  " << count << '\n';
    std::cout << "&count: " << &count << '\n';
    std::cout << "p:      " << p << '\n';
    std::cout << "*p:     " << *p << '\n';

    *p = 50;                // changes count through the pointer
    std::cout << "count:  " << count << '\n';
}

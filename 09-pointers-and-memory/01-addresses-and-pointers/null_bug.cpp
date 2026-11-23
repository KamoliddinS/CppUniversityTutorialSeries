#include <iostream>

int main() {
    int* p = nullptr;               // p points to nothing
    std::cout << "Before\n";
    std::cout << *p << '\n';        // there is no int to read
    std::cout << "After\n";
}

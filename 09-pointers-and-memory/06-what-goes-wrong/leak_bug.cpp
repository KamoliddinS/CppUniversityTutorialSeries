#include <iostream>

int main() {
    int* price = new int(12000);
    std::cout << *price << '\n';
}   // no delete: the int stays on the heap

#include <iostream>

#include "stack.h"

int main() {
    Stack<int> numbers;
    numbers.push(10);
    std::cout << numbers.size() << '\n';
}

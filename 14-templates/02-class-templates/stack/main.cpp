#include <iostream>
#include <stdexcept>
#include <string>

#include "stack.h"

int main() {
    Stack<int> numbers;
    numbers.push(10);
    numbers.push(20);
    std::cout << numbers.top() << " is on top of " << numbers.size() << " numbers\n";

    Stack<std::string> cities;
    cities.push("Tashkent");
    cities.push("Samarkand");
    cities.pop();                    // removes Samarkand
    std::cout << cities.top() << '\n';

    try {
        cities.pop();
        cities.pop();                // the stack is already empty
    } catch (const std::out_of_range& e) {
        std::cout << "Error: " << e.what() << '\n';
    }
}

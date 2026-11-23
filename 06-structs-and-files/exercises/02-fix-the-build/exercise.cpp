// Exercise 2: Fix the build
// This file does not compile yet. Fixing it is the exercise.
#include <iostream>
#include <string>

enum class Size { small, medium, large };

struct Order {
    std::string customer;
    Size size = Size::small;
    int cups = 1;
}

std::string toText(Size size) {
    switch (size) {
    case Size::small:
        return "small";
    case medium:
        return "medium";
    case Size::large:
        return "large";
    }
    return "unknown";
}

int main() {
    Order order{"Malika", 2, Size::large};
    Order.cups = order.cups + 1;

    std::cout << order.customer << " orders " << order.cups << ' ' << toText(order.size)
              << " teas.\n";
    int number = order.size;
    std::cout << "Size number: " << number << '\n';
}

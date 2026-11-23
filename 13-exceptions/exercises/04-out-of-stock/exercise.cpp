// Exercise 4: Out of stock
// A shop starts with 10 somsa. Every number in the input is one order.
// Complete the three TODO parts so that an order that is too large is refused.
#include <iostream>
#include <stdexcept>

// TODO 1: write the class OutOfStock here.
// It derives from std::runtime_error and passes the message "not enough somsa" to it.
// It stores how many somsa are missing, and its member function missing() returns that number.

class Shop {
public:
    explicit Shop(int stock) : stock_(stock) {}

    void sell(int count) {
        // TODO 2: if count is larger than the stock, throw an OutOfStock
        // that knows how many somsa are missing.
        stock_ -= count;
    }

    int stock() const { return stock_; }

private:
    int stock_;
};

int main() {
    Shop shop(10);
    int count = 0;
    while (std::cin >> count) {
        // TODO 3: put the next two lines into a try block. Add a handler that prints
        //     refused: MESSAGE, MISSING missing
        shop.sell(count);
        std::cout << "sold " << count << ", " << shop.stock() << " left\n";
    }
}

#include <iostream>
#include <string>

class SmsSender {
public:
    void send(const std::string& text) const {
        std::cout << "SMS: " << text << '\n';
    }
};

// Breaks dependency inversion: Order can only work with SmsSender. To send an
// e-mail instead, or to test Order without sending anything, you must edit Order.
class Order {
public:
    void finish() const { sender_.send("Your order is ready"); }

private:
    SmsSender sender_;
};

int main() {
    Order order;
    order.finish();
}

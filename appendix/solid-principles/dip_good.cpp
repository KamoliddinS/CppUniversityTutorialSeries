#include <iostream>
#include <memory>
#include <string>
#include <utility>

class Sender {
public:
    virtual ~Sender() = default;
    virtual void send(const std::string& text) const = 0;
};

class SmsSender : public Sender {
public:
    void send(const std::string& text) const override {
        std::cout << "SMS: " << text << '\n';
    }
};

// Order knows only the abstract Sender.
// The code that creates an Order chooses the real one.
class Order {
public:
    explicit Order(std::unique_ptr<Sender> sender) : sender_(std::move(sender)) {}
    void finish() const { sender_->send("Your order is ready"); }

private:
    std::unique_ptr<Sender> sender_;
};

int main() {
    Order order(std::make_unique<SmsSender>());
    order.finish();
}

#include <iostream>
#include <string>

class Ticket {
public:
    explicit Ticket(const std::string& seat) : seat_(seat) {}
    Ticket(const Ticket& other) = delete;               // no copy constructor
    Ticket& operator=(const Ticket& other) = delete;    // no copy assignment
    Ticket(Ticket&& other) = default;                   // moving is allowed
    Ticket& operator=(Ticket&& other) = default;
    const std::string& seat() const { return seat_; }

private:
    std::string seat_;
};

int main() {
    Ticket first("12A");
    Ticket second = first;          // a second ticket for the same seat?
    std::cout << second.seat() << '\n';
}

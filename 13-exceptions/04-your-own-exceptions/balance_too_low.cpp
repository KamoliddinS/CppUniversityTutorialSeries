#include <iostream>
#include <stdexcept>

class BalanceTooLow : public std::runtime_error {
public:
    explicit BalanceTooLow(int missing)
        : std::runtime_error("balance too low"), missing_(missing) {}

    int missing() const noexcept { return missing_; }

private:
    int missing_;       // what the handler needs besides the text
};

int withdraw(int balance, int amount) {
    if (amount > balance) {
        throw BalanceTooLow(amount - balance);
    }
    return balance - amount;
}

int main() {
    int balance = 50000;
    try {
        balance = withdraw(balance, 20000);
        balance = withdraw(balance, 90000);
    } catch (const BalanceTooLow& e) {
        std::cout << "Refused: " << e.what() << ", " << e.missing() << " so'm missing\n";
    }
    std::cout << "Balance: " << balance << " so'm\n";
}

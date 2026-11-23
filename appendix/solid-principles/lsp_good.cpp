#include <iostream>

class Account {
public:
    virtual ~Account() = default;
    // Promise: true means the money was taken out, false means nothing changed.
    virtual bool withdraw(int amount) {
        balance_ -= amount;
        return true;
    }
    void deposit(int amount) { balance_ += amount; }
    int balance() const { return balance_; }

private:
    int balance_ = 100000;
};

// LockedAccount keeps the promise: "false, nothing changed" is an allowed answer.
class LockedAccount : public Account {
public:
    bool withdraw(int) override { return false; }
};

void transfer(Account& from, Account& to, int amount) {
    if (from.withdraw(amount)) {
        to.deposit(amount);
    }
}

int main() {
    LockedAccount savings;
    Account card;
    transfer(savings, card, 30000);
    std::cout << "Savings: " << savings.balance() << ", card: " << card.balance() << '\n';
}

#include <iostream>

class Account {
public:
    virtual ~Account() = default;
    // Promise: after withdraw(amount) the balance is smaller by amount.
    virtual void withdraw(int amount) { balance_ -= amount; }
    void deposit(int amount) { balance_ += amount; }
    int balance() const { return balance_; }

private:
    int balance_ = 100000;
};

// Breaks Liskov substitution: LockedAccount does not keep the promise of
// Account::withdraw. Code that is correct for an Account now goes wrong.
class LockedAccount : public Account {
public:
    void withdraw(int) override {}   // locked: the amount is ignored, nothing happens
};

void transfer(Account& from, Account& to, int amount) {
    from.withdraw(amount);
    to.deposit(amount);
}

int main() {
    LockedAccount savings;
    Account card;
    transfer(savings, card, 30000);
    std::cout << "Savings: " << savings.balance() << ", card: " << card.balance() << '\n';
}

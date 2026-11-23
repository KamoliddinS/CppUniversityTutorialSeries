#include <iostream>

class Account {
public:
    void deposit(int amount) {
        if (amount > 0) {
            balance_ += amount;
        }
    }

    bool withdraw(int amount) {
        if (amount <= 0 || amount > balance_) {
            return false;       // refuse, so the balance stays valid
        }
        balance_ -= amount;
        return true;
    }

    int balance() { return balance_; }

private:
    int balance_ = 0;   // so'm; never negative
};

int main() {
    Account account;
    account.deposit(50000);
    if (!account.withdraw(80000)) {
        std::cout << "Not enough money.\n";
    }
    std::cout << "Balance: " << account.balance() << " so'm\n";
}

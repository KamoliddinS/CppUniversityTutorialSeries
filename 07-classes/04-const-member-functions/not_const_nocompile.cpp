#include <iostream>

class Account {
public:
    explicit Account(int amount) { deposit(amount); }

    void deposit(int amount) {
        if (amount > 0) {
            balance_ += amount;
        }
    }

    int balance() { return balance_; }      // only reads, but does not say so

private:
    int balance_ = 0;
};

void printBalance(const Account& account) {
    std::cout << account.balance() << " so'm\n";
}

int main() {
    Account account(50000);
    printBalance(account);
}

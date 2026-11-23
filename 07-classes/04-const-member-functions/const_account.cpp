#include <iostream>

class Account {
public:
    explicit Account(int amount) { deposit(amount); }

    void deposit(int amount) {                  // no const: it changes the object
        if (amount > 0) {
            balance_ += amount;
        }
    }

    int balance() const { return balance_; }    // const: it only reads

private:
    int balance_ = 0;
};

void printBalance(const Account& account) {
    std::cout << account.balance() << " so'm\n";
}

int main() {
    Account account(50000);
    account.deposit(25000);
    printBalance(account);

    const Account gift(10000);      // a const object: it can never change
    std::cout << gift.balance() << " so'm\n";
}

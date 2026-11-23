#include <iostream>

class Account {
public:
    explicit Account(int amount) {
        if (amount > 0) {
            balance_ = amount;
        }
    }

    int balance() const { return balance_; }

    friend void transfer(Account& from, Account& to, int amount);

private:
    int balance_ = 0;
};

void transfer(Account& from, Account& to, int amount) {
    if (amount > 0 && amount <= from.balance_) {
        from.balance_ -= amount;    // allowed only because transfer is a friend
        to.balance_ += amount;
    }
}

int main() {
    Account malika(50000);
    Account jasur(10000);
    transfer(malika, jasur, 20000);
    std::cout << "Malika: " << malika.balance() << " so'm\n";
    std::cout << "Jasur: " << jasur.balance() << " so'm\n";
}

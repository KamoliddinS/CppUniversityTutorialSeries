// Exercise 3: Savings account
// Complete the two functions marked TODO. Do not change Account or main.
#include <iostream>
#include <string>

class Account {
public:
    Account(const std::string& owner, int balance) : owner_(owner), balance_(balance) {}
    void deposit(int amount) { balance_ += amount; }
    int balance() const { return balance_; }
    void print() const { std::cout << owner_ << ": " << balance_ << " so'm\n"; }

private:
    std::string owner_;
    int balance_ = 0;
};

class SavingsAccount : public Account {
public:
    SavingsAccount(const std::string& owner, int balance, int rate)
        : Account(owner, balance), rate_(rate) {}

    // TODO 1: add rate_ percent of the balance to the account.
    //         balance_ is private in Account, so use the public functions of Account.
    void addInterest() {}

    // TODO 2: print the line that Account::print() prints, then the rate line.
    void print() const {}

private:
    int rate_ = 0;  // percent per year
};

int main() {
    std::string owner;
    int balance = 0;
    int rate = 0;
    std::cin >> owner >> balance >> rate;

    SavingsAccount savings(owner, balance, rate);
    savings.print();
    savings.addInterest();
    savings.print();
}

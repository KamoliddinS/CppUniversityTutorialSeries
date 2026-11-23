#include <iostream>

class Account {
public:
    explicit Account(int amount) : balance_(amount), bonus_(balance_ / 10) {}

    void print() {
        std::cout << "balance " << balance_ << ", bonus " << bonus_ << '\n';
    }

private:
    int bonus_;
    int balance_;
};

int main() {
    Account account(50000);
    account.print();    // should print: balance 50000, bonus 5000
}

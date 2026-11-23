#include <iostream>

class Account {
public:
    explicit Account(int balance) {
        balance = balance;      // which balance is which?
    }

    void print() const {
        std::cout << balance << " so'm\n";
    }

private:
    int balance = 0;    // no trailing underscore: the same name as the parameter
};

int main() {
    Account account(50000);
    account.print();    // should print: 50000 so'm
}

#include <iostream>

#include "account.h"

int main() {
    Account account(120000);
    account.deposit(30000);
    if (!account.withdraw(500000)) {
        std::cout << "Not enough money.\n";
    }
    std::cout << "Balance: " << account.balance() << " so'm\n";
}

// The same program as bank/main.cpp, but built alone, without bank/account.cpp:
//     g++ -std=c++20 main_alone_nocompile.cpp
#include <iostream>

#include "bank/account.h"

int main() {
    Account account(120000);
    account.deposit(30000);
    if (!account.withdraw(500000)) {
        std::cout << "Not enough money.\n";
    }
    std::cout << "Balance: " << account.balance() << " so'm\n";
}

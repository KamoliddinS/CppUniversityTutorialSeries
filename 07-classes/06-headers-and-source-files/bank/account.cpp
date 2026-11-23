#include "account.h"

Account::Account(int amount) : balance_(amount) {
    if (balance_ < 0) {
        balance_ = 0;
    }
}

void Account::deposit(int amount) {
    if (amount > 0) {
        balance_ += amount;
    }
}

bool Account::withdraw(int amount) {
    if (amount <= 0 || amount > balance_) {
        return false;
    }
    balance_ -= amount;
    return true;
}

int Account::balance() const {
    return balance_;
}

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
public:
    explicit Account(int amount);

    void deposit(int amount);
    bool withdraw(int amount);
    int balance() const;

private:
    int balance_ = 0;   // so'm; never negative
};

#endif

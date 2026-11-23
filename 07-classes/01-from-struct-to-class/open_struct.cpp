#include <iostream>
#include <string>

struct Account {
    std::string owner;
    int balance = 0;    // so'm; must never be negative
};

int main() {
    Account account{"Malika", 50000};
    account.balance -= 80000;   // nothing stops this line
    std::cout << account.owner << ": " << account.balance << " so'm\n";
}

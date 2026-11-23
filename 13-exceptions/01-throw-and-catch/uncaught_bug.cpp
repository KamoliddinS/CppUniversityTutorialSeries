#include <iostream>
#include <stdexcept>

int withdraw(int balance, int amount) {
    if (amount > balance) {
        throw std::runtime_error("balance too low");   // leaves the function here
    }
    std::cout << "Paid out " << amount << " so'm\n";
    return balance - amount;
}

int main() {
    int balance = withdraw(50000, 90000);   // nobody catches the exception
    std::cout << "Balance: " << balance << " so'm\n";
}

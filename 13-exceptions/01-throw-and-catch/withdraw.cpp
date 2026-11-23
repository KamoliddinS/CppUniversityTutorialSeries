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
    int balance = 50000;
    try {
        balance = withdraw(balance, 20000);
        balance = withdraw(balance, 90000);
        std::cout << "This line is skipped.\n";
    } catch (const std::runtime_error& e) {
        std::cout << "Refused: " << e.what() << '\n';
    }
    std::cout << "Balance: " << balance << " so'm\n";
}

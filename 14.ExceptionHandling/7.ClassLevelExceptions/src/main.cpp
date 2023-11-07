#include <iostream>
#include <stdexcept>
#include <string>

// A simple class representing a bank account
class BankAccount {
public:
    // Nested exception class for BankAccount-specific errors
    class AccountException : public std::exception {
    private:
        std::string message;
    public:
        AccountException(const std::string& msg) : message(msg) {}
        const char* what() const noexcept override {
            return message.c_str();
        }
    };

private:
    double balance;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {
        if (initialBalance < 0) {
            throw AccountException("Initial balance cannot be negative.");
        }
    }

    void deposit(double amount) {
        if (amount <= 0) {
            throw AccountException("Deposit amount must be positive.");
        }
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            throw AccountException("Withdrawal amount must be positive.");
        }
        if (amount > balance) {
            throw AccountException("Insufficient funds for withdrawal.");
        }
        balance -= amount;
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    try {
        BankAccount account(1000); // Start with a valid balance
        account.deposit(500);      // Valid deposit
        account.withdraw(2000);    // This will throw an exception
    } catch (const BankAccount::AccountException& e) {
        std::cerr << "BankAccount error: " << e.what() << std::endl;
    }

    // Continue with program...
    std::cout << "Continuing with the rest of the program..." << std::endl;

    return 0;
}

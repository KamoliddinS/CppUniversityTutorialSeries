#include <iostream>
#include <string>

// BankAccount class declaration
class BankAccount {
private:
    // Private data members are only accessible within the class
    std::string ownerName;
    double balance;

    // Private helper method
    bool isWithdrawalAllowed(double amount) {
        return (balance - amount) >= 0;
    }

public:
    // Constructor to initialize the BankAccount with an owner name and initial balance
    BankAccount(std::string owner, double initialBalance) : ownerName(owner), balance(initialBalance) {}

    // Public method to deposit money into the account
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited: " << amount << std::endl;
        }
    }

    // Public method to withdraw money from the account
    bool withdraw(double amount) {
        if (amount > 0 && isWithdrawalAllowed(amount)) {
            balance -= amount;
            std::cout << "Withdrawn: " << amount << std::endl;
            return true;
        }
        std::cout << "Insufficient balance or invalid amount. Withdrawal denied." << std::endl;
        return false;
    }

    // Public method to display account balance
    void displayBalance() const {
        std::cout << ownerName << ", your current balance is $" << balance << std::endl;
    }
};

// Main function
int main() {
    // Create an instance of BankAccount
    BankAccount myAccount("John Doe", 500.0);

    // Access public members: deposit and displayBalance
    myAccount.deposit(150.0);
    myAccount.displayBalance();

    // Attempt withdrawal and display balance
    if (myAccount.withdraw(100.0)) {
        myAccount.displayBalance();
    }

    // Directly accessing private members will result in a compilation error
    // myAccount.balance = 1000.0;  // Uncommenting this line will cause a compile error

    return 0;
}

#include <iostream>

class Account {
private:
    // Non-static member variable
    double balance;
    
    // Static member variable
    static int accountCount;

public:
    // Constructor
    Account(double initialBalance) : balance(initialBalance) {
        // Increment the static member variable for every new object created
        accountCount++;
    }

    // Static member function
    static int getAccountCount() {
        // Access the static member variable
        return accountCount;
    }

    // Regular member function
    void deposit(double amount) {
        balance += amount;
    }
};

// Initialize the static member variable
int Account::accountCount = 0;

int main() {
    Account a1(100.0);
    Account a2(150.0);
    
    // Output the number of accounts created
    std::cout << "Total accounts: " << Account::getAccountCount() << std::endl;

    

    return 0;
}
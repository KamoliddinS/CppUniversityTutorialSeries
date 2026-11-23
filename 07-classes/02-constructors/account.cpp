#include <iostream>
#include <string>

class Account {
public:
    Account(const std::string& owner, int amount) : owner_(owner), balance_(amount) {
        if (balance_ < 0) {
            balance_ = 0;       // an account never starts below zero
        }
    }

    void print() {
        std::cout << owner_ << ": " << balance_ << " so'm\n";
    }

private:
    std::string owner_;
    int balance_ = 0;
};

int main() {
    Account malika("Malika", 50000);
    Account jasur{"Jasur", -700};   // braces work too
    malika.print();
    jasur.print();
}

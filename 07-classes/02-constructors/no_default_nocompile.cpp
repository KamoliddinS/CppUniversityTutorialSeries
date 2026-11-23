#include <iostream>
#include <string>

class Account {
public:
    Account(const std::string& owner, int amount) : owner_(owner), balance_(amount) {}

    void print() {
        std::cout << owner_ << ": " << balance_ << " so'm\n";
    }

private:
    std::string owner_;
    int balance_ = 0;
};

int main() {
    Account account;    // whose account? how much money?
    account.print();
}

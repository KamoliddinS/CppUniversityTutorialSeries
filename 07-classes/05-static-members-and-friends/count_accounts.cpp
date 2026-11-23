#include <iostream>
#include <string>

class Account {
public:
    explicit Account(const std::string& owner) : owner_(owner) {
        ++count_;
        number_ = count_;
    }

    void print() const {
        std::cout << "Account " << number_ << " of " << count_ << ": " << owner_ << '\n';
    }

    static int count() { return count_; }   // needs no object

private:
    inline static int count_ = 0;   // one for the whole class
    std::string owner_;             // one for each object
    int number_ = 0;                // one for each object
};

int main() {
    std::cout << "Accounts: " << Account::count() << '\n';
    Account first("Malika");
    Account second("Jasur");
    first.print();
    second.print();
    std::cout << "Accounts: " << Account::count() << '\n';
}

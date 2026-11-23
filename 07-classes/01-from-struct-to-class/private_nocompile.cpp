class Account {
public:
    void deposit(int amount) {
        if (amount > 0) {
            balance_ += amount;
        }
    }

private:
    int balance_ = 0;   // so'm; never negative
};

int main() {
    Account account;
    account.deposit(50000);
    account.balance_ -= 80000;      // not allowed: balance_ is private
}

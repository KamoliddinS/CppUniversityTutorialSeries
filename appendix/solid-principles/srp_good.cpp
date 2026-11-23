#include <iostream>
#include <vector>

// Job 1: keep the prices and add them up.
class Bill {
public:
    void add(int price) { prices_.push_back(price); }
    const std::vector<int>& prices() const { return prices_; }

    int total() const {
        int sum = 0;
        for (int price : prices_) {
            sum += price;
        }
        return sum;
    }

private:
    std::vector<int> prices_;
};

// Job 2: decide how a bill looks on the screen.
void print(const Bill& bill) {
    for (int price : bill.prices()) {
        std::cout << price << " so'm\n";
    }
    std::cout << "Total: " << bill.total() << " so'm\n";
}

int main() {
    Bill bill;
    bill.add(45000);
    bill.add(8000);
    print(bill);
}

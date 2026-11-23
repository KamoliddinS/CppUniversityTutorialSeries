#include <iostream>
#include <vector>

// Breaks single responsibility: Bill has two jobs. It adds up the prices AND it
// decides how a bill looks. A new price rule and a new layout both mean editing it.
class Bill {
public:
    void add(int price) { prices_.push_back(price); }

    void print() const {
        int total = 0;
        for (int price : prices_) {
            std::cout << price << " so'm\n";
            total += price;
        }
        std::cout << "Total: " << total << " so'm\n";
    }

private:
    std::vector<int> prices_;
};

int main() {
    Bill bill;
    bill.add(45000);
    bill.add(8000);
    bill.print();
}

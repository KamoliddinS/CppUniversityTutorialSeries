#include <cstddef>
#include <iostream>
#include <vector>

class Receipt {
public:
    void add(int price) { prices_.push_back(price); }
    std::size_t size() const { return prices_.size(); }

    int& operator[](std::size_t i) { return prices_.at(i); }                // read and write
    const int& operator[](std::size_t i) const { return prices_.at(i); }    // read only

private:
    std::vector<int> prices_;       // in so'm
};

int total(const Receipt& receipt) {
    int sum = 0;
    for (std::size_t i = 0; i < receipt.size(); ++i) {
        sum += receipt[i];          // receipt is const here: the second version is called
    }
    return sum;
}

int main() {
    Receipt receipt;
    receipt.add(4200);
    receipt.add(11800);

    receipt[1] = 9900;              // the first version: assign to the element itself
    std::cout << "Total: " << total(receipt) << " so'm\n";
}

#include <iostream>

int totalCost(int price, int quantity) {
    return price * quantity;
}

bool isBigOrder(int amount) {
    return amount >= 50000;
}

int deliveryFee(int amount) {
    if (isBigOrder(amount)) {
        return 0;               // the function ends here
    }
    return 15000;
}

int main() {
    int cost = totalCost(12000, 3);
    std::cout << "Goods:    " << cost << " so'm\n";
    std::cout << "Delivery: " << deliveryFee(cost) << " so'm\n";
    std::cout << "To pay:   " << cost + deliveryFee(cost) << " so'm\n";
}

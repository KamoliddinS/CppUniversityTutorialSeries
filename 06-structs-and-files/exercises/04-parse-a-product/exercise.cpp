// Exercise 4: Parse a product
// Complete parseProduct. Do not change main.
#include <iostream>
#include <sstream>
#include <string>

struct Product {
    std::string name;
    int price = 0;      // for one piece, in so'm
    int quantity = 0;
};

// Fills product from a line such as "Bread,4500,3" and returns true.
// Returns false when the line does not have three fields.
bool parseProduct(const std::string& line, Product& product) {
    // TODO: read the three fields from a string stream made of line.
    // TODO: return false if a field is missing.
    // TODO: turn the price and the quantity into numbers, and return true.
    product.name = line;    // wrong: this stores the whole line as the name
    return false;
}

int main() {
    std::string line;
    int total = 0;
    while (std::getline(std::cin, line)) {
        Product product;
        if (parseProduct(line, product)) {
            int cost = product.price * product.quantity;
            std::cout << product.name << ": " << product.quantity << " x " << product.price
                      << " = " << cost << '\n';
            total += cost;
        } else {
            std::cout << "Skipped: " << line << '\n';
        }
    }
    std::cout << "Total: " << total << " so'm\n";
}

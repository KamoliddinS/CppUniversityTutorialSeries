#include <iostream>
#include <optional>
#include <string>
#include <vector>

struct Card {
    std::string owner;
    int discount = 0;       // percent
};

std::optional<int> findDiscount(const std::vector<Card>& cards, const std::string& owner) {
    for (const Card& card : cards) {
        if (card.owner == owner) {
            return card.discount;       // a value
        }
    }
    return std::nullopt;                // no value: a normal answer, not an error
}

int main() {
    const std::vector<Card> cards = {{"Malika", 10}, {"Jasur", 5}};

    std::optional<int> discount = findDiscount(cards, "Malika");
    if (discount) {
        std::cout << "Malika gets " << *discount << "% off\n";
    }

    discount = findDiscount(cards, "Aziz");
    if (!discount.has_value()) {
        std::cout << "Aziz has no card\n";
    }
    std::cout << "Aziz gets " << discount.value_or(0) << "% off\n";
}

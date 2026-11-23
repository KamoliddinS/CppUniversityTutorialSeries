// Exercise 1: Predict the output
// Do not run this program yet. Write what it prints into prediction.txt.
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

enum class Size { small, medium, large };

struct Tea {
    std::string name;
    int price = 0;
    Size size = Size::small;
};

int main() {
    Tea green{"green", 5000};
    Tea black = green;
    black.name = "black";
    black.price += 1000;
    std::cout << green.name << ' ' << green.price << '\n';

    std::vector<Tea> menu = {green, black};
    for (Tea tea : menu) {
        tea.price *= 2;
    }
    std::cout << menu[0].price << ' ' << menu[1].price << '\n';

    menu[1].size = Size::large;
    std::cout << static_cast<int>(menu[0].size) << static_cast<int>(menu[1].size) << '\n';

    std::cout << std::setfill('.') << std::setw(8) << black.name << black.price << '\n';
    std::cout << std::setw(8) << 7 << '\n';
}

// Exercise 1: Predict the output
// Do not run this program yet. Write what it prints into prediction.txt.
#include <iostream>
#include <map>
#include <set>
#include <string>

int main() {
    std::map<std::string, int> stock;
    stock["pen"] = 3;
    stock["book"] = 2;
    stock["pen"] += 4;
    if (stock["ruler"] == 0) {
        std::cout << "no rulers\n";
    }
    for (const auto& [item, count] : stock) {
        std::cout << item << ' ' << count << '\n';
    }

    std::set<int> seen = {5, 1, 5, 3, 1};
    std::cout << seen.size() << ' ' << *seen.begin() << '\n';

    int step = 2;
    auto next = [step](int x) { return x + step; };
    step = 10;
    std::cout << next(1) << ' ' << step << '\n';
}

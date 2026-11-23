#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {10, 20, 30, 40};
    auto it = v.begin();
    ++it;
    std::cout << *it << ' ' << *(it + 2) << ' ' << v.end() - it << '\n';
}

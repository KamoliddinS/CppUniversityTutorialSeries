#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;
    for (int i = 1; i <= 6; ++i) {
        v.push_back(i * 10);
        std::cout << "size " << v.size() << "  capacity " << v.capacity() << '\n';
    }
}

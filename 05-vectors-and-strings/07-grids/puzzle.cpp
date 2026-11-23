#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<int>> grid(2, std::vector<int>(3, 7));
    grid[1][0] = 0;
    grid[0].push_back(5);

    for (const std::vector<int>& row : grid) {
        for (int value : row) {
            std::cout << value << ' ';
        }
        std::cout << '\n';
    }
}

#include <cstddef>
#include <iostream>
#include <vector>

int main() {
    // 3 rows with 4 seats each; 0 means free
    std::vector<std::vector<int>> seats(3, std::vector<int>(4, 0));

    seats[0][1] = 1;                // row 0, seat 1 is taken
    seats[2][3] = 1;                // row 2, seat 3 is taken

    for (std::size_t r = 0; r < seats.size(); ++r) {
        std::cout << "Row " << r << ":";
        for (std::size_t c = 0; c < seats[r].size(); ++c) {
            std::cout << ' ' << seats[r][c];
        }
        std::cout << '\n';
    }
}

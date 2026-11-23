// Exercise 5: Row and column sums
// Read the number of rows and the number of columns, then the grid, row by row.
// Print the sum of every row on one line and the sum of every column on the next:
//     Rows: 6 15
//     Columns: 5 7 9
#include <cstddef>
#include <iostream>
#include <vector>

int main() {
    std::size_t rows = 0;
    std::size_t columns = 0;
    std::cin >> rows >> columns;

    std::vector<std::vector<int>> grid(rows, std::vector<int>(columns, 0));
    // TODO: read the numbers into grid.

    // TODO: print the row sums after "Rows:" and the column sums after "Columns:".
    std::cout << "Rows:\n";
    std::cout << "Columns:\n";
}

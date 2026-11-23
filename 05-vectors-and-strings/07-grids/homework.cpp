#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<int>> points = {
        {8, 10, 7},         // Aziz handed in three tasks
        {9, 6},             // Malika handed in two
        {10, 10, 9, 8}      // Jasur handed in four
    };

    for (const std::vector<int>& row : points) {    // each row is a vector
        int sum = 0;
        for (int value : row) {
            sum += value;
        }
        std::cout << row.size() << " tasks, " << sum << " points\n";
    }
}

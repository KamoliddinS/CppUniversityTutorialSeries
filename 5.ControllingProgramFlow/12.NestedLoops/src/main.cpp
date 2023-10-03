#include <iostream>

int main() {
    // Outer loop for rows (1 to 5)
    for (int i = 1; i <= 5; i++) {
        // Inner loop for columns (1 to 5)
        for (int j = 1; j <= 5; j++) {
            // Calculate and print the product
            std::cout << i << " x " << j << " = " << (i * j) << "\t";
        }
        // Move to the next row
        std::cout << std::endl;
    }

    return 0;
}

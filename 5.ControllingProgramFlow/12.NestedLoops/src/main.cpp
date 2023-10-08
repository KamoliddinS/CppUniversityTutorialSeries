#include <iostream>

int main() {
    // Outer loop for rows (1 to 5)
    // for (int i = 1; i <= 5; i++) {
    //     // Inner loop for columns (1 to 5)
    //     for (int j = 1; j <= 5; j++) {
    //         // Calculate and print the product
    //         std::cout << i << " x " << j << " = " << (i * j) << "\t";
    //     }
    //     // Move to the next row
    //     std::cout << std::endl;
    // }


    // Example 2 - Using nested loops to print a triangle
    // for (int i = 1; i <= 5; i++) {
    //     // Inner loop for columns (1 to i)
    //     for (int j = 1; j <= i; j++) {
    //         // Print the column number
    //         std::cout << j << " ";
    //     }
    //     // Move to the next row
    //     std::cout << std::endl;
    // }

    // Example 3  - Iterating over a 2D array
    int array[9][3] = {
        {1, 2, 3}, 
        {4, 5, 6}, 
        {7, 8, 9}, 
        {10, 11, 12}, 
        {13, 14, 15}, 
        {16, 17, 18}, 
        {19, 20, 21}, 
        {22, 23, 24}, 
        {25, 26, 27}
    };

    // Outer loop for rows
    for (int i = 0; i < 9; i++) {
        // Inner loop for columns
        for (int j = 0; j < 3; j++) {
            // Print the element
            std::cout << array[i][j] << " ";
        }
        // Move to the next row
        std::cout << std::endl;
    }

    return 0;
}

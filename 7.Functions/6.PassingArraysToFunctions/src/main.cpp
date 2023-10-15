// main.cpp

#include <iostream> // For input-output stream operations

// Function Prototypes
void printArray(int arr[], int size);
void modifyArray(int arr[], int size);
void print2DArray(int arr[][3], int rows);

int main() {
    // Introduction
    std::cout << "Demonstrating Passing Arrays to Functions in C++\n" << std::endl;

    // One-dimensional Array
    int arr[5] = {1, 2, 3, 4, 5};
    std::cout << "Original Array: ";
    printArray(arr, 5);

    modifyArray(arr, 5);

    std::cout << "Modified Array: ";
    printArray(arr, 5);

    // Two-dimensional Array
    int arr2D[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    std::cout << "\n2D Array:" << std::endl;
    print2DArray(arr2D, 2);

    return 0;
}

// Function Definitions
void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void modifyArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        arr[i] *= 2;  // Double the value
    }
}

void print2DArray(int arr[][3], int rows) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < 3; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


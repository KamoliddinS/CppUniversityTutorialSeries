#include <iostream>

// Function that computes the sum of all elements in an integer array
int sumArrayElements(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    // Define an integer array
    int numbers[] = {1, 2, 3, 4, 5};
    
    // Calculate the size of the array
    int arraySize = sizeof(numbers) / sizeof(numbers[0]);

    // Call the sumArrayElements function, passing the array and its size
    int totalSum = sumArrayElements(numbers, arraySize);

    // Display the sum of the array elements
    std::cout << "Sum of array elements: " << totalSum << std::endl;

    return 0;
}

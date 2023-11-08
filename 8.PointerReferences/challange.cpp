#include <iostream>

int main() {
    int* numberArray = new int[5];

    for (int i = 0; i < 5; ++i) {
        numberArray[i] = i * i;
    }
    // Accordingt to my business logic i use this array and print out the values
    for (int i = 0; i < 5; ++i) {
        std::cout << "numberArray[" << i << "] = " << numberArray[i] << std::endl;
    }


    // Business logic is done
    std::cout << "Program completed." << std::endl;

    return 0;
}






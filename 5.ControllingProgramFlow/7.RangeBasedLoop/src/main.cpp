#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Using a range-based for loop to print elements of a vector
    for (int num : numbers) {
        std::cout << "Number: " << num << std::endl;
    }



    // Example 2 - Using a range-based for loop to print elements of a vector
    std::vector<std::string> names = {"Alice", "Bob", "Charlie"};

    // Using auto with range-based for loop
    for (auto name : names) {
        std::cout << "Name: " << name << std::endl;
    }


    //{1, 2, 3, 4, 5} is collection of values
    for (auto value : {1, 2, 3, 4, 5}) {
        std::cout << "Value: " << value << std::endl;
    }
    return 0;
}

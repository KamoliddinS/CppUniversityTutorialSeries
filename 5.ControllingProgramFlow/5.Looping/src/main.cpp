#include <iostream>

int main() {
    // Initialization: Gathering ingredients and equipment
    std::cout << "Chef's Recipe Loop: Stirring the Sauce" << std::endl;
    int totalStirs = 5;  // We want to stir the sauce 5 times

    // Condition: Stirring the sauce 5 times
    for (int stirCount = 1; stirCount <= totalStirs; stirCount++) {
        // Update: Mark down the number of stirs
        std::cout << "Stir " << stirCount << ": Stirring the sauce..." << std::endl;

        // Simulate stirring action (in a real kitchen, you would stir the sauce)
        // Here, we add a small delay to mimic stirring
        for (int i = 0; i < 10000000; i++) {
            // This loop simulates the time it takes to stir
        }
    }

    // Completion: Finished stirring 5 times
    std::cout << "Sauce is well-stirred! Proceed to the next step." << std::endl;

    return 0;
}

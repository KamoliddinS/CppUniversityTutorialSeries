// main.cpp
#include <iostream>

// Using const keyword
const double PI = 3.141592653589793238;

// Using #define preprocessor
#define MAX_USERS 100

// Using constexpr
constexpr int maxAttempts = 5;

// Using enum
enum DaysOfWeek {
    MONDAY = 1,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

int main() {
    int users = 45;
    int loginAttempts = 3;
    DaysOfWeek today = WEDNESDAY;
    // MAX_USERS = 200; // This will throw an error
    // Checking against the MAX_USERS constant
    if (users < MAX_USERS) {
        std::cout << "More users can be added. Space for " << MAX_USERS - users << " more users." << std::endl;
    }
    
    // Displaying value of PI
    std::cout << "Value of PI: " << PI << std::endl;

    // Checking against the maxAttempts constant
    if (loginAttempts < maxAttempts) {
        std::cout << "You have " << maxAttempts - loginAttempts << " more attempts left." << std::endl;
    }

    // Using enum constant
    if (today == WEDNESDAY) {
        std::cout << "Today is Wednesday!" << std::endl;
    }

    return 0;
}

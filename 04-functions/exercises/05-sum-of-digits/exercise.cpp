// Exercise 5: Sum of digits
// Complete digitSum at the TODO mark. Use recursion: the function calls
// itself, and it has no loop.
// Do not change check and main: they test your function.
#include <iostream>
#include <string>

// Returns the sum of the digits of number. number is 0 or more.
// Example: digitSum(472) is 4 + 7 + 2 = 13.
int digitSum(int number) {
    // TODO: this is right for a number with one digit only.
    //       Write the base case and the recursive case.
    return number;
}

// Prints a message when a check fails. Returns 1 for a failed check and 0 for a passed one.
int check(bool ok, const std::string& what) {
    if (ok) {
        return 0;
    }
    std::cout << "FAILED: " << what << '\n';
    return 1;
}

int main() {
    int failed = 0;

    failed += check(digitSum(0) == 0, "digitSum(0) is 0");
    failed += check(digitSum(7) == 7, "digitSum(7) is 7");
    failed += check(digitSum(10) == 1, "digitSum(10) is 1");
    failed += check(digitSum(472) == 13, "digitSum(472) is 13");
    failed += check(digitSum(2026) == 10, "digitSum(2026) is 10");
    failed += check(digitSum(99999) == 45, "digitSum(99999) is 45");

    if (failed > 0) {
        return 1;
    }
    std::cout << "All checks passed.\n";
}

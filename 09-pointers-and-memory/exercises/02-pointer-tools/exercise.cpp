// Exercise 2: Pointer tools
// Complete the two functions at the TODO marks.
// Do not change check and main: they test your functions.
#include <cstddef>
#include <iostream>
#include <string>

// Swaps the two ints that a and b point to.
void swapValues(int* a, int* b) {
    // TODO: these two lines lose the old value of *a. Make it a real swap.
    *a = *b;
    *b = *a;
}

// Returns a pointer to the first element that is equal to target,
// or nullptr when no element is.
const int* findFirst(const int* values, std::size_t size, int target) {
    // TODO: this looks at values[0] only. Look at all `size` elements.
    if (size > 0 && values[0] == target) {
        return values;
    }
    return nullptr;
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

    int x = 3;
    int y = 8;
    swapValues(&x, &y);
    failed += check(x == 8 && y == 3, "after swapValues(&x, &y), x is 8 and y is 3");

    int prices[5] = {700, 1200, 500, 1200, 900};
    failed += check(findFirst(prices, 5, 1200) == prices + 1, "the first 1200 is prices[1]");
    failed += check(findFirst(prices, 5, 900) == prices + 4, "900 is prices[4]");
    failed += check(findFirst(prices, 5, 800) == nullptr, "800 is not there: nullptr");
    failed += check(findFirst(prices, 0, 700) == nullptr, "an empty array holds no 700: nullptr");

    if (failed > 0) {
        return 1;
    }
    std::cout << "All checks passed.\n";
}

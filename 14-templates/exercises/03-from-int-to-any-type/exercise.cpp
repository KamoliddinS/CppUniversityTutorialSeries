// Exercise 3: From int to any type
// This file does not compile yet: both functions work only for int.
// Turn each one into a function template. Do not change check and main.
#include <iostream>
#include <string>
#include <vector>

// Exchanges the values of a and b.
// TODO: make this a function template.
void swapValues(int& a, int& b) {
    int old = a;
    a = b;
    b = old;
}

// Returns how many elements of items are equal to wanted.
// TODO: make this a function template. Careful: not every int here is the type of an element.
int countMatches(const std::vector<int>& items, int wanted) {
    int count = 0;
    for (int item : items) {
        if (item == wanted) {
            count = count + 1;
        }
    }
    return count;
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

    int small = 3;
    int big = 8;
    swapValues(small, big);
    failed += check(small == 8 && big == 3, "swapValues with int");

    std::string first = "Aziz";
    std::string second = "Malika";
    swapValues(first, second);
    failed += check(first == "Malika" && second == "Aziz", "swapValues with std::string");

    std::vector<int> grades{5, 3, 5, 4, 5};
    failed += check(countMatches(grades, 5) == 3, "countMatches with int");
    failed += check(countMatches(grades, 2) == 0, "countMatches with a value that is not there");

    std::vector<char> letters{'a', 'n', 'a', 'n', 'a', 's'};
    failed += check(countMatches(letters, 'a') == 3, "countMatches with char");

    std::vector<std::string> cities{"Khiva", "Bukhara", "Khiva"};
    std::string wanted = "Khiva";
    failed += check(countMatches(cities, wanted) == 2, "countMatches with std::string");

    if (failed > 0) {
        return 1;
    }
    std::cout << "All checks passed.\n";
}

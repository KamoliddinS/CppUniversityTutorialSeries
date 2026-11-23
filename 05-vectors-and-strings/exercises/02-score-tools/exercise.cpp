// Exercise 2: Score tools
// Complete the three functions at the TODO marks.
// Do not change check and main: they test your functions.
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

// Returns the largest score. The list is never empty.
int largest(const std::vector<int>& scores) {
    int best = scores[0];
    // TODO: look at every score and keep the largest one in best.
    return best;
}

// Adds every score of more to the end of scores.
void append(std::vector<int>& scores, const std::vector<int>& more) {
    if (!more.empty()) {
        scores.push_back(more[0]);      // TODO: this adds only the first score of more.
    }
}

// Returns a new list with the same scores in the opposite order.
std::vector<int> reversed(const std::vector<int>& scores) {
    std::vector<int> result = scores;
    // TODO: result is a plain copy now. Put the scores into it in the opposite order.
    return result;
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

    // A list in braces becomes a vector for the call.
    failed += check(largest({72, 45, 90, 60}) == 90, "largest of 72 45 90 60 is 90");
    failed += check(largest({-5, -2, -9}) == -2, "largest of -5 -2 -9 is -2");

    std::vector<int> scores = {72, 85};
    append(scores, {90, 64});
    // == is true when two vectors have the same elements in the same order.
    failed += check(scores == std::vector<int>{72, 85, 90, 64}, "72 85 and 90 64 make 72 85 90 64");
    std::vector<int> one = {7};
    append(one, {});
    failed += check(one.size() == 1, "an empty list adds nothing");

    failed += check(reversed({1, 2, 3}) == std::vector<int>{3, 2, 1}, "1 2 3 reversed is 3 2 1");
    failed += check(reversed({4, 8}) == std::vector<int>{8, 4}, "4 8 reversed is 8 4");
    failed += check(reversed({}).empty(), "an empty list reversed is empty");

    if (failed > 0) {
        return 1;
    }
    std::cout << "All checks passed.\n";
}

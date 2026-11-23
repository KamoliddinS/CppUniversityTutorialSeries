// Exercise 6: Word count
// Read words until the input ends. Print every different word once, in alphabetical
// order, with the number of times it appears. Then print the number of words.
// The exercise page gives the details and an example.
#include <algorithm>
#include <cctype>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

// Returns the word in small letters, without the characters that are not letters:
// "Dog!" becomes "dog", and "2026" becomes "" (an empty string).
std::string clean(const std::string& word) {
    // TODO: build the cleaned word and return it.
    return word;
}

int main() {
    std::vector<std::string> words;

    // TODO: read every word, clean it, and add it to words when it is not empty.

    // TODO: print each different word with its count, in alphabetical order.

    std::cout << "Words: " << words.size() << '\n';
}

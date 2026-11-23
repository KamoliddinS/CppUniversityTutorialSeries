// Exercise 4: Pair
// This file does not compile yet: the class template Pair is missing.
// Write it where the TODO is. Do not change main.
#include <iostream>
#include <string>

// TODO: write the class template Pair here.

int main() {
    Pair<std::string, int> student("Dilnoza", 19);
    std::cout << student.first() << " is " << student.second() << '\n';

    Pair<double, std::string> melon(2.5, "kg");
    std::cout << melon.first() << ' ' << melon.second() << '\n';

    Pair<int, std::string> turned = student.swapped();
    std::cout << turned.first() << ' ' << turned.second() << '\n';
}

// Exercise 4: Balanced brackets
// Read one line. Print "balanced" if every bracket ( [ { is closed by the matching
// bracket ) ] } in the right order. Otherwise print "not balanced".
#include <iostream>
#include <stack>
#include <string>

int main() {
    std::string line;
    std::getline(std::cin, line);

    std::stack<char> open;      // the brackets that are still open

    // TODO: look at every character of the line.
    //       An opening bracket goes on the stack.
    //       A closing bracket must match the bracket on top of the stack.

    std::cout << "TODO\n";
}

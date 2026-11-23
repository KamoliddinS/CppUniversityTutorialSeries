#include <iostream>
#include <stack>

int main() {
    std::stack<int> undo;
    undo.push(7);
    int last = undo.pop();
    std::cout << last << '\n';
}

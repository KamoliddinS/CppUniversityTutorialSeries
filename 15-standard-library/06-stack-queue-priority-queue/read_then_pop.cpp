#include <iostream>
#include <stack>

int main() {
    std::stack<int> undo;
    undo.push(7);

    if (!undo.empty()) {           // never read or pop an empty stack
        int last = undo.top();     // read ...
        undo.pop();                // ... then remove
        std::cout << last << '\n';
    }
}

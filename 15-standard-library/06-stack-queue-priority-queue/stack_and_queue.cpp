#include <iostream>
#include <queue>
#include <stack>

int main() {
    std::stack<int> stack;
    std::queue<int> queue;
    for (int value = 1; value <= 4; ++value) {     // put in 1, 2, 3, 4
        stack.push(value);
        queue.push(value);
    }

    std::cout << "stack: ";
    while (!stack.empty()) {
        std::cout << stack.top() << ' ';           // read the element ...
        stack.pop();                               // ... then remove it
    }
    std::cout << "\nqueue: ";
    while (!queue.empty()) {
        std::cout << queue.front() << ' ';
        queue.pop();
    }
    std::cout << '\n';
}

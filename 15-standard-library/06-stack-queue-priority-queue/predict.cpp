#include <iostream>
#include <queue>
#include <stack>

int main() {
    std::stack<int> stack;
    std::queue<int> queue;
    for (int value = 1; value <= 3; ++value) {
        stack.push(value);
        queue.push(value);
    }
    stack.pop();
    queue.pop();
    stack.push(9);
    queue.push(9);

    std::cout << stack.top() << ' ' << queue.front() << ' ' << queue.size() << '\n';
}

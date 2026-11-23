#include <iostream>
#include <vector>

class Stack {
public:
    void push(int value) { items_.push_back(value); }
    void pop() { items_.pop_back(); }
    int top() const { return items_.back(); }
    bool empty() const { return items_.empty(); }

private:
    std::vector<int> items_;    // a Stack HAS a vector
};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // stack[0] = 99;   // error now: a Stack has no []

    while (!stack.empty()) {
        std::cout << stack.top() << ' ';
        stack.pop();
    }
    std::cout << '\n';
}

#include <iostream>
#include <vector>

class Stack : public std::vector<int> {     // "a Stack IS a vector": not true
public:
    void push(int value) { push_back(value); }
    void pop() { pop_back(); }
    int top() const { return back(); }
};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack[0] = 99;      // a vector function: it changes the bottom of the stack

    while (!stack.empty()) {
        std::cout << stack.top() << ' ';
        stack.pop();
    }
    std::cout << '\n';
}

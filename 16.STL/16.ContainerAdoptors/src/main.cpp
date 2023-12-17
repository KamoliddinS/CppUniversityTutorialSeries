#include <iostream>
#include <stack>
#include <queue>
#include <functional> // For greater (used in priority_queue)

int main() {
    // Demonstrating stack
    std::stack<int> numStack;
    numStack.push(1);
    numStack.push(2);
    numStack.push(3);
    std::cout << "Stack top: " << numStack.top() << std::endl;
    numStack.pop();
    std::cout << "Stack top after pop: " << numStack.top() << std::endl;

    // Demonstrating queue
    std::queue<int> numQueue;
    numQueue.push(1);
    numQueue.push(2);
    numQueue.push(3);
    std::cout << "Queue front: " << numQueue.front() << " and back: " << numQueue.back() << std::endl;
    numQueue.pop();
    std::cout << "Queue front after pop: " << numQueue.front() << std::endl;

    // Demonstrating priority_queue
    std::priority_queue<int, std::vector<int>, std::greater<int>> numPQueue; // Min-heap
    numPQueue.push(3);
    numPQueue.push(1);
    numPQueue.push(2);
    std::cout << "Priority queue top: " << numPQueue.top() << std::endl;
    numPQueue.pop();
    std::cout << "Priority queue top after pop: " << numPQueue.top() << std::endl;

    return 0;
}

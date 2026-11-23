#ifndef STACK_H
#define STACK_H

#include <cstddef>
#include <stdexcept>
#include <vector>

template <typename T>
class Stack {
public:
    void push(const T& value) { items_.push_back(value); }

    void pop() {
        if (items_.empty()) {
            throw std::out_of_range("the stack is empty");
        }
        items_.pop_back();
    }

    const T& top() const {
        if (items_.empty()) {
            throw std::out_of_range("the stack is empty");
        }
        return items_.back();
    }

    bool empty() const { return items_.empty(); }
    std::size_t size() const { return items_.size(); }

private:
    std::vector<T> items_;
};

#endif

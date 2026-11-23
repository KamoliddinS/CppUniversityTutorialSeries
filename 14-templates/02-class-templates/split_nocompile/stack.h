#ifndef STACK_H
#define STACK_H

#include <cstddef>
#include <vector>

template <typename T>
class Stack {
public:
    void push(const T& value);     // the bodies are in stack.cpp
    std::size_t size() const;

private:
    std::vector<T> items_;
};

#endif

#include "stack.h"

template <typename T>
void Stack<T>::push(const T& value) {
    items_.push_back(value);
}

template <typename T>
std::size_t Stack<T>::size() const {
    return items_.size();
}

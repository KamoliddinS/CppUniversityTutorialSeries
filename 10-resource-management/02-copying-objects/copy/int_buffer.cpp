#include "int_buffer.h"

#include <iostream>

IntBuffer::IntBuffer(const IntBuffer& other) : size_(other.size_), data_(new int[other.size_]) {
    std::cout << "  copy constructor\n";
    for (std::size_t i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];          // copy the values, not the address
    }
}

IntBuffer& IntBuffer::operator=(const IntBuffer& other) {
    std::cout << "  copy assignment\n";
    if (this != &other) {                   // a = a; must change nothing
        delete[] data_;                     // give back the block held so far
        size_ = other.size_;
        data_ = new int[size_];
        for (std::size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
    return *this;
}

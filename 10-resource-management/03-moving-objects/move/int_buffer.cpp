#include "int_buffer.h"

#include <iostream>

IntBuffer::IntBuffer(const IntBuffer& other) : size_(other.size_), data_(new int[other.size_]) {
    std::cout << "  copy constructor\n";
    for (std::size_t i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
    }
}

IntBuffer& IntBuffer::operator=(const IntBuffer& other) {
    std::cout << "  copy assignment\n";
    if (this != &other) {
        delete[] data_;
        size_ = other.size_;
        data_ = new int[size_];
        for (std::size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
    return *this;
}

IntBuffer::IntBuffer(IntBuffer&& other) noexcept : size_(other.size_), data_(other.data_) {
    std::cout << "  move constructor\n";
    other.size_ = 0;
    other.data_ = nullptr;                  // other is empty: its destructor deletes nothing
}

IntBuffer& IntBuffer::operator=(IntBuffer&& other) noexcept {
    std::cout << "  move assignment\n";
    if (this != &other) {
        delete[] data_;                     // give back the block held so far
        size_ = other.size_;
        data_ = other.data_;                // take over the block of other
        other.size_ = 0;
        other.data_ = nullptr;
    }
    return *this;
}

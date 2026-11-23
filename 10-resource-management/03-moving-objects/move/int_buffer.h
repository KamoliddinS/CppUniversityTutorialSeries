#ifndef INT_BUFFER_H
#define INT_BUFFER_H

#include <cstddef>

class IntBuffer {
public:
    explicit IntBuffer(std::size_t size) : size_(size), data_(new int[size]{}) {}

    ~IntBuffer() { delete[] data_; }                    // 1 destructor
    IntBuffer(const IntBuffer& other);                  // 2 copy constructor
    IntBuffer& operator=(const IntBuffer& other);       // 3 copy assignment operator
    IntBuffer(IntBuffer&& other) noexcept;              // 4 move constructor
    IntBuffer& operator=(IntBuffer&& other) noexcept;   // 5 move assignment operator

    int& operator[](std::size_t index) { return data_[index]; }
    std::size_t size() const { return size_; }

private:
    std::size_t size_ = 0;
    int* data_ = nullptr;
};

#endif

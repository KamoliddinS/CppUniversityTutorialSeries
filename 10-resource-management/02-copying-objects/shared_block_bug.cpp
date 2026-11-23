#include <cstddef>
#include <iostream>

class IntBuffer {
public:
    explicit IntBuffer(std::size_t size) : size_(size), data_(new int[size]{}) {}
    ~IntBuffer() { delete[] data_; }
    int& operator[](std::size_t index) { return data_[index]; }
    std::size_t size() const { return size_; }

private:
    std::size_t size_ = 0;
    int* data_ = nullptr;
};

int main() {
    IntBuffer a(3);
    a[0] = 7;

    IntBuffer b = a;        // copies the members: b.data_ gets the address in a.data_
    b[0] = 99;

    std::cout << "a[0] = " << a[0] << '\n';
}   // b is destroyed, then a: the same block is deleted twice

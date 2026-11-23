#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>

class IntBuffer {
public:
    explicit IntBuffer(std::size_t size) : data_(size) {}       // a vector of size zeros
    int& operator[](std::size_t index) { return data_[index]; }
    std::size_t size() const { return data_.size(); }

private:
    std::vector<int> data_;         // the vector owns the memory
};

int main() {
    IntBuffer a(3);
    a[0] = 7;

    IntBuffer b = a;                // copies the vector: b gets its own elements
    b[0] = 99;
    std::cout << "a[0] = " << a[0] << ", b[0] = " << b[0] << '\n';

    IntBuffer c = std::move(a);     // moves the vector: c takes over the elements of a
    std::cout << "a has " << a.size() << " ints, c has " << c.size() << '\n';
}

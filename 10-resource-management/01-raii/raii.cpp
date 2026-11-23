#include <cstddef>
#include <iostream>

class IntBuffer {
public:
    explicit IntBuffer(std::size_t size) : size_(size), data_(new int[size]{}) {
        std::cout << "  take " << size_ << " ints\n";
    }
    ~IntBuffer() {
        std::cout << "  give back " << size_ << " ints\n";
        delete[] data_;
    }
    int& operator[](std::size_t index) { return data_[index]; }
    std::size_t size() const { return size_; }

private:
    std::size_t size_ = 0;
    int* data_ = nullptr;
};

void report(std::size_t days) {
    IntBuffer visitors(days);
    if (days < 7) {
        std::cout << "Need at least a week of data.\n";
        return;                             // the destructor runs here ...
    }
    visitors[0] = 120;
    std::cout << "First day: " << visitors[0] << " visitors\n";
}                                           // ... and here

int main() {
    report(7);
    report(3);
}

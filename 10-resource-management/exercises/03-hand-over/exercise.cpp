// Exercise 3: Hand over
// A Photo owns a block of pixels. Complete the two TODO functions,
// so that a Photo can be moved. Do not change main.
#include <cstddef>
#include <iostream>
#include <utility>

class Photo {
public:
    explicit Photo(std::size_t size) : size_(size), pixels_(new int[size]{}) {}
    ~Photo() { delete[] pixels_; }

    Photo(Photo&& other) noexcept {
        // TODO: take over the block of other, then leave other empty (size 0, nullptr).
    }
    Photo& operator=(Photo&& other) noexcept {
        // TODO: give back your own block, take over the block of other, leave other empty.
        return *this;
    }

    std::size_t size() const { return size_; }
    const int* pixels() const { return pixels_; }

private:
    std::size_t size_ = 0;
    int* pixels_ = nullptr;
};

int main() {
    Photo a(4);
    const int* block = a.pixels();      // the address of the block that a owns
    Photo b = std::move(a);             // move constructor
    std::cout << "a has " << a.size() << " pixels, b has " << b.size() << '\n';
    Photo c(2);
    c = std::move(b);                   // move assignment
    std::cout << "b has " << b.size() << " pixels, c has " << c.size() << '\n';

    if (c.pixels() == block && a.pixels() == nullptr && b.pixels() == nullptr) {
        std::cout << "The block changed its owner twice and was never copied.\n";
    }
}

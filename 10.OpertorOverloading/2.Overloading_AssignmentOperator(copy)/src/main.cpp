#include <iostream>
#include <algorithm> // for std::swap

// A simple Widget class that requires deep copying.
class Widget {
public:
    // Constructor
    Widget(int size) : size_(size), data_(new int[size]) {
        std::fill_n(data_, size_, 0); // Initialize array with zeroes
    }

    // Destructor to clean up the allocated memory
    ~Widget() {
        delete[] data_;
    }

    // Copy constructor for deep copying
    Widget(const Widget& other) : size_(other.size_), data_(new int[other.size_]) {
        std::copy(other.data_, other.data_ + size_, data_);
    }

    // Overloaded assignment operator
    Widget& operator=(Widget rhs) {
        // Swap the contents of the passed object with 'this' object
        swap(*this, rhs);
        // 'rhs' now holds the old data of this object and will be destructed safely
        return *this;
    }

    // Friend swap function to swap two Widgets
    friend void swap(Widget& first, Widget& second) noexcept {
        // Enable ADL (not necessary in our case, but good practice)
        using std::swap;

        // Swap all members of 'first' and 'second'
        swap(first.size_, second.size_);
        swap(first.data_, second.data_);
    }

    // Utility function to print the contents of the Widget
    void print() const {
        for (int i = 0; i < size_; ++i) {
            std::cout << data_[i] << ' ';
        }
        std::cout << std::endl;
    }

private:
    int size_; // The size of the data array
    int* data_; // Pointer to the data array
};

int main() {
    // Create two Widget objects
    Widget a(10); // a Widget with size 10
    Widget b(5); // a Widget with size 5

    // Print their contents
    std::cout << "Widget A before assignment: ";
    a.print();
    std::cout << "Widget B before assignment: ";
    b.print();

    // Assign b to a
    a = b;

    // Print their contents again
    std::cout << "Widget A after assignment: ";
    a.print();
    std::cout << "Widget B after assignment (should be unchanged): ";
    b.print();

    return 0;
}

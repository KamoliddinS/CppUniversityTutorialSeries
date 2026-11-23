// Exercise 5: Growing list
// Read whole numbers until the input ends. Keep them in a heap array that grows.
// Then print the count, the numbers in reverse order, and the largest number.
// Complete the TODO parts (see the exercise text).
#include <cstddef>
#include <iostream>

// TODO: write the function
//     int* grow(int* old, std::size_t size, std::size_t newCapacity)
// It creates a heap array with room for newCapacity ints, copies the first
// `size` ints of `old` into it, deletes the old array and returns the new one.

// TODO: write the function
//     const int* largest(const int* values, std::size_t size)
// It returns a pointer to the largest of the `size` ints,
// or nullptr when size is 0.

int main() {
    std::size_t capacity = 2;       // how many ints fit in the array
    std::size_t size = 0;           // how many ints are stored
    int* values = new int[capacity]{};

    int number = 0;
    while (std::cin >> number) {
        if (size == capacity) {
            // TODO: double the capacity and let grow() make the larger array.
            break;                  // remove this line when the array can grow
        }
        values[size] = number;
        ++size;
    }

    std::cout << "Count: " << size << '\n';
    // TODO: print "Reversed:" and then the numbers from the last to the first.
    // TODO: print "Largest: " and the largest number, or "Largest: none".
    // TODO: give the memory back.
}

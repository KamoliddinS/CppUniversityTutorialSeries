#include <iostream>

// Function to demonstrate a memory leak with a raw pointer
void memory_leak_example() {
    int* leaky_ptr = new int(42);  // Memory allocated here is never deallocated
    std::cout << "Memory leak example value: " << *leaky_ptr << std::endl;
    // Correct usage would require delete leaky_ptr; here
}

// Function to demonstrate a dangling pointer
void dangling_pointer_example() {
    int* dangling_ptr = new int(42);
    delete dangling_ptr;  // The memory is deallocated here
    // dangling_ptr is now a dangling pointer. Any further operation is undefined.
    // For instance: std::cout << "Dangling pointer value: " << *dangling_ptr << std::endl;
    // It is a good practice to set the pointer to nullptr after deletion.
    dangling_ptr = nullptr;
}

// Function to demonstrate double free
void double_free_example() {
    int* double_free_ptr = new int(42);
    delete double_free_ptr;  // Memory is deallocated here
    // delete double_free_ptr; // This would be a double free. Uncommenting this line is undefined behavior and should be avoided.
    double_free_ptr = nullptr;  // Avoid dangling pointers by setting it to nullptr
}

// Function to demonstrate incorrect deallocation
void incorrect_deallocation_example() {
    int* array_ptr = new int[10];  // Allocate array
    delete[] array_ptr;  // Correct deallocation
    // delete array_ptr;  // Incorrect deallocation. Should not be used. This is a common mistake.
}

// Function to demonstrate ownership ambiguity
void ownership_ambiguity_example() {
    int* shared_ptr = new int(42);  // Who owns this pointer?
    // Some code that might delete or not delete shared_ptr
    // This ambiguity can lead to double deletes or memory leaks
    delete shared_ptr;  // Let's assume we correctly delete it here
}

// A thread-unsafe function that could be called from multiple threads
void thread_unsafe_allocation(int value) {
    static int* unsafe_ptr = new int(value);  // Static allocation shared between threads
    // Simulate work
    *unsafe_ptr = value * 2;
    std::cout << "Thread-unsafe allocation value: " << *unsafe_ptr << std::endl;
    // Deletion or re-allocation in a multithreaded context would be unsafe
}

int main() {
    memory_leak_example();
    dangling_pointer_example();
    double_free_example();
    incorrect_deallocation_example();
    ownership_ambiguity_example();
    thread_unsafe_allocation(42);

    // Caution: This code contains deliberate errors to demonstrate bad practices with raw pointers.
    // Do not use this as a reference for correct memory management.
    return 0;
}

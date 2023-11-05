#include <iostream>

int main() {
    // Pitfall 1: Uninitialized Pointer
    int *uninitializedPtr;  // Uninitialized pointer
    // *uninitializedPtr = 5;  // This is dangerous and undefined behavior. Commented to prevent crash.
    // Solution: Initialize pointers
    int *initializedPtr = nullptr;

    // Pitfall 2: Dangling Pointer
    int *danglingPtr = new int(10);
    delete danglingPtr; // The memory is freed
    danglingPtr = nullptr; // Solution: Set to nullptr to avoid dangling

    // Pitfall 3: Memory Leak
    int *memoryLeakPtr = new int(10);
    // Forgot to delete memoryLeakPtr, memory is not freed and we lose the reference to it
    // Solution: Always delete dynamically allocated memory
    // delete memoryLeakPtr;

    // Pitfall 4: Mismatched new[] and delete
    int *arrayPtr = new int[10];
    // delete arrayPtr; // Wrong! This causes undefined behavior.
    // Solution: Use delete[] for arrays
    delete[] arrayPtr;

    // Pitfall 5: Wild Pointer
    int *wildPtr = new int(10);
    delete wildPtr;
    wildPtr = nullptr; // Solution: Set wildPtr to nullptr after delete

    // Pitfall 6: Off-by-one Error
    int array[10];
    // int *offByOnePtr = array + 10; // Points just past the end of the array
    // Solution: Careful with pointer arithmetic
    int *withinBoundsPtr = array + 9; // Last element is at index 9

    // Pitfall 7: Void Pointer Dereference
    void *voidPtr = new int(10);
    // *voidPtr = 10; // Error: Cannot dereference a void pointer
    // Solution: Cast to the appropriate type before dereferencing
    *(static_cast<int*>(voidPtr)) = 10;
    delete static_cast<int*>(voidPtr);

    // Pitfall 8: Function Pointer Mismatches
    void (*funcPtr)(void); // Function pointer with no arguments
    // funcPtr = reinterpret_cast<void (*)(void)>(someOtherFunction); // Mismatch if someOtherFunction's signature is different
    // Solution: Match the function signatures exactly

    std::cout << "Pointer pitfalls demonstrated with solutions." << std::endl;

    return 0;
}

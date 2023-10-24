#include <iostream>

using namespace std;

// Global variable
int globalVar = 100;

// Function that returns a pointer to a global variable
int* getGlobalPointer() {
    return &globalVar;  // Safe because globalVar exists beyond the function scope
}

// Function that returns a pointer to dynamic memory
int* createDynamicArray(int size) {
    int* arr = new int[size];
    for(int i = 0; i < size; i++) {
        arr[i] = i;
    }
    return arr;  // Returning dynamically allocated memory. Caller is responsible for deallocation.
}

// Function that dangerously returns a pointer to a local variable
int* unsafeFunction() {
    int localVariable = 10;
    return &localVariable;  // DANGEROUS! localVariable goes out of scope after function exits.
}

int main() {
    // Using the function that returns a pointer to a global variable
    int* globalPtr = getGlobalPointer();
    cout << "Value pointed by global pointer: " << *globalPtr << endl;  // Expected output: 100

    // Using the function that returns dynamically allocated memory
    int size = 5;
    int* dynamicArr = createDynamicArray(size);
    cout << "Dynamic array: ";
    for(int i = 0; i < size; i++) {
        cout << dynamicArr[i] << " ";  // Expected output: 0 1 2 3 4
    }
    cout << endl;
    delete[] dynamicArr;  // Deallocating the memory to avoid memory leak

    // Using the unsafe function (Not recommended!)
    // int* unsafePtr = unsafeFunction();
    // cout << *unsafePtr << endl;  // UNDEFINED BEHAVIOR! Uncommenting and executing might lead to unexpected results.

    return 0;
}

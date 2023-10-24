#include <iostream>

using namespace std;

int main() {
    // Declare an array
    int arr[5] = {10, 20, 30, 40, 50};

    // The array name represents the address of the first element
    int* p = arr;  
    cout << "Address of the first element using array name: " << arr << endl;
    cout << "Address of the first element using pointer: " << p << endl;

    // Accessing array elements using pointer
    cout << "\nElement at index 0: " << *p << endl;
    p++;  // Pointer arithmetic: moving to the next element
    cout << "Element at index 1: " << *p << endl;

    // Pointer arithmetic to traverse the array
    p = arr;  // Resetting pointer to start of the array
    for (int i = 0; i < 5; i++) {
        cout << "Element at index " << i << ": " << *(p + i) << endl;  // Using addition
    }

    // Size differences
    cout << "\nSize of the array: " << sizeof(arr) << " bytes" << endl;
    cout << "Size of the pointer: " << sizeof(p) << " bytes" << endl;

    // Array name is a constant pointer: the following would be an error
    // arr = &arr[1];  // Uncommenting this would cause a compile-time error

    // Modifying array elements using pointer
    p = arr;  // Resetting pointer to start of the array
    *p = 100;  // Modifying the first element
    cout << "\nModified first element of the array: " << arr[0] << endl;

    return 0;
}

#include <iostream>

using namespace std;

int main() {
    // Declaring an integer and a pointer to it
    int val = 20;
    int *ptr = &val;

    // Declaring a pointer to the pointer (ptr)
    int **pptr = &ptr;

    // Accessing the value of 'val' using pointer to pointer
    cout << "Value of val: " << **pptr << endl;  // Expected: 20

    // Pointer addresses
    cout << "Address of val: " << &val << endl;          // Address of 'val'
    cout << "Address stored in ptr: " << ptr << endl;   // Address of 'val'
    cout << "Address of ptr: " << &ptr << endl;         // Address of 'ptr'
    cout << "Address stored in pptr: " << pptr << endl; // Address of 'ptr'

    // Dynamic allocation of 2D array
    int rows = 2, cols = 3;
    int **arr = new int*[rows];
    for(int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

    // Initializing and printing the 2D array using pointer to pointer
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            arr[i][j] = i * j; // Some random values for demonstration
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocation of the 2D array
    for(int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}

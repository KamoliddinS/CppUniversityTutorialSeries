#include <iostream>

using namespace std;

int main() {
    // Dynamically allocating memory for a single integer
    int* ptr = new int;    // Allocation
    *ptr = 10;             // Initialization

    // Printing the dynamically allocated integer
    cout << "Dynamically allocated integer value: " << *ptr << endl;

    // Releasing the memory and setting the pointer to nullptr
    delete ptr;
    ptr = nullptr;

    // Checking if memory is released
    if (ptr == nullptr)
        cout << "Memory for integer is released and pointer is set to nullptr." << endl;

    // Dynamically allocating memory for an array of integers
    int size = 5;
    int* arr = new int[size];  // Allocation
    for(int i = 0; i < size; i++)
        arr[i] = i*10;         // Initialization

    // Printing the dynamically allocated array
    cout << "\nDynamically allocated array values:" << endl;
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Releasing the memory for the array and setting the pointer to nullptr
    delete[] arr;
    arr = nullptr;

    // Checking if memory for the array is released
    if (arr == nullptr)
        cout << "Memory for array is released and pointer is set to nullptr." << endl;

    return 0;

    //  int *int_ptr {nullptr};
    // int_ptr = new int;               // allocate the int on the heap
    // cout << int_ptr << endl;    // use it
    // delete int_ptr;                    // release it
    
    // size_t size{0};
    // double *temp_ptr {nullptr};
    
    // cout << "How many temps? ";
    // cin >> size;
    
    // temp_ptr = new double[size];    // allocate the storage on the heap
    // cout << temp_ptr << endl;       // use it
    // delete [] temp_ptr;                     // release it
    
    // cout << endl;
    // return 0;
}

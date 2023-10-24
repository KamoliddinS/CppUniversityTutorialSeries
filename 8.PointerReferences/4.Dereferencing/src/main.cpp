#include <iostream>

using namespace std;

int main() {
    // Basics of Dereferencing
    cout << "---- Basics of Dereferencing ----" << endl;

    int number = 42;
    int* numberPtr = &number;

    cout << "Value of 'number': " << number << endl;
    cout << "Address of 'number': " << &number << endl;
    cout << "Value inside 'numberPtr' (Address of 'number'): " << numberPtr << endl;

    // Dereferencing Operator
    cout << "\n---- Dereferencing Operator ----" << endl;

    cout << "Dereferencing 'numberPtr' gives the value at its address: " << *numberPtr << endl;

    // Dereferencing to Access Data
    cout << "\n---- Dereferencing to Access Data ----" << endl;

    cout << "Value pointed by 'numberPtr': " << *numberPtr << endl;

    // Dereferencing to Modify Data
    cout << "\n---- Dereferencing to Modify Data ----" << endl;

    *numberPtr = 99;
    cout << "Value of 'number' after modification through pointer: " << number << endl;

    // Note on Dereferencing Uninitialized Pointers
    cout << "\n---- Note on Dereferencing Uninitialized Pointers ----" << endl;

    int* uninitializedPtr;
    // Uncommenting the following line can lead to undefined behavior as the pointer is uninitialized.
    // cout << *uninitializedPtr << endl;

    cout << "Always ensure pointers are initialized before dereferencing to avoid undefined behavior." << endl;

    // Key Takeaways
    cout << "\n---- Key Takeaways ----" << endl;
    cout << "1. Dereferencing allows access to the value to which a pointer points." << endl;
    cout << "2. The value at the memory location a pointer points to can be both accessed and modified using dereferencing." << endl;
    cout << "3. Always ensure pointers are initialized to a valid address or nullptr before dereferencing." << endl;

    return 0;
}

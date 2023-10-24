#include <iostream>

using namespace std;

int main() {
    // Declare an integer array
    int arr[5] = {10, 20, 30, 40, 50};

    // Declare an integer pointer and point it to the start of the array
    int* ptr = arr;

    // Print the initial address the pointer is pointing to
    cout << "Initial address: " << ptr << endl;

    // Increment the pointer and display the address after incrementing
    ptr++;
    cout << "Address after incrementing: " << ptr << endl;

    // Decrement the pointer and display the address after decrementing
    ptr--;
    cout << "Address after decrementing: " << ptr << endl;

    // Add 3 to the pointer to jump to the fourth element and display its value
    ptr += 3;
    cout << "Value after adding 3: " << *ptr << endl;  // Outputs 40

    // Subtract 2 from the pointer to jump to the second element and display its value
    ptr -= 2;
    cout << "Value after subtracting 2: " << *ptr << endl;  // Outputs 20

    // Declare another pointer pointing to the end of the array
    int* ptrEnd = &arr[4];

    // Calculate the difference between the two pointers
    int diff = ptrEnd - ptr;
    cout << "Difference between ptrEnd and ptr: " << diff << endl;  // Outputs 3

    // Pointer arithmetic scales according to the size of data type.
    // Let's demonstrate with a double array
    double dArr[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double* dPtr = dArr;

    // Print the initial address the double pointer is pointing to
    cout << "\nInitial address (double array): " << dPtr << endl;

    // Increment the pointer and display the address after incrementing
    dPtr++;
    cout << "Address after incrementing (double array): " << dPtr << endl;

    // Notice how the address increment for double is larger due to larger size of double compared to int

    return 0;

    // int scores[] {100, 95, 89, 68, -1};
    // int *score_ptr {scores};
    
    // while (*score_ptr != -1) {
    //     cout << *score_ptr << endl;
    //     score_ptr++;
    // }
    
    // cout << "\n-------------------------" << endl;
    // score_ptr = scores;
    // while (*score_ptr != -1)
    //     cout << *score_ptr++ << endl;
        
    // cout << "\n-------------------------" << endl;
    // string s1 {"Frank"};
    // string s2 {"Frank"};
    // string s3 {"James"};

    // string *p1 {&s1};		
    // string *p2 {&s2};
    // string *p3 {&s1};

    // cout << boolalpha;
    // cout << p1 << "==" << p2 << ": " << (p1 == p2) << endl;		// false
    // cout << p1 << "==" << p3 << ": " << (p1 == p3) << endl;		// true

    // cout << *p1 << "==" << *p2 << ": " << (*p1 == *p2) << endl;		// true
    // cout << *p1 << "==" << *p3 << ": " << (*p1 == *p3) << endl;		// true
    
    // p3 = &s3;   // point to James
    // cout << *p1 << "==" << *p3 << ": " << (*p1 == *p3) << endl;		// false
    

    // cout << "\n-------------------------" << endl;
    // char name[]  {"Frank"};
    
    // char *char_ptr1 {nullptr};
    // char *char_ptr2{nullptr};
    
    // char_ptr1 = &name[0];   // F
    // char_ptr2 = &name[3];   // n

    // cout << "In the string " << name << ",  " << *char_ptr2 << " is " << (char_ptr2 - char_ptr1) << " characters away from " <<  *char_ptr1  << endl; 
    
    // cout << endl;
    // return 0;
}

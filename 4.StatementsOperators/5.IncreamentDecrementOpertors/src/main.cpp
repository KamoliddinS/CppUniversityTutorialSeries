#include <iostream>
using namespace std;

int main() {
    // Variables for demonstration
    int a, b;

    // Prefix Increment
    a = 5;
    b = ++a;
    std::cout << "After prefix increment, a = " << a << " and b = " << b << std::endl;

    // Postfix Increment
    a = 5;
    b = a++;
    std::cout << "After postfix increment, a = " << a << " and b = " << b << std::endl;

    // Prefix Decrement
    a = 5;
    b = --a;
    std::cout << "After prefix decrement, a = " << a << " and b = " << b << std::endl;

    // Postfix Decrement
    a = 5;
    b = a--;
    std::cout << "After postfix decrement, a = " << a << " and b = " << b << std::endl;
 
        int counter {10};
    int result {0};
     
// Example 1 - simple increment
    cout << "Counter : " << counter << endl;
    
    counter = counter + 1;
    cout << "Counter : " << counter << endl;
  
    counter++;
    cout << "Counter : " << counter << endl;

    ++counter; 
    cout << "Counter : " << counter << endl;

// Example 2 - preincrement
//    counter = 10;
//    result = 0;
//    
//    cout << "Counter : " << counter << endl;
//    
//    result = ++counter; // Note the pre increment
//    cout << "Counter : " << counter << endl;
//    cout << "Result : " << result << endl;

// Example 3 - post-increment
//    counter = 10;
//    result = 0;
//    
//    cout << "Counter : " << counter << endl;
//    
//    result = counter++; // Note the post increment
//    cout << "Counter : " << counter << endl;
//    cout << "Result : " << result << endl;

// Example 4
//    counter = 10;
//    result = 0;
//
//    cout << "Counter : " << counter << endl;
//
//    result = ++counter + 10;  // Note the pre increment
//        
//    cout << "Counter : " << counter << endl;
//    cout << "Result : " << result << endl;

// Example 5
//    counter = 10;
//    result = 0;
//
//    cout << "Counter : " << counter << endl;
//
//    result = counter++ + 10;  // Note the post increment
//        
//    cout << "Counter : " << counter << endl;
//    cout << "Result : " << result << endl;


    return 0;

}

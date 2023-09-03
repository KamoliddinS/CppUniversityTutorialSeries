#include <iostream> 

extern int linked_var; // declaration of linked_var
int main() { 
    std::cout << "Hello, World!" << std::endl; 
    std::cout << linked_var << std::endl; // use of linked_var
    return 0;
}

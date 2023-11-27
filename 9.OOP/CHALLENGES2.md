
Hi, Here some challenges for you to practice. Feel free to use the code editor below to complete the challenges. Once you are done, Letme know. I will review your code and provide feedback.

1. **Copy Constructor Challenge**:
   - Problem Statement: Create a `Matrix` class that uses dynamic memory allocation. Write a copy constructor to ensure that when a new object is created as a copy of an existing object, the new object has its own copy of the matrix.
   - Assessment Focus: Students must demonstrate understanding of deep copying and managing memory in the copy constructor.

2. **Shallow vs. Deep Copy Challenge**:
   - Problem Statement: Provide a class `StringWrapper` with a default shallow copy constructor. Ask students to identify potential problems with the existing copy constructor and modify it to implement a deep copy.
   - Assessment Focus: Highlighting the differences between shallow and deep copying, and understanding the implications of each.


3. **The `this` Pointer Challenge**: (Advanced: Optional Challenge)
   - Problem Statement: Design a `SelfReferential` class where each method returns a reference to its own object, using the `this` pointer, to allow method chaining.
   - Assessment Focus: Understanding the use of the `this` pointer to refer to the calling object.

4. **Const with Classes Challenge**:
   - Problem Statement: Design a `ReadOnlyWrapper` class that has methods to manipulate its data. Add `const` to some methods to ensure they don’t modify the object, and observe the behavior when these methods are called on const objects.
   - Assessment Focus: Understanding how `const` can be used with methods to control object modification.



```cpp

#include <iostream>
#include <cstring>

class StringWrapper {
private:
    char* str;

public:
    StringWrapper(const char* s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    StringWrapper(const StringWrapper& source) : str(source.str) {

    }

    ~StringWrapper() {
        delete[] str;
    }

    void display() const {
        std::cout << str << std::endl;
    }
};

int main() {
    StringWrapper original("Hello World");
    StringWrapper copy = original; // Here the copy constructor is called

    std::cout << "Original: ";
    original.display();

    // I am gonna change the original string
    strcpy(original.str, "Hello Universe");



    std::cout << "Copy: ";
    copy.display();

    return 0;
}

```
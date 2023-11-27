Here are some code fill challenges for you to practice. Feel free to use the code editor below to complete the challenges. Once you are done, Letme know. I will review your code and provide feedback.

### 1. Copy Constructor Challenge
```cpp
#include <iostream>
using namespace std;

class MyClass {
private:
    int *data;

public:
    MyClass(int d) {
        data = new int(d);
    }

    // TODO: Implement the copy constructor
    MyClass(const MyClass &source) {
        // Students should write their implementation here
    }

    ~MyClass() {
        delete data;
    }

    void printData() {
        cout << "Data: " << *data << endl;
    }
};

int main() {
    MyClass obj1(10);
    MyClass obj2 = obj1; // Copy Constructor is called here

    obj1.printData();
    obj2.printData();

    return 0;
}
```

### 2. Shallow vs. Deep Copy
```cpp
#include <iostream>
using namespace std;

class ArrayWrapper {
private:
    int *arr;
    int size;

public:
    ArrayWrapper(int sz, int initialValue) {
        size = sz;
        arr = new int[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = initialValue;
        }
    }

    // TODO: Convert this to a deep copy constructor
    ArrayWrapper(const ArrayWrapper &source) {
        // COMPLETE THIS FUNCTION
    }

    ~ArrayWrapper() {
        delete[] arr;
    }

    void printArray() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ArrayWrapper firstArray(5, 1);
    ArrayWrapper secondArray = firstArray; // Copy constructor is called here

    firstArray.printArray();
    secondArray.printArray();

    return 0;
}
```

### 3. Move Constructor Exercise
```cpp
#include <iostream>
using namespace std;

class MoveableClass {
private:
    int *data;

public:
    MoveableClass(int d) {
        data = new int(d);
    }

    // TODO: Implement the move constructor
    MoveableClass(MoveableClass &&source) noexcept {
        // Write your implementation here
    }

    ~MoveableClass() {
        delete data;
    }

    void printData() {
        cout << "Data: " << *data << endl;
    }
};

int main() {
    MoveableClass obj1(10);
    MoveableClass obj2 = move(obj1); 

    obj2.printData();

    return 0;
}
```

### 4. The `this` Pointer Usage
```cpp
class ExampleClass {
private:
    int value;

public:
    ExampleClass(int val) : value(val) {}

    // TODO: Use 'this' pointer to compare object's value with the argument
    bool isEqual(int val) {
        // Students should write their implementation here
    }
};

int main() {
    ExampleClass example(5);
    cout << example.isEqual(5); // Should return true or false

    return 0;
}
```

### 5. `const` with Classes
```cpp
class ConstantClass {
private:
    int value;

public:
    ConstantClass(int val) : value(val) {}

    // TODO: Mark this function as const
    int getValue() {
        // Students should write their implementation here
    }
};

int main() {
    const ConstantClass obj(10);
    cout << obj.getValue();

    return 0;
}
```


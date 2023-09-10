
## Global Variables

### What is a Global Variable?

A global variable is a variable that is declared outside of all functions, typically at the top of a C++ program file. Due to its scope, a global variable can be accessed from any part of the program, including within functions, classes, or other code blocks.

### Declaring and Initializing Global Variables

Just like any other variable, global variables are declared with a data type, followed by its name. They can be initialized at the time of declaration or later:

```cpp
// Global variable declaration
int globalVar = 100;

float globalFloat;
```

In the example above, `globalVar` is initialized with a value of 100, while `globalFloat` is declared without initialization.

### Using Global Variables

Once declared, a global variable can be used anywhere in the code:

```cpp
#include<iostream>
using namespace std;

// Global variable
int globalVar = 100;

void displayGlobal() {
    cout << "Global variable value: " << globalVar << endl;
}

int main() {
    displayGlobal();
    globalVar = 200;
    displayGlobal();
    return 0;
}
```

In the example above, the `displayGlobal` function accesses the `globalVar` variable directly.

### Pros and Cons of Using Global Variables

**Pros:**

1. **Accessibility:** Global variables can be accessed from anywhere in the program, making them convenient for shared resources.
2. **Persistent State:** They retain their value between function calls.

**Cons:**

1. **Reduced Readability:** Overuse can make code harder to understand, as it becomes unclear where the variable's value might be changing.
2. **Potential for Bugs:** Due to their wide scope, unintentional modifications can occur, leading to unpredictable results.
3. **Memory Consumption:** Global variables remain in memory for the entirety of the program's execution.

### Best Practices

- **Limited Use:** Only use global variables when necessary. Local variables or class properties are often more appropriate.
- **Initialization:** Always initialize global variables to prevent unpredictable behavior.
- **Descriptive Names:** Because they're accessed throughout the program, give global variables clear and descriptive names to prevent confusion.

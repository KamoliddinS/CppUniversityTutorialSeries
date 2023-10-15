
# Scope Rules in C++

In C++, the scope of a variable or function determines its visibility and lifespan within a program. Understanding these rules is crucial for writing error-free and maintainable code. This guide delves into the different scope types and their implications.

## Table of Contents

1. [Local Scope](#local-scope)
2. [File Scope (Global Scope)](#file-scope-global-scope)
3. [Namespace Scope](#namespace-scope)
4. [Class Scope](#class-scope)
5. [Examples](#examples)
6. [Key Takeaways](#key-takeaways)

## Local Scope

A variable declared within a function or a block has local scope. It's accessible only within that function or block and ceases to exist after the function exits.

```c++
void someFunction() {
    int localVar = 10;  // Local scope
}
```

## File Scope (Global Scope)

Variables declared outside all functions, classes, or namespaces have file or global scope. They're accessible throughout the file and maintain their value between function calls.

```c++
int globalVar = 20;  // Global scope
```

## Namespace Scope

Variables declared within a namespace have namespace scope. They're accessible within that namespace and can be accessed outside it using the namespace qualifier.

```c++
namespace SomeNamespace {
    int namespaceVar = 30;  // Namespace scope
}
```

## Class Scope

Variables declared within a class (member variables) have class scope. They're accessible within member functions of that class. 

```c++
class SomeClass {
    int classVar = 40;  // Class scope
};
```

## Examples

1. **Local vs. Global Scope**

```c++
int x = 50;  // Global scope

void func() {
    int x = 100;  // Local scope
    std::cout << x;  // Will print 100
}
```

2. **Accessing Namespace Variable**

```c++
namespace Demo {
    int y = 200;
}

void anotherFunc() {
    std::cout << Demo::y;  // Accessing variable from namespace scope
}
```

## Key Takeaways

1. Scope determines the visibility and lifespan of a variable or function.
2. Local variables exist only within their declaring function/block.
3. Global variables are accessible throughout their defining file.
4. Namespaces provide a way to group related variables and functions.
5. Member variables of classes have class scope and are accessible within the class's member functions.

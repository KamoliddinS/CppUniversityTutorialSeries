
## C++ Constants

In C++, a constant is a value that cannot be altered after its initialization. Constants are useful when you have values that you want to protect from inadvertent changes, or when you want to clearly communicate to other programmers that a value should not be modified.

### 1. `const` Keyword (Recommended)

The `const` keyword is a type qualifier that you can use to declare constants with a specific type.

**Syntax:**

```cpp
const data_type name = value;
```

**Example:**

```cpp
const int daysInWeek = 7;
```

After the declaration, attempting to change the value of `daysInWeek` will result in a compile-time error.

### 2. `#define` Preprocessor (Don't use it in modern C++)

The `#define` directive allows you to define a constant without specifying its type. However, it's not a variable but rather a symbolic name for a value.

**Syntax:**

```cpp
#define NAME value
```

**Example:**

```cpp
#define PI 3.14159
```

Since `#define` is processed by the preprocessor before the code compiles, no memory is allocated for it.

### 3. `constexpr` Keyword

Introduced in C++11, the `constexpr` keyword is used to declare a constant expression. It tells the compiler to evaluate the value of the expression at compile time. It can also be used with functions to ensure they return compile-time constants.

**Syntax:**

```cpp
constexpr data_type name = value;
```

**Example:**

```cpp
constexpr double gravity = 9.81;
```

### 4. `enum` Enumeration

An enumeration is a distinct type that consists of a set of named integer constants.

**Syntax:**

```cpp
enum EnumName {CONST1, CONST2, ..., CONSTn};
```

**Example:**

```cpp
enum Days {SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY};
```

By default, `SUNDAY` will have the value `0`, `MONDAY` will have `1`, and so on. You can also explicitly set values for them if needed.

### Using Constants

Using constants in your program is straightforward. Once declared, you can utilize them as you would with variables, but remember they cannot be modified.

```cpp
const int maxUsers = 100;

int main() {
    int currentUserCount = 50;

    if (currentUserCount < maxUsers) {
        // Allow more users
    }
}
```

### Conclusion

Constants play a crucial role in C++ programming, offering a way to protect data from unintended changes, and improving the clarity and maintainability of code. Understanding and appropriately utilizing the various methods to declare constants is foundational for C++ programming.


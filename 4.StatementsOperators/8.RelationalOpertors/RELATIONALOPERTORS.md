
# C++ Relational Operators

Relational operators in C++ are used to compare two values. These operators return a boolean value, either `true` or `false`, based on the result of the comparison. This guide will explore each relational operator and provide examples of their usage.

## List of Relational Operators

- `==` : Equal to
- `!=` : Not equal to
- `>` : Greater than
- `<` : Less than
- `>=` : Greater than or equal to
- `<=` : Less than or equal to

## Usage and Examples

### 1. Equal to (`==`)

Checks if two values are the same.

```cpp
int a = 5;
int b = 5;
bool isEqual = (a == b);  // Returns true
```

### 2. Not equal to (`!=`)

Checks if two values are different.

```cpp
int a = 5;
int b = 6;
bool isDifferent = (a != b);  // Returns true
```

### 3. Greater than (`>`)

Checks if the left value is greater than the right value.

```cpp
int a = 10;
int b = 5;
bool isGreater = (a > b);  // Returns true
```

### 4. Less than (`<`)

Checks if the left value is less than the right value.

```cpp
int a = 5;
int b = 10;
bool isLess = (a < b);  // Returns true
```

### 5. Greater than or equal to (`>=`)

Checks if the left value is greater than or equal to the right value.

```cpp
int a = 10;
int b = 10;
bool isGreaterOrEqual = (a >= b);  // Returns true
```

### 6. Less than or equal to (`<=`)

Checks if the left value is less than or equal to the right value.

```cpp
int a = 5;
int b = 5;
bool isLessOrEqual = (a <= b);  // Returns true
```

## Usage in Conditional Statements

Relational operators are commonly used in conditional statements like `if`.

```cpp
int x = 10;
int y = 20;

if (x < y) {
    std::cout << "x is less than y." << std::endl;
} else {
    std::cout << "x is not less than y." << std::endl;
}
```

## Conclusion

Relational operators are essential tools in C++ programming, allowing for comparisons and decision-making in your code. Understanding and using these operators correctly is crucial for writing effective and efficient programs.

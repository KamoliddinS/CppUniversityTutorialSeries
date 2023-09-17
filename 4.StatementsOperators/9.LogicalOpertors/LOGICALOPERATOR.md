
# C++ Logical Operators

Logical operators in C++ are used to combine multiple conditions or to invert the value of a condition. These operators return a boolean value, either `true` or `false`, based on the result of the logical operation. This guide will explore each logical operator and provide examples of their usage.

## List of Logical Operators

- `&&` : Logical AND
- `||` : Logical OR
- `!` : Logical NOT

## Usage and Examples

### 1. Logical AND (`&&`)

Returns `true` if both conditions are true. Otherwise, it returns `false`.

```cpp
bool isAdult = true;
bool hasLicense = true;

if (isAdult && hasLicense) {
    std::cout << "Allowed to drive." << std::endl;
}
```

### 2. Logical OR (`||`)

Returns `true` if at least one of the conditions is true. If both are false, it returns `false`.

```cpp
bool isWeekend = true;
bool isHoliday = false;

if (isWeekend || isHoliday) {
    std::cout << "Enjoy your day off!" << std::endl;
}
```

### 3. Logical NOT (`!`)

Inverts the value of a condition. If the condition is `true`, it returns `false` and vice versa.

```cpp
bool isRaining = false;

if (!isRaining) {
    std::cout << "It's a sunny day!" << std::endl;
}
```

## Combining Logical Operators

You can combine multiple logical operators to evaluate complex conditions:

```cpp
bool hasHomework = true;
bool isWeekend = true;
bool isSick = false;

if ((isWeekend || isSick) && !hasHomework) {
    std::cout << "You can relax today." << std::endl;
} else {
    std::cout << "You have some responsibilities." << std::endl;
}
```

## Conclusion

Logical operators are essential tools in C++ programming, allowing for complex decision-making based on multiple conditions. Understanding and using these operators correctly is crucial for writing clear and efficient programs.



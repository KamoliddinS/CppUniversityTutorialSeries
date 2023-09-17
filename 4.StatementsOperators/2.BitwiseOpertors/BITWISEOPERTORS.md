
# Bitwise Operators in C++

Bitwise operators are used to perform operations on individual bits of numbers. They are useful when you want to manipulate data at the bit level.

## List of Bitwise Operators

1. `&` - Bitwise AND
2. `|` - Bitwise OR
3. `^` - Bitwise XOR (Exclusive OR)
4. `~` - Bitwise NOT
5. `<<` - Left Shift
6. `>>` - Right Shift

### 1. Bitwise AND (`&`)

This operator compares each bit of the first operand to the corresponding bit of the second operand. If both bits are `1`, the corresponding result bit is set to `1`. Otherwise, the corresponding result bit is set to `0`.

**Example:**

```cpp
int a = 5;  // 0101 in binary
int b = 3;  // 0011 in binary
int result = a & b;  // 0001 in binary which is 1 in decimal
```

### 2. Bitwise OR (`|`)

This operator compares each bit of the first operand to the corresponding bit of the second operand. If either bit is `1`, the corresponding result bit is set to `1`. Otherwise, the corresponding result bit is set to `0`.

**Example:**

```cpp
int a = 5;  // 0101 in binary
int b = 3;  // 0011 in binary
int result = a | b;  // 0111 in binary which is 7 in decimal
```

### 3. Bitwise XOR (`^`)

This operator compares each bit of the first operand to the corresponding bit of the second operand. If the bits are different, the corresponding result bit is set to `1`. Otherwise, it's set to `0`.

**Example:**

```cpp
int a = 5;  // 0101 in binary
int b = 3;  // 0011 in binary
int result = a ^ b;  // 0110 in binary which is 6 in decimal
```

### 4. Bitwise NOT (`~`)

This operator inverts the bits of its operand.

**Example:**

```cpp
int a = 5;  // 0101 in binary
int result = ~a;  // 1010 in binary which is -6 in decimal (due to two's complement representation)
```

### 5. Left Shift (`<<`)

This operator shifts the left operand's value to the left by the number of bits specified by the right operand.

**Example:**

```cpp
int a = 5;  // 0101 in binary
int result = a << 1;  // 1010 in binary which is 10 in decimal
```

### 6. Right Shift (`>>`)

This operator shifts the left operand's value to the right by the number of bits specified by the right operand.

**Example:**

```cpp
int a = 5;  // 0101 in binary
int result = a >> 1;  // 0010 in binary which is 2 in decimal
```

## Conclusion

Bitwise operators are powerful tools for manipulating individual bits in numbers. They are commonly used in low-level programming, such as systems programming and embedded systems. Understanding these operators can help you optimize your code and perform operations that aren't possible with regular arithmetic operators.

**Note:** Always be careful when using bitwise operators, as incorrect usage can lead to unexpected results.

# Computer Programming with C++: 1's and 2's Complement

## Introduction

When working with binary numbers in computer systems, two essential operations are the **1's complement** and the **2's complement**. These operations are primarily used to represent negative numbers in binary and for performing binary arithmetic operations. Significance of 1's and 2's complement in computer programming can be found [here](./SIGNIFICANCE.md).

## 1's Complement

The 1's complement of a binary number is obtained by changing all 0s to 1s and all 1s to 0s.

**Example:** 

Binary Number: `1010`

1's Complement: `0101`

### Steps to find 1's complement:
1. Start from the least significant bit (LSB).
2. For each 0, write a 1.
3. For each 1, write a 0.

## 2's Complement

The 2's complement of a binary number is obtained by taking the 1's complement and adding 1 to the least significant bit (LSB).

**Example:**

Binary Number: `1010`

1's Complement: `0101`

2's Complement: `0101 + 1 = 0110`

### Steps to find 2's complement:
1. Find the 1's complement of the binary number.
2. Add 1 to the least significant bit.

## Why 2's Complement?

The 2's complement representation is used in computer systems to represent negative numbers. The reason behind using 2's complement is that it offers a consistent method for addition and subtraction of both positive and negative binary numbers. When using 2's complement, the most significant bit (MSB) acts as the sign bit. A '0' in the MSB indicates a positive number, whereas a '1' indicates a negative number.

### Example:

Given an 8-bit number, to represent `-44` in binary:

Decimal Number: `44`

Binary Representation: `00101100`

1's Complement: `11010011`

2's Complement: `11010100`

So, `-44` in 8-bit 2's complement binary form is `11010100`.

## Quick Points:
- 1's complement is the inverse of a binary number.
- 2's complement is the 1's complement plus 1.
- 2's complement representation simplifies binary arithmetic.
- MSB acts as the sign bit in 2's complement.

## Practice:

1. Find the 2's complement of `1110`.
2. Represent `-25` in 8-bit binary using 2's complement.

## More Examples:
Examples of 1's and 2's complement of binary numbers can be found [here](./EXAMPLE.md).

## Summary

Understanding the 1's and 2's complement is crucial in the realm of computer programming, especially when dealing with binary arithmetic operations and representation of negative numbers. The simplicity of the 2's complement method in handling both positive and negative numbers makes it the preferred choice in computer systems.
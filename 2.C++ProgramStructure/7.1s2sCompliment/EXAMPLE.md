
### Example 1:

**Binary Number:** `1011`

#### 1's Complement:
Flip each bit.
`1011` becomes `0100`.

#### 2's Complement:
Add 1 to the least significant bit of the 1's complement.
`0100 + 1 = 0101`

### Example 2:

**Binary Number:** `110100`

#### 1's Complement:
Flip each bit.
`110100` becomes `001011`.

#### 2's Complement:
Add 1 to the least significant bit of the 1's complement.
`001011 + 1 = 001100`

### Example 3:

**Binary Number:** `10001`

#### 1's Complement:
Flip each bit.
`10001` becomes `01110`.

#### 2's Complement:
Add 1 to the least significant bit of the 1's complement.
`01110 + 1 = 01111`

### Example 4:

To find the 2's complement representation of a negative decimal number:

**Decimal Number:** `-18`

1. Convert `18` to binary. This is `10010`.
2. Expand this binary to a preferred bit-length, say 8 bits, to get `00010010`.
3. Find the 1's complement: `11101101`.
4. Add 1 to the least significant bit to get the 2's complement: `11101110`.

So, `-18` in 8-bit 2's complement form is `11101110`.

Remember, 2's complement is the preferred way to represent negative numbers in binary in most computer systems because it allows for easy addition and subtraction operations.
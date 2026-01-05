# 🔢 Primitive Types

## Overview

Rust has a rich set of primitive (scalar) types built into the language. These are the fundamental building blocks for all data in Rust.

## 📊 Integer Types

### Signed Integers

Can hold positive and negative values:

| Type | Size | Range |
|------|------|-------|
| `i8` | 8 bits | -128 to 127 |
| `i16` | 16 bits | -32,768 to 32,767 |
| `i32` | 32 bits | -2,147,483,648 to 2,147,483,647 |
| `i64` | 64 bits | -9.2×10¹⁸ to 9.2×10¹⁸ |
| `i128` | 128 bits | ±1.7×10³⁸ |
| `isize` | arch | Depends on architecture |

### Unsigned Integers

Only positive values:

| Type | Size | Range |
|------|------|-------|
| `u8` | 8 bits | 0 to 255 |
| `u16` | 16 bits | 0 to 65,535 |
| `u32` | 32 bits | 0 to 4,294,967,295 |
| `u64` | 64 bits | 0 to 1.8×10¹⁹ |
| `u128` | 128 bits | 0 to 3.4×10³⁸ |
| `usize` | arch | Depends on architecture |

### Integer Literals

```rust
let decimal = 98_222;       // Decimal (underscores for readability)
let hex = 0xff;             // Hexadecimal
let octal = 0o77;           // Octal
let binary = 0b1111_0000;   // Binary
let byte = b'A';            // Byte (u8 only)
```

### Type Suffixes

```rust
let x = 42i32;   // i32
let y = 42u64;   // u64
let z = 42_u8;   // u8 (underscore before suffix is valid)
```

### Default Integer Type

```rust
let x = 42;  // Defaults to i32
```

## 🔵 Floating-Point Types

| Type | Size | Precision |
|------|------|-----------|
| `f32` | 32 bits | ~6-7 decimal digits |
| `f64` | 64 bits | ~15-16 decimal digits |

```rust
let x = 2.0;      // f64 (default)
let y: f32 = 3.0; // f32

// Scientific notation
let large = 1.0e10;    // 10,000,000,000
let small = 1.5e-5;    // 0.000015
```

### Float Operations

```rust
let sum = 5.0 + 10.0;
let difference = 95.5 - 4.3;
let product = 4.0 * 30.0;
let quotient = 56.7 / 32.2;

// Special values
let infinity = f64::INFINITY;
let neg_infinity = f64::NEG_INFINITY;
let nan = f64::NAN;
```

## ✅ Boolean Type

```rust
let t = true;
let f: bool = false;

// Boolean operations
let and = true && false;  // false
let or = true || false;   // true
let not = !true;          // false
```

## 🔤 Character Type

Rust's `char` is a Unicode scalar value (4 bytes):

```rust
let c = 'z';
let z: char = 'ℤ';
let heart = '❤';
let emoji = '😀';
let chinese = '中';
```

### Character Methods

```rust
let c = 'A';

c.is_alphabetic();  // true
c.is_numeric();     // false
c.is_whitespace();  // false
c.is_uppercase();   // true
c.to_lowercase();   // 'a' (returns iterator)
```

### Char vs String

```rust
let c: char = 'A';    // Single quotes - char (4 bytes)
let s: &str = "A";    // Double quotes - string slice (1+ bytes)
```

## 🔢 Numeric Operations

### Basic Math

```rust
let sum = 5 + 10;
let difference = 95.5 - 4.3;
let product = 4 * 30;
let quotient = 56.7 / 32.2;
let remainder = 43 % 5;
```

### Integer Division

```rust
let truncated = 5 / 3;     // 1 (not 1.666...)
let float_div = 5.0 / 3.0; // 1.666...
```

### Checked Operations

```rust
let x: u8 = 255;

// These panic in debug, wrap in release
// let overflow = x + 1;

// Safe alternatives
let checked = x.checked_add(1);     // Returns Option<u8>
let wrapped = x.wrapping_add(1);    // Returns 0
let saturated = x.saturating_add(1); // Returns 255
let (result, overflow) = x.overflowing_add(1); // Returns (0, true)
```

## 📏 The Unit Type

The "empty" type, written `()`:

```rust
let unit: () = ();

// Functions with no return value return ()
fn do_nothing() {
    // Implicitly returns ()
}

fn explicit_unit() -> () {
    ()
}
```

## 🎯 Type Conversion

### Between Numeric Types

```rust
let x: i32 = 42;
let y: i64 = x as i64;  // Widening - safe
let z: i16 = x as i16;  // Narrowing - may truncate

let f: f64 = 3.14;
let i: i32 = f as i32;  // 3 (truncates decimal)
```

### Careful with Conversions

```rust
let big: i32 = 1000;
let small: u8 = big as u8;  // 232 (1000 % 256) - data loss!

let negative: i32 = -1;
let unsigned: u32 = negative as u32;  // 4294967295 - unexpected!
```

## 📂 Example Code

```rust
fn main() {
    // Integers
    let a: i32 = -42;
    let b: u64 = 100_000_000;
    let hex: u8 = 0xFF;

    // Floats
    let pi: f64 = 3.14159265358979;
    let e: f32 = 2.71828;

    // Boolean
    let is_rust_awesome: bool = true;

    // Character
    let letter: char = 'R';
    let emoji: char = '🦀';

    println!("Integer: {}", a);
    println!("Unsigned: {}", b);
    println!("Hex value: {}", hex);
    println!("Pi: {}", pi);
    println!("e: {}", e);
    println!("Is Rust awesome? {}", is_rust_awesome);
    println!("Letter: {}, Emoji: {}", letter, emoji);
}
```

---

[← Previous: Variables and Mutability](../1.VariablesMutability/README.md) | [Next: Compound Types →](../3.CompoundTypes/README.md)

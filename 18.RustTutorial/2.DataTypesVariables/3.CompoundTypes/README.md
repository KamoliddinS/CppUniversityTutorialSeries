# 📦 Compound Types

## Overview

Compound types group multiple values into one type. Rust has two primitive compound types: **tuples** and **arrays**.

## 📊 Tuples

A tuple groups values of different types with a fixed length.

### Creating Tuples

```rust
let tuple: (i32, f64, char) = (500, 6.4, 'y');

// With type inference
let point = (3, 4);
let person = ("Alice", 30, true);
```

### Accessing Tuple Elements

#### Destructuring

```rust
let tuple = (500, 6.4, 'y');
let (x, y, z) = tuple;

println!("x: {}, y: {}, z: {}", x, y, z);
```

#### Dot Notation

```rust
let tuple = (500, 6.4, 'y');

let first = tuple.0;   // 500
let second = tuple.1;  // 6.4
let third = tuple.2;   // 'y'
```

### Tuple Operations

```rust
// Single-element tuple (note the comma)
let single = (5,);  // Type: (i32,)
let not_tuple = (5); // Type: i32 - just parentheses!

// Empty tuple (unit type)
let unit: () = ();

// Mutable tuple
let mut mutable = (1, 2, 3);
mutable.0 = 10;
```

### Tuple Functions

```rust
fn get_user() -> (String, i32) {
    (String::from("Alice"), 30)
}

fn main() {
    let (name, age) = get_user();
    println!("{} is {} years old", name, age);
}
```

## 📚 Arrays

Arrays have a fixed length and store elements of the same type.

### Creating Arrays

```rust
// Explicit type annotation
let array: [i32; 5] = [1, 2, 3, 4, 5];

// Type inference
let months = ["January", "February", "March"];

// Initialize with same value
let zeros = [0; 5];  // [0, 0, 0, 0, 0]
let ones = [1; 10];  // [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
```

### Array Type Notation

```rust
// [Type; Length]
let bytes: [u8; 4] = [192, 168, 1, 1];
let flags: [bool; 3] = [true, false, true];
```

### Accessing Array Elements

```rust
let array = [10, 20, 30, 40, 50];

let first = array[0];   // 10
let third = array[2];   // 30
let last = array[4];    // 50

// Out of bounds - panics at runtime!
// let invalid = array[10]; // Runtime panic!
```

### Array Properties

```rust
let array = [1, 2, 3, 4, 5];

let length = array.len();        // 5
let is_empty = array.is_empty(); // false
```

### Iterating Over Arrays

```rust
let array = [10, 20, 30];

// Using for loop
for element in array {
    println!("{}", element);
}

// Using for loop with index
for (index, element) in array.iter().enumerate() {
    println!("[{}] = {}", index, element);
}
```

### Array Slices

```rust
let array = [1, 2, 3, 4, 5];

let slice = &array[1..3];  // [2, 3]
let start = &array[..2];   // [1, 2]
let end = &array[3..];     // [4, 5]
let full = &array[..];     // [1, 2, 3, 4, 5]
```

### Mutable Arrays

```rust
let mut array = [1, 2, 3];
array[0] = 10;
println!("{:?}", array);  // [10, 2, 3]
```

## 📊 Comparison: Tuple vs Array

| Feature | Tuple | Array |
|---------|-------|-------|
| **Element Types** | Different | Same |
| **Length** | Fixed | Fixed |
| **Access** | `.0`, `.1`, etc. or destructuring | `[index]` |
| **Type Syntax** | `(T1, T2, T3)` | `[T; N]` |
| **Use Case** | Group related different data | Collection of same data |

## 🎯 When to Use What

### Use Tuples When:
- Grouping a small number of different types
- Returning multiple values from a function
- Quick, ad-hoc groupings

```rust
// Good tuple use
fn divide(a: i32, b: i32) -> (i32, i32) {
    (a / b, a % b)  // quotient and remainder
}

let point = (3.5, 2.1);  // x, y coordinates
```

### Use Arrays When:
- You have a collection of the same type
- The size is known at compile time
- You need indexed access

```rust
// Good array use
let days = ["Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"];
let rgb: [u8; 3] = [255, 128, 0];
```

### Use Vec When:
- Size can change at runtime
- (We'll cover Vec in the Collections lesson)

```rust
let mut dynamic = vec![1, 2, 3];
dynamic.push(4);  // Can grow
```

## 📂 Example Code

```rust
fn main() {
    // Tuples
    let person: (&str, i32, bool) = ("Alice", 30, true);
    let (name, age, active) = person;
    println!("{} is {} years old, active: {}", name, age, active);

    // Tuple indexing
    let point = (3.5, 2.8);
    println!("Point: ({}, {})", point.0, point.1);

    // Arrays
    let numbers: [i32; 5] = [1, 2, 3, 4, 5];
    println!("Array: {:?}", numbers);
    println!("First: {}, Last: {}", numbers[0], numbers[4]);

    // Array initialization
    let zeros = [0; 10];
    println!("Zeros: {:?}", zeros);

    // Array iteration
    let fruits = ["apple", "banana", "cherry"];
    for fruit in fruits {
        println!("I like {}", fruit);
    }

    // Slices
    let slice = &numbers[1..4];
    println!("Slice: {:?}", slice);

    // Function returning tuple
    let (quotient, remainder) = divide_with_remainder(17, 5);
    println!("17 / 5 = {} remainder {}", quotient, remainder);
}

fn divide_with_remainder(a: i32, b: i32) -> (i32, i32) {
    (a / b, a % b)
}
```

---

[← Previous: Primitive Types](../2.PrimitiveTypes/README.md) | [Next: Constants and Statics →](../4.ConstantsStatics/README.md)

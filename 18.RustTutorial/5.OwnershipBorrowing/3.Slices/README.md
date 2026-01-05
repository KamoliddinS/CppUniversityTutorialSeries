# 🍕 Slices

## Overview

Slices let you reference a contiguous sequence of elements in a collection without taking ownership. They're a kind of reference, so they don't have ownership.

## 📝 String Slices (`&str`)

```rust
let s = String::from("hello world");

let hello = &s[0..5];   // "hello"
let world = &s[6..11];  // "world"
```

### Slice Syntax

```rust
let s = String::from("hello");

let slice1 = &s[0..2];  // "he"
let slice2 = &s[..2];   // "he" (start from 0)
let slice3 = &s[2..];   // "llo" (go to end)
let slice4 = &s[..];    // "hello" (entire string)
```

### Range Syntax

| Syntax | Meaning |
|--------|---------|
| `[0..5]` | Index 0 to 4 (5 is exclusive) |
| `[..5]` | Start to index 4 |
| `[2..]` | Index 2 to end |
| `[..]` | Entire collection |
| `[0..=4]` | Index 0 to 4 (inclusive) |

## 🔤 String Literals Are Slices

```rust
let s: &str = "Hello, world!";  // String literal is &str
```

String literals are stored in the program's binary and are immutable `&str` slices.

## 📊 The `&str` vs `String` Distinction

| Type | Ownership | Mutability | Storage |
|------|-----------|------------|---------|
| `String` | Owned | Mutable | Heap |
| `&str` | Borrowed | Immutable | Anywhere |

```rust
let owned: String = String::from("hello");  // Owned
let borrowed: &str = "hello";               // Borrowed (static)
let slice: &str = &owned[..];               // Borrowed from String
```

## 🎯 Using `&str` in Functions

Prefer `&str` over `&String` for parameters:

```rust
// Good - accepts both String and &str
fn greet(name: &str) {
    println!("Hello, {}!", name);
}

fn main() {
    let owned = String::from("Alice");
    let literal = "Bob";

    greet(&owned);    // Works with &String (deref coercion)
    greet(literal);   // Works with &str
    greet("Carol");   // Works with literal
}
```

## 📚 Array Slices

Slices work on arrays and vectors too:

```rust
let arr = [1, 2, 3, 4, 5];

let slice: &[i32] = &arr[1..4];  // [2, 3, 4]

println!("{:?}", slice);
```

### Vector Slices

```rust
let vec = vec![1, 2, 3, 4, 5];

let slice = &vec[1..4];  // &[i32] containing [2, 3, 4]

for item in slice {
    println!("{}", item);
}
```

## 🔧 Mutable Slices

```rust
let mut arr = [1, 2, 3, 4, 5];

let slice: &mut [i32] = &mut arr[1..4];

slice[0] = 20;  // Modifies arr[1]

println!("{:?}", arr);  // [1, 20, 3, 4, 5]
```

## 📊 Slice Methods

```rust
let numbers = [1, 2, 3, 4, 5];
let slice = &numbers[..];

// Length
println!("Length: {}", slice.len());

// Is empty
println!("Empty: {}", slice.is_empty());

// First/Last
println!("First: {:?}", slice.first());
println!("Last: {:?}", slice.last());

// Contains
println!("Has 3: {}", slice.contains(&3));

// Iteration
for (i, item) in slice.iter().enumerate() {
    println!("[{}] = {}", i, item);
}

// Get safely
println!("Index 2: {:?}", slice.get(2));  // Some(&3)
println!("Index 10: {:?}", slice.get(10)); // None
```

## 🎨 Common Patterns

### First Word

```rust
fn first_word(s: &str) -> &str {
    for (i, c) in s.char_indices() {
        if c == ' ' {
            return &s[..i];
        }
    }
    s
}

fn main() {
    let sentence = String::from("hello world");
    let word = first_word(&sentence);
    println!("First word: {}", word);
}
```

### Split Into Words

```rust
fn main() {
    let text = "hello world rust";

    // Using split
    for word in text.split_whitespace() {
        println!("{}", word);
    }

    // Collecting into Vec
    let words: Vec<&str> = text.split_whitespace().collect();
    println!("{:?}", words);
}
```

### Working with Chunks

```rust
let data = [1, 2, 3, 4, 5, 6];

// Chunks of 2
for chunk in data.chunks(2) {
    println!("{:?}", chunk);
}

// Windows of 3
for window in data.windows(3) {
    println!("{:?}", window);
}
```

## ⚠️ Slice Gotchas

### String Indexing

```rust
let s = String::from("hello");

// Error! Strings can't be indexed by integers
// let h = s[0];

// Use slices instead
let h = &s[0..1];  // "h"

// Or chars()
let first_char = s.chars().next().unwrap();  // 'h'
```

### UTF-8 and Slices

```rust
let s = String::from("こんにちは");  // Japanese "hello"

// Each character is 3 bytes
// let slice = &s[0..2];  // Error! Not a char boundary

let slice = &s[0..3];  // OK - first character "こ"
```

## 📂 Example Code

```rust
fn main() {
    // String slices
    let greeting = String::from("Hello, World!");
    let hello = &greeting[..5];
    let world = &greeting[7..12];
    println!("{} {}", hello, world);

    // First word
    let sentence = "The quick brown fox";
    let first = first_word(sentence);
    println!("First word: '{}'", first);

    // Array slices
    let numbers = [10, 20, 30, 40, 50];
    let middle = &numbers[1..4];
    println!("Middle: {:?}", middle);

    // Mutable slices
    let mut data = [1, 2, 3, 4, 5];
    double_slice(&mut data[1..4]);
    println!("After doubling: {:?}", data);

    // Slice methods
    let items = [1, 2, 3, 4, 5];
    println!("Sum: {}", sum_slice(&items));
    println!("Average: {:.2}", average_slice(&items));
}

fn first_word(s: &str) -> &str {
    match s.find(' ') {
        Some(i) => &s[..i],
        None => s,
    }
}

fn double_slice(slice: &mut [i32]) {
    for item in slice.iter_mut() {
        *item *= 2;
    }
}

fn sum_slice(slice: &[i32]) -> i32 {
    slice.iter().sum()
}

fn average_slice(slice: &[i32]) -> f64 {
    if slice.is_empty() {
        0.0
    } else {
        slice.iter().sum::<i32>() as f64 / slice.len() as f64
    }
}
```

---

[← Previous: References and Borrowing](../2.Borrowing/README.md) | [Next Lesson: Structs and Enums →](../../6.StructsEnums/README.md)

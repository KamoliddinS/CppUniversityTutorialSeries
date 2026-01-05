# 🔗 References and Borrowing

## Overview

Borrowing allows you to use a value without taking ownership. This is done through **references**, which are like pointers but with guaranteed validity.

## 📖 Borrowing Rules

| Rule | Description |
|------|-------------|
| 1 | You can have **either** one mutable reference **or** any number of immutable references |
| 2 | References must always be **valid** (no dangling references) |

## 📌 Immutable References (`&T`)

```rust
fn main() {
    let s = String::from("hello");

    let len = calculate_length(&s);  // Borrow s

    println!("Length of '{}' is {}", s, len);  // s is still valid!
}

fn calculate_length(s: &String) -> usize {
    s.len()
}  // s goes out of scope, but since it's a reference, nothing is dropped
```

### Multiple Immutable References

```rust
let s = String::from("hello");

let r1 = &s;
let r2 = &s;
let r3 = &s;

println!("{}, {}, {}", r1, r2, r3);  // All valid!
```

## 🔧 Mutable References (`&mut T`)

```rust
fn main() {
    let mut s = String::from("hello");

    change(&mut s);

    println!("{}", s);  // Prints: hello, world!
}

fn change(s: &mut String) {
    s.push_str(", world!");
}
```

### Only One Mutable Reference

```rust
let mut s = String::from("hello");

let r1 = &mut s;
// let r2 = &mut s;  // Error! Cannot have two mutable references

println!("{}", r1);
```

### Why This Restriction?

Prevents **data races** at compile time:
- Two or more pointers access the same data simultaneously
- At least one is writing
- No synchronization mechanism

## 🚫 Cannot Mix References

```rust
let mut s = String::from("hello");

let r1 = &s;      // Immutable borrow
let r2 = &s;      // Another immutable borrow - OK
// let r3 = &mut s;  // Error! Cannot borrow as mutable while borrowed immutably

println!("{} and {}", r1, r2);
```

## 🔄 Non-Lexical Lifetimes (NLL)

References are valid until their last use, not until end of scope:

```rust
let mut s = String::from("hello");

let r1 = &s;
let r2 = &s;
println!("{} and {}", r1, r2);
// r1 and r2 are no longer used after this point

let r3 = &mut s;  // OK! r1 and r2 are done
println!("{}", r3);
```

## 🎯 Reference Patterns

### Function Parameters

```rust
// Immutable borrow - can read
fn print_info(s: &String) {
    println!("String: {}", s);
    println!("Length: {}", s.len());
}

// Mutable borrow - can modify
fn append(s: &mut String, text: &str) {
    s.push_str(text);
}

fn main() {
    let mut data = String::from("Hello");

    print_info(&data);       // Borrow
    append(&mut data, "!");  // Mutable borrow

    println!("Final: {}", data);
}
```

### Method Receivers

```rust
struct Rectangle {
    width: u32,
    height: u32,
}

impl Rectangle {
    // &self - immutable borrow of self
    fn area(&self) -> u32 {
        self.width * self.height
    }

    // &mut self - mutable borrow of self
    fn double(&mut self) {
        self.width *= 2;
        self.height *= 2;
    }

    // self - takes ownership
    fn consume(self) -> (u32, u32) {
        (self.width, self.height)
    }
}
```

## 🚫 Dangling References

Rust prevents dangling references at compile time:

```rust
// Error! This would create a dangling reference
fn dangle() -> &String {
    let s = String::from("hello");
    &s  // s is dropped here, reference would be invalid
}

// Fix: Return ownership instead
fn no_dangle() -> String {
    let s = String::from("hello");
    s  // Ownership is moved out
}
```

## 📊 Reference Summary

| Type | Syntax | Can Read | Can Write | Multiple Allowed |
|------|--------|----------|-----------|------------------|
| Owned | `T` | Yes | Yes | N/A |
| Immutable Ref | `&T` | Yes | No | Yes |
| Mutable Ref | `&mut T` | Yes | Yes | No |

## 💡 Best Practices

### Prefer References Over Ownership

```rust
// Good - doesn't take ownership
fn is_valid(input: &str) -> bool {
    !input.is_empty()
}

// Avoid - unnecessarily takes ownership
fn is_valid_bad(input: String) -> bool {
    !input.is_empty()
}
```

### Use Mutable References Sparingly

```rust
// Good - returns new value
fn add_prefix(s: &str) -> String {
    format!("prefix_{}", s)
}

// Use when mutation is appropriate
fn normalize(s: &mut String) {
    *s = s.trim().to_lowercase();
}
```

## 📂 Example Code

```rust
fn main() {
    // Immutable borrowing
    let s = String::from("hello world");
    let first_word = get_first_word(&s);
    println!("First word: {}", first_word);
    println!("Full string: {}", s);  // s is still valid

    // Mutable borrowing
    let mut numbers = vec![1, 2, 3];
    double_all(&mut numbers);
    println!("Doubled: {:?}", numbers);

    // Multiple immutable references
    let data = String::from("shared data");
    let ref1 = &data;
    let ref2 = &data;
    println!("ref1: {}, ref2: {}", ref1, ref2);

    // Non-lexical lifetimes
    let mut value = 10;
    let r1 = &value;
    println!("Value: {}", r1);
    // r1's lifetime ends here

    let r2 = &mut value;
    *r2 += 5;
    println!("Modified: {}", r2);
}

fn get_first_word(s: &str) -> &str {
    for (i, c) in s.char_indices() {
        if c == ' ' {
            return &s[..i];
        }
    }
    s
}

fn double_all(numbers: &mut Vec<i32>) {
    for n in numbers.iter_mut() {
        *n *= 2;
    }
}
```

---

[← Previous: Understanding Ownership](../1.Ownership/README.md) | [Next: Slices →](../3.Slices/README.md)

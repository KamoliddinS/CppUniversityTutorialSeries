# 👑 Understanding Ownership

## Overview

Ownership is Rust's most unique feature. It enables Rust to make memory safety guarantees without needing a garbage collector.

## 📜 The Three Rules

| Rule | Description |
|------|-------------|
| 1 | Each value in Rust has a variable that's its **owner** |
| 2 | There can only be **one owner** at a time |
| 3 | When the owner goes out of scope, the value is **dropped** |

## 🔍 Ownership in Action

### Stack vs Heap

```rust
// Stack data - fixed size, copied automatically
let x = 5;
let y = x;  // Copy - both x and y are valid

// Heap data - dynamic size, moved
let s1 = String::from("hello");
let s2 = s1;  // Move - s1 is no longer valid
// println!("{}", s1);  // Error! s1 was moved
```

### Why the Difference?

| Type | Storage | Copy Behavior |
|------|---------|---------------|
| `i32`, `f64`, `bool`, `char` | Stack | Automatic copy |
| `String`, `Vec`, `Box` | Heap | Move (unless cloned) |

## 🔄 Move Semantics

When you assign heap data to another variable, ownership moves:

```rust
let s1 = String::from("hello");
let s2 = s1;  // s1 is moved to s2

// s1 is now invalid
println!("{}", s2);  // OK
// println!("{}", s1);  // Error!
```

**Memory visualization:**

```
Before move:
s1 → [ptr|len|cap] → "hello"

After move:
s1 → (invalid)
s2 → [ptr|len|cap] → "hello"
```

## 📋 Clone for Deep Copy

To create an actual copy of heap data:

```rust
let s1 = String::from("hello");
let s2 = s1.clone();  // Deep copy

println!("{}", s1);  // OK - s1 is still valid
println!("{}", s2);  // OK
```

## ✅ The Copy Trait

Types that implement `Copy` are copied instead of moved:

```rust
// These types implement Copy
let x: i32 = 5;
let y = x;  // Copy
println!("{} {}", x, y);  // Both valid

let a: f64 = 3.14;
let b = a;  // Copy
println!("{} {}", a, b);  // Both valid

let t: (i32, i32) = (1, 2);
let u = t;  // Copy (tuples of Copy types)
println!("{:?} {:?}", t, u);  // Both valid
```

### Copy Types

- All integer types (`i32`, `u64`, etc.)
- All floating-point types (`f32`, `f64`)
- `bool`
- `char`
- Tuples containing only Copy types
- Arrays of Copy types with known size

## 📤 Ownership and Functions

### Passing Values

```rust
fn main() {
    let s = String::from("hello");
    takes_ownership(s);     // s is moved into the function
    // println!("{}", s);   // Error! s is no longer valid

    let x = 5;
    makes_copy(x);          // x is copied
    println!("{}", x);      // OK - x is still valid
}

fn takes_ownership(s: String) {
    println!("{}", s);
}  // s is dropped here

fn makes_copy(n: i32) {
    println!("{}", n);
}
```

### Returning Values

```rust
fn main() {
    let s1 = gives_ownership();         // Ownership moves to s1

    let s2 = String::from("hello");
    let s3 = takes_and_gives_back(s2);  // s2 moved in, s3 moves out
}

fn gives_ownership() -> String {
    let s = String::from("hello");
    s  // s is returned and moves to the caller
}

fn takes_and_gives_back(s: String) -> String {
    s  // s is returned and moves to the caller
}
```

## 🔄 Pattern: Return Multiple Values

```rust
fn main() {
    let s1 = String::from("hello");
    let (s2, len) = calculate_length(s1);
    println!("Length of '{}' is {}", s2, len);
}

fn calculate_length(s: String) -> (String, usize) {
    let length = s.len();
    (s, length)  // Return ownership along with the result
}
```

**Note**: This pattern is cumbersome. Borrowing (next topic) is a better solution.

## 📊 Ownership Decision Tree

```
Do you need to modify the data?
├── Yes → Do you need ownership?
│         ├── Yes → Take ownership (move)
│         └── No → Use &mut T (mutable borrow)
└── No → Do you need ownership?
         ├── Yes → Clone or take ownership
         └── No → Use &T (immutable borrow)
```

## 💡 Best Practices

### Prefer Borrowing

```rust
// Good - borrows instead of taking ownership
fn print_length(s: &String) {
    println!("Length: {}", s.len());
}

// Avoid - unnecessarily takes ownership
fn print_length_bad(s: String) {
    println!("Length: {}", s.len());
}  // s is dropped, caller can't use it anymore
```

### Clone When Necessary

```rust
let original = String::from("important data");

// When you need two independent copies
let backup = original.clone();

process(original);
archive(backup);
```

## 📂 Example Code

```rust
fn main() {
    // Ownership basics
    let s1 = String::from("hello");
    let s2 = s1;  // Move
    println!("s2: {}", s2);

    // Clone for deep copy
    let s3 = String::from("world");
    let s4 = s3.clone();
    println!("s3: {}, s4: {}", s3, s4);

    // Copy types
    let x = 42;
    let y = x;  // Copy
    println!("x: {}, y: {}", x, y);

    // Ownership with functions
    let data = String::from("my data");
    let data = process_and_return(data);
    println!("Processed: {}", data);

    // Multiple return values
    let text = String::from("hello rust");
    let (text, word_count) = count_words(text);
    println!("'{}' has {} words", text, word_count);
}

fn process_and_return(mut s: String) -> String {
    s.push_str(" - processed");
    s
}

fn count_words(s: String) -> (String, usize) {
    let count = s.split_whitespace().count();
    (s, count)
}
```

---

[Next: References and Borrowing →](../2.Borrowing/README.md)

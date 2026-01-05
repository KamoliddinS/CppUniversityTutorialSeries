# 🔍 Type Inference and Annotations

## Overview

Rust has a powerful type inference system. The compiler can often figure out the type of a variable from context, but sometimes you need to provide type annotations explicitly.

## 🤖 Type Inference

### How It Works

```rust
let x = 5;           // Compiler infers i32
let y = 3.14;        // Compiler infers f64
let z = true;        // Compiler infers bool
let s = "hello";     // Compiler infers &str
```

### Inference from Usage

```rust
let mut numbers = Vec::new();  // Type unknown here
numbers.push(5);               // Now compiler knows: Vec<i32>

let result = "42".parse();     // Type unknown
let num: i32 = result.unwrap(); // Now compiler knows parse returns Result<i32, _>
```

### Inference from Return Types

```rust
fn get_number() -> i64 {
    42  // Inferred as i64 due to return type
}
```

## 📝 Type Annotations

### Basic Syntax

```rust
let x: i32 = 5;
let pi: f64 = 3.14159;
let active: bool = true;
let name: &str = "Alice";
let letter: char = 'A';
```

### When Annotations Are Required

#### 1. Ambiguous Types

```rust
// Error: type must be known
let guess = "42".parse();

// Fix: annotate the type
let guess: i32 = "42".parse().unwrap();
// OR
let guess = "42".parse::<i32>().unwrap();
```

#### 2. Empty Collections

```rust
// Error: cannot infer type
let numbers = Vec::new();

// Fix: annotate
let numbers: Vec<i32> = Vec::new();
// OR
let numbers = Vec::<i32>::new();
```

#### 3. Constants and Statics

```rust
// Always required
const MAX: i32 = 100;
static COUNT: u64 = 0;
```

#### 4. Function Parameters and Returns

```rust
// Always required
fn add(a: i32, b: i32) -> i32 {
    a + b
}
```

## 🎯 The Turbofish `::<>`

The "turbofish" syntax specifies types for generic functions:

```rust
// Without turbofish - needs type annotation
let numbers: Vec<i32> = vec![1, 2, 3];
let first: Option<&i32> = numbers.first();

// With turbofish - inline type specification
let numbers = vec![1, 2, 3];
let parsed = "42".parse::<i32>().unwrap();
let collected = (0..10).collect::<Vec<i32>>();
```

### Turbofish Examples

```rust
// Parsing
let int = "42".parse::<i32>().unwrap();
let float = "3.14".parse::<f64>().unwrap();

// Collecting iterators
let vec: Vec<_> = (0..5).collect();           // With annotation
let vec = (0..5).collect::<Vec<i32>>();       // With turbofish
let vec = (0..5).collect::<Vec<_>>();         // Partial turbofish

// Generic functions
fn create<T: Default>() -> T {
    T::default()
}
let num: i32 = create();        // Annotation
let num = create::<i32>();      // Turbofish
```

## 🔄 Type Aliases

Create shorter names for complex types:

```rust
// Type alias
type Kilometers = i32;
type Result<T> = std::result::Result<T, std::io::Error>;

let distance: Kilometers = 100;

fn read_file() -> Result<String> {
    // Returns std::result::Result<String, std::io::Error>
    std::fs::read_to_string("file.txt")
}
```

## 💡 Best Practices

### Let Inference Work

```rust
// Good - inference handles it
let numbers = vec![1, 2, 3];
let sum: i32 = numbers.iter().sum();

// Unnecessary - don't over-annotate
let numbers: Vec<i32> = vec![1, 2, 3];
let x: i32 = 5;  // 5 is obviously an integer
```

### Annotate When Unclear

```rust
// Good - makes intent clear
let timeout: u64 = 30;  // Could be any integer type
let bytes: Vec<u8> = Vec::new();  // Empty, type unknown
```

### Use Turbofish for Chains

```rust
// Readable chain with turbofish
let result = "10,20,30"
    .split(',')
    .map(|s| s.parse::<i32>().unwrap())
    .collect::<Vec<_>>();
```

## 🎨 Underscore for Partial Inference

Let the compiler infer part of a type:

```rust
// Compiler infers the element type
let numbers: Vec<_> = vec![1, 2, 3];

// Compiler infers the error type
let result: Result<i32, _> = "42".parse();

// Useful in complex types
let map: HashMap<_, _> = [("a", 1), ("b", 2)].into_iter().collect();
```

## 📂 Example Code

```rust
fn main() {
    // Type inference
    let inferred_int = 42;           // i32
    let inferred_float = 3.14;       // f64
    let inferred_bool = true;        // bool

    // Explicit annotations
    let explicit_int: i64 = 42;
    let explicit_float: f32 = 3.14;

    // Inference from usage
    let mut numbers = Vec::new();
    numbers.push(1);  // Now Vec<i32>
    numbers.push(2);
    numbers.push(3);
    println!("Numbers: {:?}", numbers);

    // Turbofish
    let parsed = "100".parse::<i32>().unwrap();
    println!("Parsed: {}", parsed);

    let collected = (0..5).collect::<Vec<i32>>();
    println!("Collected: {:?}", collected);

    // Partial inference with _
    let partial: Vec<_> = vec![1, 2, 3];
    println!("Partial: {:?}", partial);

    // Type alias
    type UserId = u64;
    let user_id: UserId = 12345;
    println!("User ID: {}", user_id);
}
```

---

[← Previous: Constants and Statics](../4.ConstantsStatics/README.md) | [Next Lesson: Control Flow →](../../3.ControlFlow/README.md)

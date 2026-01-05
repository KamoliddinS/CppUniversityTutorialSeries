# λ Closures

## Overview

Closures are anonymous functions that can capture variables from their environment. They're similar to lambdas in other languages.

## 🔤 Basic Syntax

```rust
// Function
fn add_one(x: i32) -> i32 {
    x + 1
}

// Equivalent closure
let add_one = |x: i32| -> i32 { x + 1 };

// Simplified (type inference)
let add_one = |x| x + 1;
```

## 📊 Closure Syntax Variations

```rust
// Full syntax
let add = |a: i32, b: i32| -> i32 { a + b };

// Without type annotations
let add = |a, b| a + b;

// Single expression (no braces needed)
let double = |x| x * 2;

// Multiple statements (braces required)
let complex = |x| {
    let y = x * 2;
    let z = y + 1;
    z
};

// No parameters
let say_hi = || println!("Hi!");

// Called immediately
let result = (|x, y| x + y)(5, 3);  // 8
```

## 🎯 Capturing Variables

Closures can capture variables from their environment:

```rust
fn main() {
    let x = 10;

    // Closure captures x
    let add_x = |n| n + x;

    println!("{}", add_x(5));  // 15
}
```

### Capture Modes

| Mode | Trait | Description |
|------|-------|-------------|
| By reference | `Fn` | Borrows immutably |
| By mutable reference | `FnMut` | Borrows mutably |
| By value | `FnOnce` | Takes ownership |

```rust
fn main() {
    // Fn - immutable borrow
    let x = 10;
    let print_x = || println!("{}", x);
    print_x();
    print_x();  // Can call multiple times

    // FnMut - mutable borrow
    let mut count = 0;
    let mut increment = || {
        count += 1;
        println!("Count: {}", count);
    };
    increment();  // Count: 1
    increment();  // Count: 2

    // FnOnce - takes ownership
    let name = String::from("Alice");
    let consume = || {
        println!("Hello, {}", name);
        drop(name);  // Consumes name
    };
    consume();
    // consume();  // Error! Can only call once
}
```

### The `move` Keyword

Force ownership transfer:

```rust
fn main() {
    let numbers = vec![1, 2, 3];

    // Without move - borrows numbers
    let print_nums = || println!("{:?}", numbers);

    // With move - takes ownership
    let own_nums = move || println!("{:?}", numbers);

    // println!("{:?}", numbers);  // Error if used with move
}
```

Useful for threads:

```rust
use std::thread;

fn main() {
    let message = String::from("Hello from thread!");

    let handle = thread::spawn(move || {
        println!("{}", message);
    });

    handle.join().unwrap();
}
```

## 📦 Closures as Parameters

### Using Trait Bounds

```rust
fn apply<F>(f: F, x: i32) -> i32
where
    F: Fn(i32) -> i32,
{
    f(x)
}

fn main() {
    let double = |x| x * 2;
    let result = apply(double, 5);
    println!("Result: {}", result);  // 10
}
```

### Using `impl Trait`

```rust
fn apply(f: impl Fn(i32) -> i32, x: i32) -> i32 {
    f(x)
}
```

### Multiple Calls (Fn)

```rust
fn call_twice<F: Fn()>(f: F) {
    f();
    f();
}
```

### Single Call (FnOnce)

```rust
fn call_once<F: FnOnce() -> String>(f: F) -> String {
    f()
}
```

### Mutating State (FnMut)

```rust
fn apply_mut<F: FnMut()>(mut f: F) {
    f();
    f();
}
```

## 🔄 Returning Closures

```rust
// Using impl Trait
fn make_adder(n: i32) -> impl Fn(i32) -> i32 {
    move |x| x + n
}

// Using Box (for multiple possible return types)
fn make_operation(add: bool) -> Box<dyn Fn(i32) -> i32> {
    if add {
        Box::new(|x| x + 1)
    } else {
        Box::new(|x| x - 1)
    }
}

fn main() {
    let add_5 = make_adder(5);
    println!("{}", add_5(10));  // 15
}
```

## 🎨 Common Patterns

### With Iterator Methods

```rust
fn main() {
    let numbers = vec![1, 2, 3, 4, 5];

    // map
    let doubled: Vec<_> = numbers.iter().map(|x| x * 2).collect();

    // filter
    let evens: Vec<_> = numbers.iter().filter(|x| *x % 2 == 0).collect();

    // fold
    let sum: i32 = numbers.iter().fold(0, |acc, x| acc + x);

    // find
    let first_even = numbers.iter().find(|x| *x % 2 == 0);

    // any/all
    let has_negative = numbers.iter().any(|x| *x < 0);
    let all_positive = numbers.iter().all(|x| *x > 0);
}
```

### Event Handlers / Callbacks

```rust
struct Button {
    on_click: Box<dyn Fn()>,
}

impl Button {
    fn new(handler: impl Fn() + 'static) -> Self {
        Button {
            on_click: Box::new(handler),
        }
    }

    fn click(&self) {
        (self.on_click)();
    }
}

fn main() {
    let button = Button::new(|| println!("Button clicked!"));
    button.click();
}
```

## 📂 Example Code

```rust
fn main() {
    // Basic closure
    let greet = |name| format!("Hello, {}!", name);
    println!("{}", greet("World"));

    // Capturing variables
    let multiplier = 3;
    let multiply = |x| x * multiplier;
    println!("5 * 3 = {}", multiply(5));

    // With iterators
    let numbers = vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

    let sum_of_squares: i32 = numbers
        .iter()
        .filter(|&&x| x % 2 == 0)
        .map(|x| x * x)
        .sum();

    println!("Sum of squares of even numbers: {}", sum_of_squares);

    // Closure as parameter
    let result = apply_to_3(|x| x + 5);
    println!("3 + 5 = {}", result);

    // Returning closure
    let counter = make_counter();
    println!("{}", counter()); // 1
    println!("{}", counter()); // 2
    println!("{}", counter()); // 3

    // FnMut example
    let mut total = 0;
    let mut add_to_total = |x| {
        total += x;
        total
    };
    println!("Total after 5: {}", add_to_total(5));
    println!("Total after 10: {}", add_to_total(10));
}

fn apply_to_3<F>(f: F) -> i32
where
    F: Fn(i32) -> i32,
{
    f(3)
}

fn make_counter() -> impl FnMut() -> i32 {
    let mut count = 0;
    move || {
        count += 1;
        count
    }
}
```

---

[← Previous: Return Values](../3.ReturnValues/README.md) | [Next Lesson: Ownership and Borrowing →](../../5.OwnershipBorrowing/README.md)

# 🔐 Constants and Statics

## Overview

Rust provides two ways to define global, immutable values: **constants** (`const`) and **static variables** (`static`). Understanding the differences is important for writing efficient Rust code.

## 📌 Constants (`const`)

Constants are values that are computed at compile time and inlined wherever they're used.

### Defining Constants

```rust
const MAX_POINTS: u32 = 100_000;
const PI: f64 = 3.14159265358979;
const GREETING: &str = "Hello, World!";
```

### Rules for Constants

| Rule | Description |
|------|-------------|
| **Type Required** | Must annotate the type |
| **Compile-time** | Value must be known at compile time |
| **No `mut`** | Constants are always immutable |
| **SCREAMING_SNAKE_CASE** | Naming convention |
| **Any Scope** | Can be declared in any scope |

### What Can Be Const?

```rust
// ✅ Literals
const A: i32 = 42;
const B: f64 = 3.14;
const C: char = 'x';
const D: bool = true;
const E: &str = "hello";

// ✅ Const expressions
const SUM: i32 = 10 + 20;
const PRODUCT: i32 = 5 * 6;
const ARRAY: [i32; 3] = [1, 2, 3];

// ✅ Const functions (since Rust 1.31)
const fn square(x: i32) -> i32 {
    x * x
}
const SQUARED: i32 = square(5);

// ❌ NOT const - runtime operations
// const RANDOM: i32 = rand::random();  // Error!
// const NOW: Instant = Instant::now(); // Error!
```

### Constants in Practice

```rust
// Global constant
const MAX_USERS: usize = 1000;

fn main() {
    // Local constant
    const BUFFER_SIZE: usize = 4096;

    let users: [&str; MAX_USERS] = [""; MAX_USERS];
    let buffer: [u8; BUFFER_SIZE] = [0; BUFFER_SIZE];
}

mod config {
    // Module-level constant
    pub const API_VERSION: &str = "v1";
}
```

## 📍 Static Variables (`static`)

Static variables have a fixed memory location that persists for the program's lifetime.

### Defining Statics

```rust
static LANGUAGE: &str = "Rust";
static mut COUNTER: i32 = 0;  // Mutable static (unsafe!)
```

### Rules for Statics

| Rule | Description |
|------|-------------|
| **Type Required** | Must annotate the type |
| **Fixed Address** | Has a single memory location |
| **`'static` Lifetime** | Lives for entire program |
| **Can Be Mutable** | With `mut` (but unsafe to access) |

### Mutable Statics (Unsafe)

```rust
static mut COUNTER: i32 = 0;

fn increment() {
    unsafe {
        COUNTER += 1;
    }
}

fn get_count() -> i32 {
    unsafe { COUNTER }
}

fn main() {
    increment();
    increment();
    println!("Count: {}", get_count());
}
```

**Warning**: Mutable statics are unsafe because they can cause data races. Prefer thread-safe alternatives.

## 📊 Const vs Static

| Feature | `const` | `static` |
|---------|---------|----------|
| **Memory** | Inlined (no address) | Fixed address |
| **Mutability** | Never mutable | Can be mutable (unsafe) |
| **Lifetime** | N/A (inlined) | `'static` |
| **Use Case** | Magic numbers, config | Global state, FFI |
| **Performance** | May duplicate values | Single copy |

### When to Use Const

```rust
// Configuration values
const MAX_RETRIES: u32 = 3;
const TIMEOUT_MS: u64 = 5000;

// Mathematical constants
const E: f64 = 2.71828;
const GOLDEN_RATIO: f64 = 1.61803;

// Array sizes
const BUFFER_SIZE: usize = 1024;
let buffer: [u8; BUFFER_SIZE] = [0; BUFFER_SIZE];
```

### When to Use Static

```rust
// When you need a fixed memory address
static VERSION: &str = "1.0.0";

// For FFI (Foreign Function Interface)
#[no_mangle]
pub static EXPORTED_VALUE: i32 = 42;

// Large data that shouldn't be copied
static LOOKUP_TABLE: [u8; 256] = [/* ... */];
```

## 🔧 Thread-Safe Alternatives to Mutable Static

### Using `std::sync::atomic`

```rust
use std::sync::atomic::{AtomicUsize, Ordering};

static COUNTER: AtomicUsize = AtomicUsize::new(0);

fn increment() {
    COUNTER.fetch_add(1, Ordering::SeqCst);
}

fn get_count() -> usize {
    COUNTER.load(Ordering::SeqCst)
}
```

### Using `lazy_static` or `once_cell`

```rust
use std::sync::OnceLock;

static CONFIG: OnceLock<String> = OnceLock::new();

fn get_config() -> &'static str {
    CONFIG.get_or_init(|| {
        // Initialize once
        String::from("default_config")
    })
}
```

## 📂 Example Code

```rust
// Global constants
const MAX_LEVEL: u32 = 100;
const PI: f64 = 3.14159265358979;
const APP_NAME: &str = "RustTutorial";

// Static variable
static VERSION: &str = "1.0.0";

// Const function
const fn calculate_area(radius: f64) -> f64 {
    PI * radius * radius
}

// Compile-time calculation
const UNIT_CIRCLE_AREA: f64 = calculate_area(1.0);

fn main() {
    println!("Welcome to {} v{}", APP_NAME, VERSION);
    println!("Maximum level: {}", MAX_LEVEL);
    println!("Pi: {}", PI);
    println!("Unit circle area: {}", UNIT_CIRCLE_AREA);

    // Using const in expressions
    let radius = 5.0;
    let area = PI * radius * radius;
    println!("Circle with radius {} has area {:.2}", radius, area);

    // Array sized by const
    const SIZE: usize = 5;
    let array: [i32; SIZE] = [1, 2, 3, 4, 5];
    println!("Array: {:?}", array);
}
```

---

[← Previous: Compound Types](../3.CompoundTypes/README.md) | [Next: Type Inference →](../5.TypeInference/README.md)

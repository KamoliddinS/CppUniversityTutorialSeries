# 🦀 Rust Programming Tutorial

Welcome to the **Rust Programming Tutorial**! This comprehensive guide will take you from a complete beginner to a confident Rust programmer. Rust is a systems programming language focused on safety, speed, and concurrency.

## 🎯 Why Learn Rust?

- **Memory Safety**: Rust prevents common bugs like null pointer dereferences and buffer overflows at compile time
- **Zero-Cost Abstractions**: High-level features with no runtime overhead
- **Fearless Concurrency**: Write parallel code without data races
- **Modern Tooling**: Excellent package manager (Cargo), documentation, and compiler error messages
- **Growing Ecosystem**: Used by Mozilla, Microsoft, Amazon, Google, and many others

## 📚 Course Structure

This tutorial is organized into progressive lessons, each building on the concepts from previous ones.

### Beginner Level

| Lesson | Topic | Description |
|--------|-------|-------------|
| 1 | [Introduction to Rust](./1.Introduction/README.md) | Getting started, Hello World, Cargo basics |
| 2 | [Data Types and Variables](./2.DataTypesVariables/README.md) | Primitives, mutability, constants, shadowing |
| 3 | [Control Flow](./3.ControlFlow/README.md) | If/else, loops, pattern matching basics |
| 4 | [Functions](./4.Functions/README.md) | Function syntax, parameters, return values |

### Intermediate Level

| Lesson | Topic | Description |
|--------|-------|-------------|
| 5 | [Ownership and Borrowing](./5.OwnershipBorrowing/README.md) | Rust's unique memory management system |
| 6 | [Structs and Enums](./6.StructsEnums/README.md) | Custom data types, methods, pattern matching |
| 7 | [Error Handling](./7.ErrorHandling/README.md) | Result, Option, panic, error propagation |
| 8 | [Collections](./8.Collections/README.md) | Vec, String, HashMap, iterators |

### Advanced Level

| Lesson | Topic | Description |
|--------|-------|-------------|
| 9 | [Traits and Generics](./9.TraitsGenerics/README.md) | Polymorphism, trait bounds, generic types |
| 10 | [Lifetimes](./10.Lifetimes/README.md) | Lifetime annotations, lifetime elision |

## 🛠️ Prerequisites

Before starting this tutorial, you should:

1. Have basic programming knowledge (any language)
2. Install Rust using [rustup](https://rustup.rs/):
   ```bash
   curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
   ```
3. Verify installation:
   ```bash
   rustc --version
   cargo --version
   ```

## 📁 Repository Structure

Each lesson follows a consistent structure:

```
[LessonNumber.TopicName]/
├── README.md           # Detailed lesson content
├── [Subtopic folders]  # Individual topic folders
│   ├── README.md       # Topic explanation
│   └── src/
│       ├── main.rs     # Example code
│       └── Cargo.toml  # Rust project configuration
```

## 🚀 Getting Started

1. Clone this repository
2. Navigate to `18.RustTutorial`
3. Start with [Lesson 1: Introduction to Rust](./1.Introduction/README.md)
4. Work through each lesson in order
5. Practice with the exercises provided

## 💡 Learning Tips

- **Type the code yourself** - Don't just copy and paste
- **Experiment** - Modify examples and see what happens
- **Read compiler errors** - Rust has excellent error messages
- **Use `cargo check`** - Faster than full compilation for checking errors
- **Embrace the borrow checker** - It's your friend, not your enemy!

## 🔗 Additional Resources

- [The Rust Programming Language Book](https://doc.rust-lang.org/book/)
- [Rust by Example](https://doc.rust-lang.org/rust-by-example/)
- [Rustlings Exercises](https://github.com/rust-lang/rustlings)
- [Rust Standard Library Documentation](https://doc.rust-lang.org/std/)

---

Happy coding! 🦀

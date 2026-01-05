# 📦 Understanding Cargo

## Overview

Cargo is Rust's official package manager and build system. It handles downloading dependencies, compiling your code, running tests, and much more. Think of it as npm for JavaScript or pip for Python, but more integrated into the language.

## 🚀 Why Use Cargo?

| Feature | Benefit |
|---------|---------|
| **Dependency Management** | Automatically downloads and compiles libraries |
| **Build System** | Compiles your project with one command |
| **Project Structure** | Creates standardized project layouts |
| **Testing** | Built-in test runner |
| **Documentation** | Generates HTML documentation |
| **Publishing** | Share packages on crates.io |

## 📂 Creating a Project

### New Project (with Git)
```bash
cargo new my_project
```

Creates:
```
my_project/
├── Cargo.toml
├── .git/
├── .gitignore
└── src/
    └── main.rs
```

### New Library Project
```bash
cargo new my_library --lib
```

Creates:
```
my_library/
├── Cargo.toml
└── src/
    └── lib.rs
```

### Initialize in Existing Directory
```bash
cargo init
```

## 📄 Cargo.toml Explained

The `Cargo.toml` file is your project's manifest:

```toml
[package]
name = "my_project"          # Package name
version = "0.1.0"            # Semantic version
edition = "2021"             # Rust edition (2015, 2018, 2021)
authors = ["Your Name <email@example.com>"]
description = "A brief description"
license = "MIT"

[dependencies]
serde = "1.0"                # External dependency
rand = { version = "0.8", features = ["std"] }

[dev-dependencies]
criterion = "0.5"            # Only for tests/benchmarks

[build-dependencies]
cc = "1.0"                   # Only for build scripts
```

### Edition System

| Edition | Released | Key Features |
|---------|----------|--------------|
| 2015 | May 2015 | Original edition |
| 2018 | Dec 2018 | Module system changes, async/await |
| 2021 | Oct 2021 | Disjoint capture in closures, IntoIterator for arrays |

## 🔧 Essential Commands

### Building and Running

```bash
# Build the project (debug mode)
cargo build

# Build with optimizations (release mode)
cargo build --release

# Build and run
cargo run

# Run with arguments
cargo run -- arg1 arg2

# Run in release mode
cargo run --release
```

### Checking and Testing

```bash
# Check code without compiling (faster)
cargo check

# Run tests
cargo test

# Run a specific test
cargo test test_name

# Run tests with output
cargo test -- --nocapture
```

### Documentation

```bash
# Generate documentation
cargo doc

# Generate and open in browser
cargo doc --open
```

### Dependency Management

```bash
# Update dependencies
cargo update

# Add a dependency (Rust 1.62+)
cargo add serde

# Remove a dependency
cargo remove serde

# View dependency tree
cargo tree
```

### Other Useful Commands

```bash
# Format code
cargo fmt

# Run linter
cargo clippy

# Clean build artifacts
cargo clean

# Publish to crates.io
cargo publish
```

## 📁 Project Structure

A typical Cargo project:

```
my_project/
├── Cargo.toml           # Project manifest
├── Cargo.lock           # Locked dependency versions
├── src/
│   ├── main.rs          # Main entry point (binaries)
│   ├── lib.rs           # Library entry point
│   └── bin/             # Additional binaries
│       └── other.rs
├── tests/               # Integration tests
│   └── integration_test.rs
├── benches/             # Benchmarks
│   └── benchmark.rs
├── examples/            # Example programs
│   └── example.rs
└── target/              # Build output (gitignored)
    ├── debug/
    └── release/
```

## 🔗 Using Dependencies

### From crates.io

```toml
[dependencies]
serde = "1.0"           # Caret requirement: >=1.0.0, <2.0.0
serde = "=1.0.104"      # Exact version
serde = ">=1.0, <2.0"   # Range requirement
```

### From Git

```toml
[dependencies]
my_crate = { git = "https://github.com/user/repo" }
my_crate = { git = "https://github.com/user/repo", branch = "main" }
my_crate = { git = "https://github.com/user/repo", tag = "v1.0" }
```

### From Local Path

```toml
[dependencies]
my_crate = { path = "../my_crate" }
```

### With Features

```toml
[dependencies]
serde = { version = "1.0", features = ["derive"] }
tokio = { version = "1", features = ["full"] }
```

## 🎯 Build Profiles

### Debug (default for `cargo build`)
```toml
[profile.dev]
opt-level = 0      # No optimization
debug = true       # Include debug info
```

### Release (`cargo build --release`)
```toml
[profile.release]
opt-level = 3      # Maximum optimization
debug = false      # No debug info
lto = true         # Link-time optimization
```

## 💡 Tips and Tricks

### 1. Use `cargo check` During Development
It's much faster than `cargo build` for catching errors.

### 2. Enable Clippy Warnings
Add to `Cargo.toml`:
```toml
[lints.clippy]
pedantic = "warn"
```

### 3. Use Workspaces for Multi-Crate Projects
```toml
[workspace]
members = ["crate1", "crate2", "crate3"]
```

### 4. Set Default Features Off
```toml
[dependencies]
library = { version = "1.0", default-features = false }
```

## 🏋️ Exercises

1. Create a new project called "calculator" using Cargo
2. Add the `rand` crate as a dependency
3. Build the project in both debug and release modes
4. Generate and view the documentation

---

[← Previous: Hello World](../2.HelloWorld/README.md) | [Next: Comments and Documentation →](../4.Comments/README.md)

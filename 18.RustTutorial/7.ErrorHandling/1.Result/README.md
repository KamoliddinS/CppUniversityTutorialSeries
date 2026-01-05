# ✅ Recoverable Errors with Result

## Overview

`Result<T, E>` is Rust's primary mechanism for handling recoverable errors. It forces you to explicitly handle potential failures.

## 🔤 The Result Type

```rust
enum Result<T, E> {
    Ok(T),   // Success with value of type T
    Err(E),  // Error with value of type E
}
```

## 📝 Basic Usage

```rust
use std::fs::File;

fn main() {
    let file_result = File::open("hello.txt");

    let file = match file_result {
        Ok(f) => f,
        Err(e) => {
            eprintln!("Failed to open file: {}", e);
            return;
        }
    };
}
```

## 🎯 The `?` Operator

Propagate errors concisely:

```rust
use std::fs::File;
use std::io::{self, Read};

fn read_username() -> Result<String, io::Error> {
    let mut file = File::open("username.txt")?;  // Returns Err if fails
    let mut username = String::new();
    file.read_to_string(&mut username)?;         // Returns Err if fails
    Ok(username)
}

// Even shorter
fn read_username_short() -> Result<String, io::Error> {
    std::fs::read_to_string("username.txt")
}
```

## 🔧 Result Methods

```rust
let ok: Result<i32, &str> = Ok(5);
let err: Result<i32, &str> = Err("error");

// unwrap - panics on Err
let value = ok.unwrap();  // 5

// expect - panics with message on Err
let value = ok.expect("Failed to get value");

// unwrap_or - default on Err
let value = err.unwrap_or(0);  // 0

// unwrap_or_else - computed default
let value = err.unwrap_or_else(|e| {
    eprintln!("Error: {}", e);
    -1
});

// map - transform Ok value
let doubled = ok.map(|x| x * 2);  // Ok(10)

// map_err - transform Err value
let new_err = err.map_err(|e| format!("Error: {}", e));

// and_then - chain operations
let result = ok.and_then(|x| {
    if x > 0 { Ok(x * 2) } else { Err("negative") }
});

// is_ok / is_err
if ok.is_ok() { println!("Success!"); }
```

## 📊 Error Types

### Standard Library Errors

```rust
use std::io;
use std::num::ParseIntError;

fn read_number() -> Result<i32, io::Error> {
    let content = std::fs::read_to_string("number.txt")?;
    // Note: parse returns ParseIntError, not io::Error
    // This won't compile as-is
    Ok(content.trim().parse().unwrap())
}
```

### Custom Error Types

```rust
#[derive(Debug)]
enum AppError {
    IoError(std::io::Error),
    ParseError(std::num::ParseIntError),
    ValidationError(String),
}

impl std::fmt::Display for AppError {
    fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
        match self {
            AppError::IoError(e) => write!(f, "IO error: {}", e),
            AppError::ParseError(e) => write!(f, "Parse error: {}", e),
            AppError::ValidationError(msg) => write!(f, "Validation error: {}", msg),
        }
    }
}

impl From<std::io::Error> for AppError {
    fn from(e: std::io::Error) -> Self {
        AppError::IoError(e)
    }
}
```

### Using `Box<dyn Error>`

```rust
use std::error::Error;

fn do_something() -> Result<(), Box<dyn Error>> {
    let content = std::fs::read_to_string("file.txt")?;
    let number: i32 = content.trim().parse()?;
    println!("Number: {}", number);
    Ok(())
}
```

## 📂 Example Code

```rust
use std::fs::File;
use std::io::{self, BufRead, BufReader};

fn main() {
    match read_first_line("data.txt") {
        Ok(line) => println!("First line: {}", line),
        Err(e) => eprintln!("Error: {}", e),
    }

    // Using unwrap_or_else
    let config = read_config("config.txt").unwrap_or_else(|e| {
        eprintln!("Warning: {}, using defaults", e);
        String::from("default_config")
    });
    println!("Config: {}", config);
}

fn read_first_line(path: &str) -> Result<String, io::Error> {
    let file = File::open(path)?;
    let mut reader = BufReader::new(file);
    let mut line = String::new();
    reader.read_line(&mut line)?;
    Ok(line)
}

fn read_config(path: &str) -> Result<String, io::Error> {
    std::fs::read_to_string(path)
}
```

---

[Next: Unrecoverable Errors with panic! →](../2.Panic/README.md)

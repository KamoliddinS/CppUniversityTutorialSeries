# 16 · Rust for C++ programmers

An optional chapter. After it you can read small Rust programs and say how Rust's rules differ from what you learned in C++.

| # | Lesson | You learn to |
|---|--------|--------------|
| 1 | [Cargo and first differences](01-cargo-and-first-differences/README.md) | build and run a Rust program with Cargo, and name what is different from C++ |
| 2 | [Ownership and moves](02-ownership-and-moves/README.md) | predict when `=` moves a value, and compare that with copies and `std::move` in C++ |
| 3 | [Borrowing](03-borrowing/README.md) | borrow a value with `&` and `&mut`, and name the C++ bugs that the compiler now rejects |
| 4 | [Structs, enums and match](04-structs-enums-and-match/README.md) | model data without classes and without `nullptr` |
| 5 | [Result and Option](05-result-and-option/README.md) | report and handle failures without exceptions |
| 6 | [Traits and generics](06-traits-and-generics/README.md) | write a trait and a generic function, and compare them with abstract classes and templates |
| 7 | [Closures, iterators and lifetimes](07-closures-iterators-and-lifetimes/README.md) | write closures and iterator chains, and read a lifetime annotation |

**Practice:** [Exercises](exercises/README.md)

## Key terms

| Term | Meaning |
|------|---------|
| Cargo | Rust's tool that creates, builds, runs and tests a project |
| ownership | the rule that every Rust value has exactly one owner and is destroyed when that owner goes out of scope |
| move (in Rust) | giving a value to a new owner; the old variable cannot be used any more |
| drop | the clean-up that runs when the owner of a value goes out of scope; Rust's destructor |
| borrow | a reference to a value that someone else owns: `&T` to read it, `&mut T` to change it |
| `Option` | a value that may be missing: `Some(value)` or `None`; Rust has no null |
| `Result` | what a function that can fail returns: `Ok(value)` or `Err(error)` |
| panic | the program stops with a message, because of a bug |
| trait | a list of functions that a type must provide, like an abstract class with only pure virtual functions |
| trait bound | what a generic function needs from its type, for example `T: PartialOrd` |
| closure | a function without a name that can use the variables around it; Rust's lambda |
| lifetime annotation | a name such as `'a` in a signature; it tells the compiler how long a returned reference stays valid |

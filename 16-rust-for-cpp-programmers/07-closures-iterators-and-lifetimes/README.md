# Closures, iterators and lifetimes

> **Goal:** write closures and iterator chains, and read a lifetime annotation.

## Closures and iterator chains

In C++ you pass a lambda to an algorithm
([Lambdas](../../15-standard-library/04-lambdas/README.md),
[Algorithms](../../15-standard-library/05-algorithms/README.md)).
A Rust **closure** is a lambda. The algorithms are methods of an iterator, and you chain them.

| C++ | Rust |
|-----|------|
| `[](int x) { return x * 2; }` | `\|x\| x * 2` |
| `std::count_if(v.begin(), v.end(), f)` | `v.iter().filter(f).count()` |
| `std::transform(...)` | `v.iter().map(f)` |
| `std::accumulate(v.begin(), v.end(), 0)` | `v.iter().sum()` |

**`iterators.rs`**
<!-- file: iterators.rs -->
```rust
struct Student {
    name: String,
    score: u32,
}

fn main() {
    let group = vec![
        Student { name: String::from("Aziz"), score: 72 },
        Student { name: String::from("Malika"), score: 95 },
        Student { name: String::from("Jasur"), score: 58 },
    ];
    let pass = 60;

    let passed = group.iter().filter(|s| s.score >= pass).count();
    let total: u32 = group.iter().map(|s| s.score).sum();
    let names: Vec<&String> = group
        .iter()
        .filter(|s| s.score >= pass)
        .map(|s| &s.name)
        .collect();
    println!("{passed} passed, total {total}, names {names:?}");   // {:?} prints a Vec

    let doubled = group.iter().map(|s| {
        println!("  doubling {}", s.score);
        s.score * 2
    });
    println!("nothing has run yet");
    let sum: u32 = doubled.sum();       // now the closure runs, once for each student
    println!("sum = {sum}");
}
```

<!-- output: iterators -->
```text
2 passed, total 225, names ["Aziz", "Malika"]
nothing has run yet
  doubling 72
  doubling 95
  doubling 58
sum = 450
```

- The first closure uses `pass` from `main`. It only reads `pass`, so it borrows it, like
  `[&]`. Write `move` before the `|` and the closure gets its own `pass` instead.
- `filter` and `map` are lazy: they only describe the work. The work runs when `count`,
  `sum`, `collect` or a `for` loop asks for the values. Look at `nothing has run yet`.

## Lifetimes

In C++ nothing stops a reference from living longer than its variable
([Scope and lifetime](../../04-functions/07-scope-and-lifetime/README.md)). The Rust
compiler must see that a returned reference does not outlive the value it borrows from.
Usually it finds this out by itself. With two reference parameters it cannot:

**`longest_nocompile.rs`**
<!-- file: longest_nocompile.rs -->
```rust
fn longest(a: &str, b: &str) -> &str {
    if a.len() >= b.len() { a } else { b }
}

fn main() {
    println!("{}", longest("Samarkand", "Khiva"));
}
```

<!-- errors: longest_nocompile -->
```text
error[E0106]: missing lifetime specifier
 --> longest_nocompile.rs:1:33
  |
1 | fn longest(a: &str, b: &str) -> &str {
  |               ----     ----     ^ expected named lifetime parameter
  |
  = help: this function's return type contains a borrowed value, but the signature does not say whether it is borrowed from `a` or `b`
help: consider introducing a named lifetime parameter
  |
1 | fn longest<'a>(a: &'a str, b: &'a str) -> &'a str {
  |           ++++     ++          ++          ++

error: aborting due to 1 previous error

For more information about this error, try `rustc --explain E0106`.
```

The `help:` part shows the fix:

**`longest.rs`**
<!-- file: longest.rs -->
```rust
fn longest<'a>(a: &'a str, b: &'a str) -> &'a str {
    if a.len() >= b.len() { a } else { b }
}

fn first_word(text: &str) -> &str {     // one reference comes in: no annotation needed
    text.split(' ').next().unwrap_or("")
}

fn main() {
    println!("{}", longest("Samarkand", "Khiva"));
    println!("{}", first_word("Registan Square"));
}
```

<!-- output: longest -->
```text
Samarkand
Registan
```

`'a` is a **lifetime annotation**: a name for how long a reference is valid. The signature
now says: the result is valid as long as both `a` and `b` are. An annotation changes
nothing at run time; it only tells the compiler what to check. `first_word` needs none: the
result can only borrow from `text`.

## Watch out

- A chain without `count`, `sum`, `collect` or a loop does nothing. The compiler warns:
  `iterators are lazy and do nothing unless consumed`.
- `sum` and `collect` can give several types. Say which one you want:
  `let total: u32 = ...`.

## Try it

1. Predict: you delete the last two lines of `main` in `iterators.rs`. How many `doubling`
   lines appear?
2. Add a chain that gives the highest score with `.max()`. Which type does it return, and why?

<details>
<summary>Answers</summary>

1. None. Nothing asks for the values, so the closure never runs. The compiler warns that
   `doubled` is unused.
2. `group.iter().map(|s| s.score).max()` returns an `Option<u32>`: an empty vector has no
   highest score. Here it is `Some(95)`.
</details>

**Next:** [Exercises for this chapter](../exercises/README.md)

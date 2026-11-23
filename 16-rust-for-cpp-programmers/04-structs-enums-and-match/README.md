# Structs, enums and match

> **Goal:** model data with `struct`, `impl` and `enum`, and handle every case with `match`.

## A struct and an `impl` block instead of a class

In C++ you write a class: data, constructors and member functions in one block
([From struct to class](../../07-classes/01-from-struct-to-class/README.md)).
Rust has no classes. A `struct` holds the data, and an `impl` block holds the functions.

**`account.rs`**
<!-- file: account.rs -->
```rust
struct Account {
    owner: String,
    balance: i32,
}

impl Account {
    fn new(owner: &str) -> Account {            // no `self`: called as Account::new(...)
        Account { owner: String::from(owner), balance: 0 }
    }

    fn deposit(&mut self, amount: i32) {        // &mut self: may change the object
        self.balance += amount;
    }

    fn balance(&self) -> i32 {                  // &self: may only read it
        self.balance
    }
}

fn main() {
    let mut account = Account::new("Malika");
    account.deposit(50000);
    account.deposit(25000);
    println!("{} has {} so'm", account.owner, account.balance());
}
```

<!-- output: account -->
```text
Malika has 75000 so'm
```

| C++ | Rust |
|-----|------|
| a constructor | an ordinary function that returns the struct, usually named `new` |
| `this` | `self`, written as the first parameter |
| `int balance() const` | `fn balance(&self) -> i32` |
| `void deposit(int amount)` | `fn deposit(&mut self, amount: i32)` |
| `private:` | fields are private outside their module (here: the file); `pub` opens them |
| `class Savings : public Account` | no inheritance: put an `Account` inside, and share behaviour with traits ([lesson 6](../06-traits-and-generics/README.md)) |

## An enum whose variants carry data

A C++ `enum class` only names the choices ([Enums](../../06-structs-and-files/02-enums/README.md)).
A Rust variant can also carry values: a tag together with its data. `match` reads the tag
and takes the data out.

**`ticket.rs`**
<!-- file: ticket.rs -->
```rust
enum Ticket {
    Metro,
    Bus,
    Train { km: u32 },                  // this variant carries a number
}

fn price(ticket: Ticket) -> u32 {
    match ticket {
        Ticket::Metro => 3000,
        Ticket::Bus => 2000,
        Ticket::Train { km } => 400 * km,   // km comes out of the variant
    }
}

fn discount(code: &str) -> Option<u32> {    // a percentage, or nothing
    match code {
        "STUDENT" => Some(50),
        "NAVRUZ" => Some(20),
        _ => None,
    }
}

fn main() {
    for ticket in [Ticket::Metro, Ticket::Bus, Ticket::Train { km: 300 }] {
        println!("{} so'm", price(ticket));
    }
    for code in ["STUDENT", "HELLO"] {
        match discount(code) {
            Some(percent) => println!("{code}: {percent}% off"),
            None => println!("{code}: no such code"),
        }
    }
}
```

<!-- output: ticket -->
```text
3000 so'm
2000 so'm
120000 so'm
STUDENT: 50% off
HELLO: no such code
```

`match` must cover every variant. `missing_arm_nocompile.rs` is the same `price` without
the `Bus` line:

<!-- errors: missing_arm_nocompile -->
```text
error[E0004]: non-exhaustive patterns: `Ticket::Bus` not covered
  --> missing_arm_nocompile.rs:8:11
   |
 8 |     match ticket {
   |           ^^^^^^ pattern `Ticket::Bus` not covered
   |
note: `Ticket` defined here
  --> missing_arm_nocompile.rs:1:6
   |
 1 | enum Ticket {
   |      ^^^^^^
 2 |     Metro,
 3 |     Bus,
   |     --- not covered
   = note: the matched value is of type `Ticket`
help: ensure that all possible cases are being handled by adding a match arm with a wildcard pattern or an explicit pattern as shown
   |
10 ~         Ticket::Train { km } => 400 * km,
11 ~         Ticket::Bus => todo!(),
   |

error: aborting due to 1 previous error

For more information about this error, try `rustc --explain E0004`.
```

## No null: `Option`

**`Option`** is an enum from the standard library: `Some(value)` or `None`. Rust has no
null. A value that may be missing has the type `Option<T>`, the same idea as `std::optional<T>`
([Exceptions or return values](../../13-exceptions/05-exceptions-or-return-values/README.md)).
You cannot reach the value without saying what happens for `None`.

## Watch out

- In C++ a `switch` that forgets a `case` still builds; `g++` only warns. In Rust it is an
  error. Add a variant later, and the compiler shows you every `match` to update.

## Try it

1. Predict what `ticket.rs` prints for the code `"student"`. Then try it.
2. Add a variant `Taxi { km: u32 }` that costs 5000 plus 2500 per km. Build before you change
   `price`: what does the compiler say?

<details>
<summary>Answers</summary>

1. `student: no such code`. Text is compared exactly, so only the `_` arm matches.
2. ``non-exhaustive patterns: `Ticket::Taxi { .. }` not covered``. Add the arm
   `Ticket::Taxi { km } => 5000 + 2500 * km,`.
</details>

**Next:** [Result and Option](../05-result-and-option/README.md)

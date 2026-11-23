# Traits and generics

> **Goal:** write a trait and a generic function, and compare them with abstract classes and templates.

## A trait says what a type can do

In C++ you list the functions that several types must have in an abstract class, and each
derived class overrides them
([Abstract classes](../../12-polymorphism/04-abstract-classes/README.md)).
In Rust that list is a **trait**. A type provides the functions in an
`impl Trait for Type` block.

**`shapes.rs`**
<!-- file: shapes.rs -->
```rust
trait Shape {                           // only says what a shape can do
    fn name(&self) -> &str;
    fn area(&self) -> f64;
}

struct Circle {
    radius: f64,
}

struct Square {
    side: f64,
}

impl Shape for Circle {
    fn name(&self) -> &str {
        "circle"
    }
    fn area(&self) -> f64 {
        std::f64::consts::PI * self.radius * self.radius
    }
}

impl Shape for Square {
    fn name(&self) -> &str {
        "square"
    }
    fn area(&self) -> f64 {
        self.side * self.side
    }
}

fn print_area(shape: &dyn Shape) {      // accepts any type that implements Shape
    println!("{}: {:.2}", shape.name(), shape.area());
}

fn main() {
    let shapes: Vec<Box<dyn Shape>> = vec![
        Box::new(Circle { radius: 1.0 }),
        Box::new(Square { side: 2.5 }),
    ];
    for shape in &shapes {
        print_area(shape.as_ref());     // as_ref: borrow the shape inside the Box
    }
}
```

<!-- output: shapes -->
```text
circle: 3.14
square: 6.25
```

| C++ | Rust |
|-----|------|
| `virtual double area() const = 0;` | `fn area(&self) -> f64;` in a `trait` |
| `class Circle : public Shape` | `impl Shape for Circle` |
| `const Shape&` | `&dyn Shape` |
| `std::unique_ptr<Shape>` | `Box<dyn Shape>` |
| `std::make_unique<Circle>(1.0)` | `Box::new(Circle { radius: 1.0 })` |
| `std::vector<std::unique_ptr<Shape>>` | `Vec<Box<dyn Shape>>` |

- `dyn` means: pick the function at run time, like a virtual call
  ([Polymorphic collections](../../12-polymorphism/05-polymorphic-collections/README.md)).
  Nothing is virtual unless you write `dyn`.

## A generic function says what it needs

**`larger.rs`**
<!-- file: larger.rs -->
```rust
fn larger<T: PartialOrd>(a: T, b: T) -> T {
    if a > b { a } else { b }
}

fn main() {
    println!("{}", larger(3, 7));
    println!("{}", larger(2.5, 1.5));
    println!("{}", larger("Samarkand", "Tashkent"));
}
```

<!-- output: larger -->
```text
7
2.5
Tashkent
```

`T: PartialOrd` is a **trait bound**: `T` must be a type that can be compared with `<` and
`>`. The C++ template states no such need
([Function templates](../../14-templates/01-function-templates/README.md)):

<!-- snippet: template_nocompile.cpp -->
```cpp
template <typename T>
T larger(T a, T b) {
    return (a > b) ? a : b;
}
```

C++ checks `a > b` only when the template is used with a real type. So a wrong call is
reported inside the template. Here it is called with two `Book` structs:

<!-- errors: template_nocompile -->
```text
template_nocompile.cpp: In instantiation of ‘T larger(T, T) [with T = Book]’:
template_nocompile.cpp:17:24:   required from here
template_nocompile.cpp:11:15: error: no match for ‘operator>’ (operand types are ‘Book’ and ‘Book’)
   11 |     return (a > b) ? a : b;
      |            ~~~^~~~
```

With `std::sort`, that place is deep inside the library, and the message has about 80
lines. (C++20 can state such a need with a *concept*, as `std::ranges::sort` does.)

Rust checks the body once, against the bound. A wrong call is reported at the call, and the
message names the missing trait (`larger_nocompile.rs`):

<!-- errors: larger_nocompile -->
```text
error[E0277]: can't compare `Book` with `Book`
  --> larger_nocompile.rs:13:20
   |
13 |     println!("{}", larger(atlas, novel).title);
   |                    ^^^^^^ -----  ----- `Book` doesn't satisfy the trait bound
   |                    |      |
   |                    |      `Book` doesn't satisfy the trait bound
   |                    no implementation for `Book < Book` and `Book > Book`
   |
   = help: the trait `PartialOrd` is not implemented for `Book`
note: required by a bound in `larger`
  --> larger_nocompile.rs:6:14
   |
 6 | fn larger<T: PartialOrd>(a: T, b: T) -> T {
   |              ^^^^^^^^^^ required by this bound in `larger`
help: consider annotating `Book` with `#[derive(PartialOrd)]`
   |
 1 + #[derive(PartialOrd)]
 2 | struct Book {
   |

error: aborting due to 1 previous error

For more information about this error, try `rustc --explain E0277`.
```

## Watch out

- A trait is not a type: `&Shape` does not compile, `&dyn Shape` does.

## Try it

1. Add a `Triangle` with `base` and `height` to `shapes.rs` and put one into the vector.
2. Predict: you remove `: PartialOrd` from `larger.rs`. Is the error at the three calls or
   in the body?
3. Make `larger_nocompile.rs` compile. The `help:` gives half of the answer.

<details>
<summary>Answers</summary>

1. With this code and `Box::new(Triangle { base: 3.0, height: 4.0 })` in the vector, it
   prints `triangle: 6.00`.

   ```rust
   struct Triangle { base: f64, height: f64 }
   impl Shape for Triangle {
       fn name(&self) -> &str { "triangle" }
       fn area(&self) -> f64 { 0.5 * self.base * self.height }
   }
   ```
2. In the body: `binary operation > cannot be applied to type T`. Without the bound, the
   body may not compare, whatever the callers pass. The `help:` line suggests the bound.
3. Write `#[derive(PartialEq, PartialOrd)]` above `struct Book`. The compiler then writes
   the comparison for you: by `title` first, then by `pages`.
</details>

**Next:** [Closures, iterators and lifetimes](../07-closures-iterators-and-lifetimes/README.md)

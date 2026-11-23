# Stream operators

> **Goal:** print your type with `<<` and read it with `>>`, as you do with an `int`.

## Print with `<<`

`total.print()` cannot stand inside a `std::cout << ...` line, and it cannot write to a
file. An `operator<<` can do both.

**`print_money.cpp`**
<!-- file: print_money.cpp -->
```cpp
#include <iostream>

class Money {
public:
    Money(long long soms, long long tiyin) : amount_(soms * 100 + tiyin) {}

    friend std::ostream& operator<<(std::ostream& out, const Money& m);

private:
    long long amount_ = 0;      // in tiyin: 1 so'm = 100 tiyin
};

std::ostream& operator<<(std::ostream& out, const Money& m) {
    out << m.amount_ / 100 << " so'm " << m.amount_ % 100 << " tiyin";
    return out;                 // give the stream back for the next <<
}

int main() {
    Money bread(4200, 50);
    Money milk(11800, 75);

    std::cout << "Bread: " << bread << '\n';
    std::cout << "Both:  " << bread << " and " << milk << '\n';
}
```

<!-- output: print_money -->
```text
Bread: 4200 so'm 50 tiyin
Both:  4200 so'm 50 tiyin and 11800 so'm 75 tiyin
```

- In `std::cout << bread` the left operand is the stream, not your object. So `operator<<`
  cannot be a member of `Money`. It is a non-member: `operator<<(std::cout, bread)`.
- It reads the private `amount_`, so the class declares it a
  [friend](../../07-classes/05-static-members-and-friends/README.md). An operator that
  uses only public member functions needs no `friend` line.
- It returns the stream. That makes **chaining** work: in
  `std::cout << bread << " and " << milk`, each `<<` gets the stream that the `<<` before
  it returned.
- `std::ostream` is the type of `std::cout`. A
  [file stream](../../06-structs-and-files/03-write-and-read-files/README.md) can be passed
  as `out` too, so the same operator writes to files.

## Read with `>>`

[`read_money.cpp`](read_money.cpp) adds an `operator>>` and uses it in `main`:

<!-- snippet: read_money.cpp -->
```cpp
std::istream& operator>>(std::istream& in, Money& m) {
    long long soms = 0;
    long long tiyin = 0;
    if (in >> soms >> tiyin) {      // change m only when both numbers were read
        m = Money(soms, tiyin);
    }
    return in;
}

if (!(std::cin >> price)) {
    std::cout << "That is not a price.\n";
    return 1;
}
```

<!-- session: read_money -->
```text
Price (so'm and tiyin): 4200 50
You pay 4200 so'm 50 tiyin.
```

- `std::istream` is the type of `std::cin`. `m` is a reference without `const`: the
  operator changes the caller's object.
- The operator only reads the parts. It prints no question: that is the job of `main`,
  because the input may also come from a file.
- The caller tests the read like any other read
  ([Safe input](../../03-control-flow/07-safe-input/README.md)).

## Watch out

- Inside the operators, use `out` and `in`, not `std::cout` and `std::cin`. Otherwise
  `file << price` prints on the screen.
- Do not print `'\n'` in `operator<<`. The caller decides where the line ends.
- Without `return out;` the program still builds, with a warning. Running it is undefined
  behaviour.

## Try it

1. Predict what `read_money` prints when the user types `4200 abc`.
2. In `print_money.cpp`, write `void` instead of `std::ostream&` in front of
   `operator<<`, in both places, and delete `return out;`. Build. Why do both lines of
   `main` fail?

<details>
<summary>Answers</summary>

1. After the question: `That is not a price.` The second number cannot be read, so the read
   fails and `price` keeps its old value.
2. `error: invalid operands of types 'void' and 'char' to binary 'operator<<'`, and the same
   with `'const char [6]'` for the second line. `std::cout << "Bread: " << bread` now gives
   nothing back, so the next `<<` has no stream on its left.
</details>

**Next:** [Index and increment](../05-index-and-increment/README.md)

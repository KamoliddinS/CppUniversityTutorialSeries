# 08 · Operator overloading

After this chapter your own types work with `+`, `==`, `<<` and `[]` like the built-in ones.

| # | Lesson | You learn to |
|---|--------|--------------|
| 1 | [Operators are functions](01-operators-are-functions/README.md) | read `a + b` as a function call, and write that function |
| 2 | [Arithmetic operators](02-arithmetic-operators/README.md) | give your type `+=`, `+` and unary `-`, and `*` with a number on either side |
| 3 | [Comparison operators](03-comparison-operators/README.md) | compare objects with `==` and `<=>` |
| 4 | [Stream operators](04-stream-operators/README.md) | print and read your type with `<<` and `>>` |
| 5 | [Index and increment](05-index-and-increment/README.md) | add `[]`, `++` and `--` |

**Practice:** [Exercises](exercises/README.md)

## Key terms

| Term | Meaning |
|------|---------|
| operator overloading | writing a function that says what an operator does for your own type |
| operand | a value that an operator works on: `a` and `b` in `a + b` |
| non-member function | an ordinary function that is not part of a class |
| `*this` | inside a member function: the object the function was called on |
| unary operator | an operator with one operand, such as `-a`; a binary operator has two |
| defaulted | written by the compiler because the declaration ends with `= default` |
| three-way comparison | the operator `<=>`: it tells whether the left operand is less than, equal to or greater than the right one |
| chaining | using the result of one operator as the left operand of the next, as in `std::cout << a << b` |
| prefix, postfix | the two forms of `++` and `--`: before the operand (`++x`) or after it (`x++`) |

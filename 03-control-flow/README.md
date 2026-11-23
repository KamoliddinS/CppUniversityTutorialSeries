# 03 · Control flow

After this chapter your programs can make decisions, repeat work and survive wrong input.

| # | Lesson | You learn to |
|---|--------|--------------|
| 1 | [Comparisons and logic](01-comparisons-and-logic/README.md) | write conditions with `==`, `<`, `&&`, `\|\|` and `!` |
| 2 | [If and else](02-if-and-else/README.md) | run code only when a condition is true |
| 3 | [Switch](03-switch/README.md) | choose between several fixed values of one variable |
| 4 | [While loops](04-while-loops/README.md) | repeat a block while a condition is true |
| 5 | [For loops](05-for-loops/README.md) | repeat a block a known number of times |
| 6 | [Loop patterns](06-loop-patterns/README.md) | sum, count, find the largest value, search |
| 7 | [Safe input](07-safe-input/README.md) | keep going when the user types the wrong thing |

**Practice:** [Exercises](exercises/README.md)

## Key terms

| Term | Meaning |
|------|---------|
| condition | a value that is `true` or `false`; `if` and loops test it to decide what to do |
| short-circuit evaluation | the right side of `&&` (and of the or operator) does not run when the left side already decides the result |
| nested | placed inside a statement of the same kind: an `if` inside an `if`, a loop inside a loop |
| fall-through | in a `switch`, running on into the next case because a `break` is missing |
| loop | a statement that repeats a block of code |
| iteration | one run of the block of a loop; one round |
| endless loop | a loop whose condition never becomes false, so it never stops |
| off-by-one error | a loop that runs one round too many or one too few |
| sentinel | a special input value that marks the end of the data, such as `0` |
| flag | a `bool` variable that remembers whether something has happened |
| trace table | a table that follows the values of the variables round by round |
| failed state | the state of `std::cin` after a read that did not work; every later read fails until `clear()` is called |

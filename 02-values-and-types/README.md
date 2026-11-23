# 02 · Values and types

After this chapter you can store numbers and text in variables and calculate with them without surprises.

| # | Lesson | You learn to |
|---|--------|--------------|
| 1 | [Variables](01-variables/README.md) | create a variable, give it a starting value and change it later |
| 2 | [Whole numbers and decimals](02-whole-numbers-and-decimals/README.md) | choose between `int` and `double` and know their limits |
| 3 | [Text, characters and booleans](03-text-characters-and-booleans/README.md) | store text in a `std::string`, one character in a `char` and true or false in a `bool` |
| 4 | [Arithmetic](04-arithmetic/README.md) | calculate with `+ - * / %` and predict what integer division gives |
| 5 | [Conversions](05-conversions/README.md) | predict what mixing `int` and `double` gives, and convert on purpose with `static_cast` |
| 6 | [Constants](06-constants/README.md) | name values that never change with `const` and `constexpr` |

**Practice:** [Exercises](exercises/README.md)

## Key terms

| Term | Meaning |
|------|---------|
| variable | a named place in memory that holds one value |
| type | the kind of value a variable holds, such as `int`, `double` or `std::string` |
| initialise | give a variable its first value in the line that creates it |
| assignment | replacing the value of an existing variable with `=` |
| overflow | a result that does not fit in its type; undefined behaviour for an `int` |
| string | a piece of text; its type is `std::string` |
| integer division | dividing two whole numbers: the fraction is cut off |
| conversion | making a value of one type from a value of another type |
| cast | a conversion you ask for, such as `static_cast<double>(x)` |
| narrowing | a conversion that can lose information, such as `double` to `int` |
| constant | a variable whose value cannot change after it is set (`const` or `constexpr`) |
| magic number | a number in the code whose meaning the reader has to guess |

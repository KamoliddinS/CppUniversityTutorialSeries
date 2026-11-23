# 05 · Vectors and strings

After this chapter you can keep many values in one variable and work with text.

| # | Lesson | You learn to |
|---|--------|--------------|
| 1 | [Vectors](01-vectors/README.md) | store a list of values that can grow, and index it safely |
| 2 | [Loop over a vector](02-loop-over-a-vector/README.md) | visit every element, with or without an index |
| 3 | [Vectors and functions](03-vectors-and-functions/README.md) | pass a list to a function without copying it, and return a new one |
| 4 | [Strings in depth](04-strings-in-depth/README.md) | search, cut and compare text; read whole lines |
| 5 | [Characters](05-characters/README.md) | test and change single characters |
| 6 | [Arrays](06-arrays/README.md) | use fixed-size lists and say why `std::vector` is the default |
| 7 | [Grids](07-grids/README.md) | store a table as a vector of vectors |
| 8 | [Sort and search](08-sort-and-search/README.md) | let the standard library sort, search, count and add up |

**Practice:** [Exercises](exercises/README.md)

## Key terms

| Term | Meaning |
|------|---------|
| vector | a list of values of one type that can grow and shrink (`std::vector`) |
| element | one of the values in a vector, an array or a string |
| index | the position of an element; the first element has index 0 |
| `std::size_t` | the type of a size or an index: a whole number that is never negative |
| range-based `for` | a loop that gives you the elements one by one: `for (int x : v)` |
| `std::string::npos` | the value that `find` returns when it does not find the text |
| whitespace | spaces, tabs and line ends |
| array | a list with a fixed number of elements (`std::array`, or the built-in `int a[5]`) |
| grid | a table of values with rows and columns, stored as a vector of vectors |
| algorithm | a ready-made function of the standard library that works on a list, such as `std::ranges::sort` |

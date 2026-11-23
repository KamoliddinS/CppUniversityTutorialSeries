# 15 · The standard library

After this chapter you can pick the right container and let algorithms do the loops.

| # | Lesson | You learn to |
|---|--------|--------------|
| 1 | [Choose a container](01-choose-a-container/README.md) | pick between `vector`, `deque`, `list` and the rest, and know when a vector moves its elements |
| 2 | [Maps and sets](02-maps-and-sets/README.md) | look things up by key and keep unique values |
| 3 | [Iterators](03-iterators/README.md) | move through any container the same way, and say what `begin()` and `end()` mean |
| 4 | [Lambdas](04-lambdas/README.md) | write a small function right where you need it |
| 5 | [Algorithms](05-algorithms/README.md) | sort, search, count and change a container without writing the loop |
| 6 | [Stack, queue and priority queue](06-stack-queue-priority-queue/README.md) | use containers with a fixed order of access |

**Practice:** [Exercises](exercises/README.md)

## Key terms

| Term | Meaning |
|------|---------|
| container | an object that holds many elements, such as `std::vector` or `std::map` |
| capacity | how many elements fit in the block of memory that a vector has now |
| map | a container that stores a value for each key (`std::map`) |
| key | the value by which a map finds an entry, for example a name |
| set | a container that stores each value once (`std::set`) |
| iterator | a value that marks a position in a container |
| range | the elements from one iterator up to, but not including, another |
| lambda | a small function without a name, written where it is used |
| capture | an outside variable that a lambda may use: `[x]` is a copy, `[&x]` is the variable itself |
| predicate | a function that answers `true` or `false` about an element |
| adaptor | a wrapper around a container that allows only one way in and one way out, such as `std::stack` |

# Choose a container

> **Goal:** pick a container for a task, and know when a vector moves its elements.

## Compare the containers

A **container** is an object that holds many elements. Each one is fast at different
things. Its header has the same name: `<deque>` for `std::deque`.

| Container | Good at | Slow or missing | Big-O |
|-----------|---------|-----------------|-------|
| `std::vector` | the default: indexing, adding at the end | inserting or erasing in the middle: everything after it moves | index O(1), middle O(n) |
| `std::array` | indexing | cannot grow: the size is fixed | index O(1) |
| `std::deque` | indexing; adding and removing at **both** ends (`push_front`, `pop_front`) | the middle: as slow as a vector | ends O(1), middle O(n) |
| `std::list` | inserting or erasing at a known position: nothing moves | no indexing | insert, erase O(1) |
| `std::set`, `std::map` | kept sorted; finding by key is fast | no indexing | find O(log n) |
| `std::unordered_set`, `std::unordered_map` | finding by key is fastest on average | no order | find O(1) on average |

O(1) is the same time for any number of elements n; O(n) grows with n; O(log n) grows very
slowly.

Start with `std::vector`. Change only when the table gives you a reason.

## Size and capacity of a vector

A vector keeps its elements side by side in one block of memory.

**`capacity.cpp`**
<!-- file: capacity.cpp -->
```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;
    for (int i = 1; i <= 6; ++i) {
        v.push_back(i * 10);
        std::cout << "size " << v.size() << "  capacity " << v.capacity() << '\n';
    }
}
```

<!-- output: capacity -->
```text
size 1  capacity 1
size 2  capacity 2
size 3  capacity 4
size 4  capacity 4
size 5  capacity 8
size 6  capacity 8
```

- `size()` is the number of elements. The **capacity** is how many fit in the block.
- When the block is full, `push_back` gets a bigger block, moves every element there and
  frees the old one.
- These numbers are the choice of `g++`. Other compilers may choose others.

## Watch out

**`dangling_bug.cpp`**
<!-- file: dangling_bug.cpp -->
```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> scores = {70, 85, 90};
    int& first = scores[0];        // refers to an element inside the vector

    scores.push_back(60);          // the block is full: the vector moves

    std::cout << first << '\n';    // first still refers to the old block
}
```

Built with `-g -fsanitize=address,undefined`, the program stops (folder name left out):

```text
SUMMARY: AddressSanitizer: heap-use-after-free dangling_bug.cpp:10 in main
```

`first` refers to the old block, which was freed. This is undefined behaviour. Without the
sanitizers, our machine printed a different number on every run.

When a vector moves, every reference, pointer and
[iterator](../03-iterators/README.md) to its elements becomes invalid. Keep the index instead:

<!-- snippet: keep_index.cpp -->
```cpp
    std::size_t first = 0;         // an index stays correct after a move
    scores.push_back(60);
    std::cout << scores[first] << '\n';
```

<!-- output: keep_index -->
```text
70
```

## Try it

1. Which container fits a line where people join at the back and leave at the front?
2. Add `v.reserve(6);` before the loop in `capacity.cpp`: it asks for a block for at least
   6 elements. Predict the output, then run it.

<details>
<summary>Answers</summary>

1. `std::deque`: fast at both ends.
2. `capacity 6` on all six lines. The first block is big enough, so the vector never moves.
</details>

**Next:** [Maps and sets](../02-maps-and-sets/README.md)

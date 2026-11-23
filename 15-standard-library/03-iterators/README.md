# Iterators

> **Goal:** walk through any container with an iterator, and say what `begin()` and `end()` mean.

## A position in a container

An **iterator** is a value that marks a position in a container. Every container gives you two:

```text
           begin()                      end()
              ↓                           ↓
          ┌────────┬────────┬────────┐
  names:  │ Malika │  Aziz  │ Jasur  │  (no element)
          └────────┴────────┴────────┘
```

`begin()` is the position of the first element. `end()` is one **past** the last. A
**range** is everything from `begin()` up to, but not including, `end()`.

**`walk.cpp`**
<!-- file: walk.cpp -->
```cpp
#include <iostream>
#include <set>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> names = {"Malika", "Aziz", "Jasur"};

    for (auto it = names.begin(); it != names.end(); ++it) {
        std::cout << *it << " has " << it->size() << " letters\n";
    }

    std::set<int> years = {2026, 2024, 2025};
    for (auto it = years.begin(); it != years.end(); ++it) {   // the same loop
        std::cout << *it << ' ';
    }
    std::cout << '\n';
}
```

<!-- output: walk -->
```text
Malika has 6 letters
Aziz has 4 letters
Jasur has 5 letters
2024 2025 2026
```

| Code | Meaning |
|------|---------|
| `*it` | the element at this position |
| `it->size()` | a member of that element |
| `++it` | move to the next position |

- `auto` saves you from writing the type `std::vector<std::string>::iterator`.
- The range-based `for` does exactly these steps for you.
- An iterator works like a
  [pointer into an array](../../09-pointers-and-memory/02-pointers-and-arrays/README.md).

## The container decides what its iterators can do

| Container | Its iterators can |
|-----------|-------------------|
| `vector`, `deque`, `array` | step and jump: `++it`, `--it`, `it + 5`, `it2 - it1`, `it1 < it2` |
| `list`, `set`, `map` | only step: `++it`, `--it` |

You do not choose the kind. `std::sort` takes a range as two iterators and needs to jump,
so it refuses a list:

**`sort_list_nocompile.cpp`**
<!-- file: sort_list_nocompile.cpp -->
```cpp
#include <algorithm>
#include <list>

int main() {
    std::list<int> scores = {70, 95, 85};
    std::sort(scores.begin(), scores.end());   // sort needs iterators that can jump
}
```

The message is long. Find the line that names your file, then the first `error`:

```text
sort_list_nocompile.cpp:6:14:   required from here
/usr/include/c++/13/bits/stl_algo.h:1948:50: error: no match for ‘operator-’ (operand types are ‘std::_List_iterator<int>’ and ‘std::_List_iterator<int>’)
```

`std::sort` subtracts two iterators, and a list iterator has no `-`. A list has its own `sort`:

<!-- snippet: list_sort.cpp -->
```cpp
    scores.sort();                             // a member of std::list: it only steps
```

<!-- output: list_sort -->
```text
70 85 95
```

## Not found means `end()`

In [chapter 05](../../05-vectors-and-strings/08-sort-and-search/README.md) you read
`find(...) != v.end()` as "found". The reason: `find` returns an iterator.

**`find_end.cpp`**
<!-- file: find_end.cpp -->
```cpp
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> names = {"Aziz", "Malika", "Jasur"};
    auto it = std::ranges::find(names, "Malika");
    if (it != names.end()) {                       // not end(): Malika was found
        std::cout << *it << " is at index " << it - names.begin() << '\n';
    }
    if (std::ranges::find(names, "Nodira") == names.end()) {
        std::cout << "Nodira is not in the list\n";
    }

    std::map<std::string, int> scores = {{"Aziz", 90}, {"Malika", 95}};
    auto entry = scores.find("Aziz");              // a map has its own find
    if (entry != scores.end()) {
        std::cout << entry->first << " has " << entry->second << '\n';
    }
}
```

<!-- output: find_end -->
```text
Malika is at index 1
Nodira is not in the list
Aziz has 90
```

- When nothing matches, `find` returns `end()`, the position without an element.
- A map entry is a `std::pair`: its member `first` is the key, `second` is the value.

## Watch out

`*v.end()` is undefined behaviour: there is no element at `end()`. Compare an iterator with
`end()` before you use `*` or `->`.

## Try it

1. Predict the output of `predict.cpp`.

   **`predict.cpp`**
   <!-- file: predict.cpp -->
   ```cpp
   #include <iostream>
   #include <vector>

   int main() {
       std::vector<int> v = {10, 20, 30, 40};
       auto it = v.begin();
       ++it;
       std::cout << *it << ' ' << *(it + 2) << ' ' << v.end() - it << '\n';
   }
   ```

2. Change the container in `sort_list_nocompile.cpp` so that the program builds.

<details>
<summary>Answers</summary>

1. `it` is at index 1, and `it + 2` at index 3. From `it` to `end()` there are 3 elements.

   <!-- output: predict -->
   ```text
   20 40 3
   ```

2. Use `std::vector<int>` and include `<vector>`: its iterators can jump. `std::deque`
   works too.
</details>

**Next:** [Lambdas](../04-lambdas/README.md)

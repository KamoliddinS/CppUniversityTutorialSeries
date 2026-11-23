# Maps and sets

> **Goal:** store a value for each key in a `std::map`, and keep unique values in a `std::set`.

## A map stores a value for each key

A vector finds an element by its index. A **map** finds a value by its **key**, and a key
can be text: a score for each name, a price for each product.

**`scores.cpp`**
<!-- file: scores.cpp -->
```cpp
#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> scores;      // key: a name, value: a score
    scores["Malika"] = 95;
    scores["Aziz"] = 90;
    scores["Jasur"] = 72;
    scores["Aziz"] = 91;                    // the key exists: its value is replaced

    for (const auto& [name, score] : scores) {
        std::cout << name << ": " << score << '\n';
    }
    std::cout << scores.size() << " entries\n";
}
```

<!-- output: scores -->
```text
Aziz: 91
Jasur: 72
Malika: 95
3 entries
```

- `scores[key] = value` adds an entry: a key with its value. If the key is already there,
  only its value changes. A map stores each key once.
- The loop visits the entries sorted by key, not in the order you added them.
- An entry is a `std::pair`: one object with two parts. `const auto& [name, score]` gives
  them names: first the key, then the value.

## A set keeps unique values

A **set** stores each value once and keeps the values sorted.

**`unique_cities.cpp`**
<!-- file: unique_cities.cpp -->
```cpp
#include <iostream>
#include <set>
#include <string>

int main() {
    std::set<std::string> cities;
    cities.insert("Samarkand");
    cities.insert("Khiva");
    cities.insert("Samarkand");             // already there: nothing happens
    cities.insert("Bukhara");

    for (const std::string& city : cities) {
        std::cout << city << '\n';
    }
    std::cout << cities.size() << " cities\n";
}
```

<!-- output: unique_cities -->
```text
Bukhara
Khiva
Samarkand
3 cities
```

`cities.contains("Khiva")` tells you whether a value is in the set.

## The unordered versions

`std::unordered_map` and `std::unordered_set` are used the same way and usually find a key
faster. But a loop over them visits the entries in no promised order. Never rely on that
order: when it matters, use `std::map` or sort first.

## Watch out

`scores[key]` looks like a question. But when the key is missing, `[]` **creates** it,
here with the value `0`.

**`missing_key.cpp`**
<!-- file: missing_key.cpp -->
```cpp
#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> scores = {{"Aziz", 90}, {"Malika", 95}};
    std::cout << "size: " << scores.size() << '\n';

    if (scores["Nobody"] == 0) {            // looks like a question, but adds "Nobody"
        std::cout << "Nobody has no score\n";
    }
    std::cout << "size: " << scores.size() << '\n';

    if (scores.contains("Dilnoza")) {       // a real question: adds nothing
        std::cout << "Dilnoza: " << scores.at("Dilnoza") << '\n';
    }
    std::cout << "size: " << scores.size() << '\n';
}
```

<!-- output: missing_key -->
```text
size: 2
Nobody has no score
size: 3
size: 3
```

| Ask without adding | When the key is missing |
|--------------------|-------------------------|
| `scores.contains(key)` | gives `false` (C++20) |
| `scores.at(key)` | throws `std::out_of_range` |
| `scores.find(key)` | gives `scores.end()`: see [Iterators](../03-iterators/README.md) |

For the same reason, `[]` does not compile on a `const` map. Use `at`.

## Try it

1. Predict what `word_count.cpp` prints when the user types the two lines below it.

   **`word_count.cpp`**
   <!-- file: word_count.cpp -->
   ```cpp
   #include <iostream>
   #include <map>
   #include <string>

   int main() {
       std::map<std::string, int> counts;
       std::string word;
       while (std::cin >> word) {
           ++counts[word];
       }

       for (const auto& [text, count] : counts) {
           std::cout << text << ": " << count << '\n';
       }
   }
   ```

   **`word_count.in`**
   <!-- file: word_count.in -->
   ```text
   non choy non
   osh choy non
   ```

2. In `scores.cpp`, change `std::map` to `std::unordered_map` and include
   `<unordered_map>`. What may change in the output?

<details>
<summary>Answers</summary>

1. Here the trap is useful: `[]` creates a new word with `0`, and `++` makes it `1`.

   <!-- output: word_count -->
   ```text
   choy: 2
   non: 3
   osh: 1
   ```

2. Only the order of the three lines with names. No order is promised, so do not rely on
   the one you see.
</details>

**Next:** [Iterators](../03-iterators/README.md)

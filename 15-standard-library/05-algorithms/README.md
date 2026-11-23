# Algorithms

> **Goal:** sort, search, count and change a container with an algorithm and a lambda instead of your own loop.

In [chapter 05](../../05-vectors-and-strings/08-sort-and-search/README.md) you called
algorithms such as `std::ranges::sort(v)`. With a lambda, an algorithm does what you decide.
Most are in `<algorithm>` and take a range as two iterators.

## Sort in your own order

**`sort_students.cpp`**
<!-- file: sort_students.cpp -->
```cpp
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    int score = 0;
};

int main() {
    std::vector<Student> group = {
        {"Aziz", 72}, {"Malika", 95}, {"Jasur", 58}, {"Nodira", 90},
    };

    // The lambda answers one question: does a come before b?
    std::sort(group.begin(), group.end(),
              [](const Student& a, const Student& b) { return a.score > b.score; });
    for (const Student& student : group) {
        std::cout << student.name << ' ' << student.score << '\n';
    }

    // The ranges form takes the container itself and the same kind of lambda.
    std::ranges::sort(group,
                      [](const Student& a, const Student& b) { return a.name < b.name; });
    std::cout << "first by name: " << group[0].name << '\n';
}
```

<!-- output: sort_students -->
```text
Malika 95
Nodira 90
Aziz 72
Jasur 58
first by name: Aziz
```

`return a.score > b.score;` says: `a` comes before `b` when its score is higher.
Use `<` or `>` here, never `<=` or `>=`.

## Ask questions

A **predicate** is a function that answers `true` or `false`, like `failed` here.

**`questions.cpp`**
<!-- file: questions.cpp -->
```cpp
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> scores = {72, 95, 58, 90, 41};
    auto failed = [](int score) { return score < 60; };

    auto first = std::find_if(scores.begin(), scores.end(), failed);
    if (first != scores.end()) {
        std::cout << "first failed score: " << *first << '\n';
    }
    std::cout << "failed: " << std::count_if(scores.begin(), scores.end(), failed) << '\n';

    if (std::any_of(scores.begin(), scores.end(), failed)) {
        std::cout << "somebody failed\n";
    }
    if (!std::all_of(scores.begin(), scores.end(), failed)) {
        std::cout << "but not everybody\n";
    }

    auto best = std::max_element(scores.begin(), scores.end());   // a position
    if (best != scores.end()) {
        std::cout << "best: " << *best << '\n';
    }
}
```

<!-- output: questions -->
```text
first failed score: 58
failed: 2
somebody failed
but not everybody
best: 95
```

| Algorithm | Gives you |
|-----------|-----------|
| `std::find_if` | the position of the first element for which the predicate gives `true`, or the end of the range |
| `std::count_if` | how many elements make the predicate give `true` |
| `std::any_of`, `std::all_of` | `true` if the predicate gives `true` for at least one element, or for all of them |
| `std::max_element`, `std::min_element` | the position of the largest or smallest element |

## Change, remove, add up

**`change.cpp`**
<!-- file: change.cpp -->
```cpp
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<double> weights = {1.5, 2.5, 3.5};     // kilograms

    // Each weight becomes weight * 1000. The results go back into the same vector.
    std::transform(weights.begin(), weights.end(), weights.begin(),
                   [](double kilos) { return kilos * 1000; });

    std::erase_if(weights, [](double grams) { return grams > 3000; });
    for (double grams : weights) {
        std::cout << grams << ' ';
    }
    std::cout << '\n';

    double total = std::accumulate(weights.begin(), weights.end(), 0.0);   // 0.0, not 0
    std::cout << "total: " << total << '\n';

    if (std::binary_search(weights.begin(), weights.end(), 2500.0)) {      // sorted data only
        std::cout << "2500 is there\n";
    }
}
```

<!-- output: change -->
```text
1500 2500
total: 4000
2500 is there
```

| Algorithm | What it does |
|-----------|--------------|
| `std::transform` | calls the lambda on each element and stores the results |
| `std::erase_if` | removes every element for which the lambda gives `true` (C++20) |
| `std::accumulate` | adds the elements to a starting value (header `<numeric>`) |
| `std::binary_search` | says quickly whether a value is there; the range must be sorted |

## Watch out

- `std::accumulate` returns the type of its starting value. For decimal numbers start from
  `0.0`, not `0`.
- `std::max_element` on an empty range returns `end()`. Check before you use `*`.
- With `<=` in the lambda for `std::sort`, two equal elements each come before the other.
  That is undefined behaviour: with 100 equal scores, our test read memory outside the vector.
- Older code removes with `v.erase(std::remove_if(...), v.end())`, the erase-remove idiom.

## Try it

1. In `questions.cpp`, add `int passMark = 80;` and count the scores of at least `passMark`.
   What must the lambda capture?
2. Predict the output of `predict.cpp`.

   **`predict.cpp`**
   <!-- file: predict.cpp -->
   ```cpp
   #include <iostream>
   #include <numeric>
   #include <vector>

   int main() {
       std::vector<double> halves = {0.5, 0.5, 0.5, 0.5};
       std::cout << std::accumulate(halves.begin(), halves.end(), 0) << '\n';
   }
   ```

<details>
<summary>Answers</summary>

1. `[passMark](int score) { return score >= passMark; }` counts 2 scores.
2. The sum is an `int`. Every step stores `0 + 0.5` in it, which is `0` again.

   <!-- output: predict -->
   ```text
   0
   ```

</details>

**Next:** [Stack, queue and priority queue](../06-stack-queue-priority-queue/README.md)

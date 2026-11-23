# Lambdas

> **Goal:** write a small function right where you need it, and let it use variables from outside.

## A function without a name

A **lambda** is a small function without a name. You write it at the place where it is used.

**`first_lambda.cpp`**
<!-- file: first_lambda.cpp -->
```cpp
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    auto twice = [](int x) { return x * 2; };      // a lambda, stored in a variable
    std::cout << twice(21) << '\n';

    std::vector<int> scores = {72, 95, 58, 90};
    auto passed = std::count_if(scores.begin(), scores.end(),
                                [](int score) { return score >= 60; });
    std::cout << passed << " passed\n";
}
```

<!-- output: first_lambda -->
```text
42
3 passed
```

| Part | Meaning |
|------|---------|
| `[]` | the outside variables the lambda may use: none here |
| `(int x)` | the parameters, as in any function |
| `{ return x * 2; }` | the body; the compiler works out the return type |

- Stored in an `auto` variable, a lambda is called like a function: `twice(21)`.
- Its real use is as an argument. `std::count_if` calls the lambda for every element and
  counts how often the answer is `true`. With a
  [function pointer](../../09-pointers-and-memory/07-function-pointers/README.md) you
  needed a named function for this.

## Captures: variables from outside

The square brackets **capture** outside variables: they say which ones the body may use.

**`captures.cpp`**
<!-- file: captures.cpp -->
```cpp
#include <iostream>

int main() {
    int limit = 60;
    auto passes = [limit](int score) { return score >= limit; };   // copies limit now

    limit = 90;                          // too late: the lambda keeps its own 60
    if (passes(75)) {
        std::cout << "75 passes\n";
    }

    int total = 0;
    auto add = [&total](int amount) { total += amount; };          // uses total itself
    add(5000);
    add(2500);
    std::cout << "total: " << total << '\n';
}
```

<!-- output: captures -->
```text
75 passes
total: 7500
```

| Capture | The lambda gets |
|---------|-----------------|
| `[limit]` | a copy of `limit`, made when the lambda is created |
| `[&total]` | `total` itself: a change on one side is seen on the other |
| `[=]` | a copy of every outside variable the body uses |
| `[&]` | every outside variable the body uses, itself |

## One type for different lambdas

Every lambda has its own type, which has no name. That is why you store it with `auto`.
A `std::function<int(int)>` from `<functional>` can hold any lambda that takes an `int` and
returns an `int`.

**`function.cpp`**
<!-- file: function.cpp -->
```cpp
#include <functional>
#include <iostream>

int main() {
    int bonus = 5;

    std::function<int(int)> change = [](int x) { return x * 2; };
    std::cout << change(10) << '\n';

    change = [bonus](int x) { return x + bonus; };   // another lambda, the same variable
    std::cout << change(10) << '\n';
}
```

<!-- output: function -->
```text
20
15
```

## Watch out

- A copy is read-only inside the lambda: `[count]() { ++count; }` does not compile. Write
  `mutable` after the `()` to change the copy. The outside `count` stays as it is.
- A lambda with `[&total]` must not be used after `total` is gone, for example when a
  function returns the lambda. That is undefined behaviour.

## Try it

1. Predict the output of `predict.cpp`.

   **`predict.cpp`**
   <!-- file: predict.cpp -->
   ```cpp
   #include <iostream>

   int main() {
       int x = 1;
       auto byCopy = [x]() { return x * 10; };
       auto byReference = [&x]() { return x * 10; };

       x = 5;
       std::cout << byCopy() << ' ' << byReference() << '\n';
   }
   ```

2. Change `captures.cpp` so that `passes` sees the new value of `limit`.

<details>
<summary>Answers</summary>

1. `byCopy` took its copy when `x` was `1`. `byReference` reads `x` when it is called.

   <!-- output: predict -->
   ```text
   10 50
   ```

2. Capture `[&limit]`. Now `passes(75)` compares with 90, and `75 passes` is not printed.
</details>

**Next:** [Algorithms](../05-algorithms/README.md)

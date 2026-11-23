# Stack, queue and priority queue

> **Goal:** use `std::stack`, `std::queue` and `std::priority_queue` when elements must leave in a fixed order.

## One way in, one way out

An **adaptor** wraps a container and allows only one way in and one way out, like the
[`Stack` of chapter 14](../../14-templates/02-class-templates/README.md). It has no index
and no iterators, so you cannot loop over it.

| Adaptor | Header | Comes out first | Read it | Remove it |
|---------|--------|-----------------|---------|-----------|
| `std::stack` | `<stack>` | the last element put in | `top()` | `pop()` |
| `std::queue` | `<queue>` | the first element put in | `front()` | `pop()` |
| `std::priority_queue` | `<queue>` | the largest element | `top()` | `pop()` |

All three add an element with `push()` and have `empty()` and `size()`.

**`stack_and_queue.cpp`**
<!-- file: stack_and_queue.cpp -->
```cpp
#include <iostream>
#include <queue>
#include <stack>

int main() {
    std::stack<int> stack;
    std::queue<int> queue;
    for (int value = 1; value <= 4; ++value) {     // put in 1, 2, 3, 4
        stack.push(value);
        queue.push(value);
    }

    std::cout << "stack: ";
    while (!stack.empty()) {
        std::cout << stack.top() << ' ';           // read the element ...
        stack.pop();                               // ... then remove it
    }
    std::cout << "\nqueue: ";
    while (!queue.empty()) {
        std::cout << queue.front() << ' ';
        queue.pop();
    }
    std::cout << '\n';
}
```

<!-- output: stack_and_queue -->
```text
stack: 4 3 2 1
queue: 1 2 3 4
```

A stack is like a pile of plates: you take the top one. A queue is like a line in a shop:
who came first leaves first.

## The priority queue: the comparison decides

**`priority.cpp`**
<!-- file: priority.cpp -->
```cpp
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::priority_queue<int> largestFirst;
    std::priority_queue<int, std::vector<int>, std::greater<>> smallestFirst;

    const std::vector<int> values = {30, 50, 10, 40};
    for (int value : values) {
        largestFirst.push(value);
        smallestFirst.push(value);
    }

    while (!largestFirst.empty()) {
        std::cout << largestFirst.top() << ' ';
        largestFirst.pop();
    }
    std::cout << '\n';
    while (!smallestFirst.empty()) {
        std::cout << smallestFirst.top() << ' ';
        smallestFirst.pop();
    }
    std::cout << '\n';
}
```

<!-- output: priority -->
```text
50 40 30 10
10 30 40 50
```

- The order of arrival does not matter. By default the largest element is on top.
- The three arguments are the element type, the container inside, and the comparison.
  `std::greater<>` from `<functional>` puts the smallest element on top.

## Watch out

`pop()` removes an element but returns nothing:

**`pop_nocompile.cpp`**
<!-- file: pop_nocompile.cpp -->
```cpp
#include <iostream>
#include <stack>

int main() {
    std::stack<int> undo;
    undo.push(7);
    int last = undo.pop();
    std::cout << last << '\n';
}
```

<!-- errors: pop_nocompile -->
```text
pop_nocompile.cpp: In function ‘int main()’:
pop_nocompile.cpp:7:24: error: void value not ignored as it ought to be
    7 |     int last = undo.pop();
      |                ~~~~~~~~^~
```

Read first, then remove. Test `empty()` before both. Your `Stack` threw an exception when
it was empty; the standard adaptors do not check. `top()`, `front()` and `pop()` on an
empty adaptor are undefined behaviour: on our machine, `top()` on an empty stack crashed.

<!-- snippet: read_then_pop.cpp -->
```cpp
    if (!undo.empty()) {           // never read or pop an empty stack
        int last = undo.top();     // read ...
        undo.pop();                // ... then remove
        std::cout << last << '\n';
    }
```

<!-- output: read_then_pop -->
```text
7
```

## Try it

1. Predict the output of `predict.cpp`.

   **`predict.cpp`**
   <!-- file: predict.cpp -->
   ```cpp
   #include <iostream>
   #include <queue>
   #include <stack>

   int main() {
       std::stack<int> stack;
       std::queue<int> queue;
       for (int value = 1; value <= 3; ++value) {
           stack.push(value);
           queue.push(value);
       }
       stack.pop();
       queue.pop();
       stack.push(9);
       queue.push(9);

       std::cout << stack.top() << ' ' << queue.front() << ' ' << queue.size() << '\n';
   }
   ```

2. Write a program that prints a word backwards with a `std::stack<char>`.

<details>
<summary>Answers</summary>

1. `pop()` took the newest element, `3`, from the stack and the oldest, `1`, from the
   queue. Then `9` went on top of the stack and to the back of the queue.

   <!-- output: predict -->
   ```text
   9 2 3
   ```

2. Push every character of the word. Then, while the stack is not empty, print `top()` and
   call `pop()`.
</details>

**Next:** [Exercises for this chapter](../exercises/README.md)

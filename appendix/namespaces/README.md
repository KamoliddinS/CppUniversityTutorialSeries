# Namespaces

> **Goal:** say what `std::` means, and put your own names into a namespace.

## A family name for names

A large program uses code from many people. Two of them may both write a function called
`price`. A **namespace** is a named group of names. The full name of a thing is
`group::name`, so the two functions no longer clash.

**`two_shops.cpp`**
<!-- file: two_shops.cpp -->
```cpp
#include <iostream>

namespace bakery {
    int price() { return 4000; }        // one loaf of bread, in so'm
}

namespace bookshop {
    int price() { return 45000; }       // one set of notebooks, in so'm
}

int main() {
    std::cout << "Bread: " << bakery::price() << " so'm\n";
    std::cout << "Notebooks: " << bookshop::price() << " so'm\n";
}
```

<!-- output: two_shops -->
```text
Bread: 4000 so'm
Notebooks: 45000 so'm
```

- `bakery::price()` means "`price` from `bakery`".
- `std` is the namespace of the standard library. `std::cout` means "`cout` from `std`".
- You can open the same namespace again later, also in another file, and add more names to it.

## Shorter names, one at a time

**`one_name.cpp`**
<!-- file: one_name.cpp -->
```cpp
#include <iostream>
#include <string>

using std::cout;        // from here on, cout means std::cout

int main() {
    std::string city = "Khiva";
    cout << city << '\n';
}
```

<!-- output: one_name -->
```text
Khiva
```

`using std::cout;` brings in **one** name. You still see where everything else comes from.

## Why this course never writes `using namespace std;`

That line brings in every name of the standard library: thousands of names you have never
seen. Sooner or later one of them is the same as one of yours.

**`clash_nocompile.cpp`**
<!-- file: clash_nocompile.cpp -->
```cpp
#include <algorithm>
#include <iostream>

using namespace std;    // brings in EVERY name of the standard library

int count = 0;

int main() {
    count = count + 1;
    cout << count << '\n';
}
```

<!-- errors: clash_nocompile -->
```text
clash_nocompile.cpp: In function ‘int main()’:
clash_nocompile.cpp:9:5: error: reference to ‘count’ is ambiguous
    9 |     count = count + 1;
      |     ^~~~~
```

The message goes on to list the candidates: `count` is also the name of a function in the
standard library, so the compiler cannot tell which one you mean. With `std::` in front of library names this cannot happen.

## Watch out

- Never put a `using` line in a header file. It changes the meaning of names in every file
  that includes the header
  ([Headers and source files](../../07-classes/06-headers-and-source-files/README.md)).
- A missing prefix gives `'cout' was not declared in this scope`. The fix is `std::cout`,
  not a `using` line.

## Try it

1. In `two_shops.cpp`, call `price()` without a prefix. What does the compiler say?
2. Make `clash_nocompile.cpp` build in two different ways.

<details>
<summary>Answers</summary>

1. `'price' was not declared in this scope`, followed by the two candidates it knows:
   `bakery::price` and `bookshop::price`.
2. Remove the `using namespace std;` line and write `std::cout`. Or give the variable a
   name that the library does not use, such as `visitors`.
</details>

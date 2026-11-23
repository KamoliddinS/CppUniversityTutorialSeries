# Pointers or references

> **Goal:** choose between a pointer and a reference, and never return the address of a local variable.

## The difference

You know references as parameters. A reference is another name for an object that already
exists. A pointer is a variable of its own that holds an address.

**`rebind.cpp`**
<!-- file: rebind.cpp -->
```cpp
#include <iostream>

int main() {
    int a = 1;
    int b = 2;

    int& r = a;         // r is another name for a
    r = b;              // r still means a: this copies the value of b into a
    std::cout << "a = " << a << ", b = " << b << '\n';

    int* p = &a;        // p points to a
    p = &b;             // now p points to b
    *p = 9;
    std::cout << "a = " << a << ", b = " << b << '\n';
}
```

<!-- output: rebind -->
```text
a = 2, b = 2
a = 2, b = 9
```

Memory at the end. The reference has no row of its own. The pointer has one:

| Name | Address | Value |
|------|---------|-------|
| `a`, also named `r` | `0x1000` | `2` |
| `b` | `0x1004` | `9` |
| `p` | `0x1008` | `0x1004` (points to `b`) |

The differences, side by side:

| | Reference `int& r = a;` | Pointer `int* p = &a;` |
|---|---|---|
| Needs a target when it is created | yes | no |
| Can mean "nothing" | no | yes: `nullptr` |
| Can change its target | no | yes: `p = &b;` |
| Reach the target | `r` | `*p` |
| Reach a member | `r.name` | `p->name` |

Use a reference when there is always an object. Use a pointer when "nothing" is a possible
answer, or when the target must change.

## Both in one function

**`find_student.cpp`**
<!-- file: find_student.cpp -->
```cpp
#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    int grade = 0;
};

// There is always a group: a reference. There may be no such student: a pointer.
Student* findStudent(std::vector<Student>& group, const std::string& name) {
    for (Student& student : group) {
        if (student.name == name) {
            return &student;
        }
    }
    return nullptr;
}

int main() {
    std::vector<Student> group = {{"Aziz", 78}, {"Malika", 91}};

    Student* found = findStudent(group, "Malika");
    if (found != nullptr) {
        found->grade += 5;              // the same as (*found).grade += 5
        std::cout << found->name << ": " << found->grade << '\n';
    }
    if (findStudent(group, "Jasur") == nullptr) {
        std::cout << "Jasur: not found\n";
    }
}
```

<!-- output: find_student -->
```text
Malika: 96
Jasur: not found
```

- `found->grade` means `(*found).grade`.
- The [`this`](../../07-classes/04-const-member-functions/README.md) of a member function
  is a pointer too: it points to the object itself.

## Never return the address of a local variable

**`dangling_bug.cpp`**
<!-- file: dangling_bug.cpp -->
```cpp
#include <iostream>

int* makeNumber() {
    int number = 42;
    return &number;         // number disappears when the function ends
}

int main() {
    int* p = makeNumber();
    std::cout << *p << '\n';
}
```

g++ builds it, but warns:

<!-- errors: dangling_bug -->
```text
dangling_bug.cpp: In function ‘int* makeNumber()’:
dangling_bug.cpp:5:12: warning: address of local variable ‘number’ returned [-Wreturn-local-addr]
    5 |     return &number;         // number disappears when the function ends
      |            ^~~~~~~
dangling_bug.cpp:4:9: note: declared here
    4 |     int number = 42;
      |         ^~~~~~
```

`number` is destroyed when `makeNumber` ends, so the function returns the address of an
object that no longer exists. A pointer to such an object is a **dangling pointer**. Using
`*p` is undefined behaviour: the program may crash, print garbage, or seem to work.
Returning a reference to a local variable (`int& makeNumber()`) is the same mistake. The
fix is to return the value: `int makeNumber()`.

`findStudent` is safe: the student lives in `group`, and `group` is still there after the call.

## Watch out

- `int* p = a;` and `int& r = &a;` do not compile. A pointer needs an address: `&a`.
  A reference needs the variable itself: `a`.
- `findStudent(group, "Jasur")->grade` skips the test. Nobody is found, so this
  dereferences a null pointer.

## Try it

Predict what this program prints, then run it.

**`mix.cpp`**
<!-- file: mix.cpp -->
```cpp
#include <iostream>

int main() {
    int x = 5;
    int y = 8;
    int& r = x;
    int* p = &y;

    r = y;
    *p = 3;
    p = &r;
    *p = *p + 1;

    std::cout << x << ' ' << y << '\n';
}
```

<details>
<summary>Answer</summary>

<!-- output: mix -->
```text
9 3
```

`r = y` puts 8 into `x`. `*p = 3` changes `y`. `&r` is the address of `x`, so after
`p = &r` the last assignment adds 1 to `x`.
</details>

**Next:** [Stack and heap](../05-stack-and-heap/README.md)

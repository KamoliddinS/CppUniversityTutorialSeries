# Destructors and lifetime

> **Goal:** say exactly when an object is created and when it is destroyed.

## The destructor runs when the object's life ends

A local variable lives until the closing brace of its block
([Scope and lifetime](../../04-functions/07-scope-and-lifetime/README.md)). For an object, C++
lets you run code at that moment. The **destructor** is a member function named `~` plus the
class name. It runs automatically when the object's life ends.

**`lifetime.cpp`**
<!-- file: lifetime.cpp -->
```cpp
#include <iostream>
#include <string>

class Reporter {
public:
    explicit Reporter(const std::string& name) : name_(name) {
        std::cout << "create " << name_ << '\n';
    }

    ~Reporter() {
        std::cout << "destroy " << name_ << '\n';
    }

private:
    std::string name_;
};

int main() {
    Reporter a("a");
    Reporter b("b");
    {
        Reporter c("c");
        std::cout << "end of inner block\n";
    }
    std::cout << "end of main\n";
}
```

<!-- output: lifetime -->
```text
create a
create b
create c
end of inner block
destroy c
end of main
destroy b
destroy a
```

- `c` is destroyed at the `}` of the inner block, before `main` goes on.
- `b` is destroyed before `a`: objects are destroyed in the reverse order of their creation.
- Nobody calls `~Reporter()`. The compiler adds the calls for you.

## Objects inside objects

In [`members.cpp`](members.cpp), a `Car` has two `Reporter` members:

<!-- snippet: members.cpp -->
```cpp
class Car {
public:
    Car() : engine_("engine"), radio_("radio") {
        std::cout << "create car\n";
    }

    ~Car() {
        std::cout << "destroy car\n";
    }

private:
    Reporter engine_;
    Reporter radio_;
};

int main() {
    Car car;
    std::cout << "driving\n";
}
```

<!-- output: members -->
```text
create engine
create radio
create car
driving
destroy car
destroy radio
destroy engine
```

| When | Order |
|------|-------|
| creation | the members, in the order they are declared; then the constructor body |
| destruction | the destructor body; then the members, in reverse order |

## Watch out

- Do not call a destructor yourself. It runs once, automatically.
- A destructor has no parameters and no return type, so a class has only one.
- Most classes need no destructor of their own: the compiler writes one that destroys the
  members, and `std::string` and `std::vector` clean up after themselves.
  [RAII](../../10-resource-management/01-raii/README.md) uses a destructor to release
  resources automatically.

## Try it

1. In `lifetime.cpp`, move the line `Reporter b("b");` into the inner block, below `c`.
   Predict the output, then run it.
2. Predict what this loop prints: `for (int i = 0; i < 2; ++i) { Reporter r("r"); }`

<details>
<summary>Answers</summary>

1. `create a`, `create c`, `create b`, `end of inner block`, `destroy b`, `destroy c`,
   `end of main`, `destroy a`.
2. `create r`, `destroy r`, `create r`, `destroy r`. Each round of the loop creates a new
   object and destroys it at the closing brace.
</details>

**Next:** [Const member functions](../04-const-member-functions/README.md)

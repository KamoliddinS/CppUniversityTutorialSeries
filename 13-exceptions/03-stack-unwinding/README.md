# Stack unwinding

> **Goal:** say what is cleaned up while an exception travels to its handler, and what is not.

## Every function on the way is cleaned up

An exception can leave several functions before it reaches a handler. Each of them is
cleaned up: all its local objects are destroyed, the newest first. This is
**stack unwinding**.

`Reporter` is the class from
[Destructors and lifetime](../../07-classes/03-destructors-and-lifetime/README.md). It prints
a line when an object is created and when it is destroyed.

**`unwind.cpp`**
<!-- file: unwind.cpp -->
```cpp
#include <iostream>
#include <stdexcept>
#include <string>

class Reporter {
public:
    explicit Reporter(const std::string& name) : name_(name) {
        std::cout << "create " << name_ << '\n';
    }
    ~Reporter() { std::cout << "destroy " << name_ << '\n'; }

private:
    std::string name_;
};

void inner() {
    Reporter c("c");
    throw std::runtime_error("inner failed");
}

void middle() {
    Reporter b("b");
    inner();
    std::cout << "middle goes on\n";
}

void outer() {
    Reporter a("a");
    middle();
    std::cout << "outer goes on\n";
}

int main() {
    try {
        outer();
    } catch (const std::runtime_error& e) {
        std::cout << "caught: " << e.what() << '\n';
    }
}
```

<!-- output: unwind -->
```text
create a
create b
create c
destroy c
destroy b
destroy a
caught: inner failed
```

- `middle` and `outer` have no `try` block. The exception passes through them, and
  their last lines never run.
- `c`, `b` and `a` are destroyed **before** the handler prints its message.

## What unwinding releases

Destructors run. So what an object owns is released, and what a raw pointer points to is not:

| The function has | Released during unwinding? |
|------------------|----------------------------|
| a `std::string` or a `std::vector` | yes |
| an open file stream | yes: the file is closed |
| a `std::unique_ptr` | yes: it deletes its object |
| a raw pointer from `new` | **no**: a pointer has no destructor |

<!-- snippet: leak_bug.cpp -->
```cpp
void send(bool online) {
    Reporter* message = new Reporter("message");
    if (!online) {
        throw std::runtime_error("no connection");      // leaves before the delete
    }
    std::cout << "sending\n";
    delete message;
}
```

[`leak_bug.cpp`](leak_bug.cpp) calls `send(false)` and catches the exception. It prints:

```text
create message
caught: no connection
```

There is no `destroy message` line: the object leaks. With a
[`std::unique_ptr`](../../10-resource-management/05-unique-ptr/README.md) the same code is safe:

<!-- snippet: no_leak.cpp -->
```cpp
void send(bool online) {
    std::unique_ptr<Reporter> message = std::make_unique<Reporter>("message");
    if (!online) {
        throw std::runtime_error("no connection");      // message is destroyed anyway
    }
    std::cout << "sending\n";
}
```

<!-- output: no_leak -->
```text
create message
destroy message
caught: no connection
```

## Watch out

- If no handler exists anywhere, the program ends, and whether the destructors run first
  is up to the compiler. With g++ they do not run.
- Do not add a `try` block only to `delete` something. Let an object own it:
  [RAII](../../10-resource-management/01-raii/README.md) covers every way out of a function.

## Try it

Move the `try` and `catch` of `unwind.cpp` from `main` into `middle`, around the call
`inner();`. Predict the output before you run it.

<details>
<summary>Answer</summary>

[`caught_in_middle.cpp`](caught_in_middle.cpp) is the changed program. It prints:

<!-- output: caught_in_middle -->
```text
create a
create b
create c
destroy c
caught: inner failed
middle goes on
destroy b
outer goes on
destroy a
```

Only `inner` is unwound. `middle` and `outer` then finish in the normal way.
</details>

**Next:** [Your own exceptions](../04-your-own-exceptions/README.md)

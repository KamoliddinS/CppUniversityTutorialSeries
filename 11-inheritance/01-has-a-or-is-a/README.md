# Has-a or is-a

> **Goal:** choose between composition and inheritance when you build one class from another.

## Two ways to build on a class

**Composition** builds a class from members of other classes. You already do it: a class
with a `std::string` member has a string.

**Inheritance** is new: a class gets the members of an existing class and adds its own.

| | Composition | Inheritance |
|---|-------------|-------------|
| Test sentence | a car **has an** engine | a student **is a** person |
| In code | `Engine engine_;` is a member of `Car` | `class Student : public Person` |
| Code outside can call | only what `Car` defines | every public function of `Person`, and what `Student` adds |

**`student.cpp`**
<!-- file: student.cpp -->
```cpp
#include <iostream>

class Person {
public:
    void greet() const { std::cout << "Salom!\n"; }
};

class Student : public Person {     // a Student IS a Person
public:
    void study() const { std::cout << "Student studies\n"; }
};

int main() {
    Student malika;
    malika.greet();     // comes from Person
    malika.study();     // added by Student
}
```

<!-- output: student -->
```text
Salom!
Student studies
```

`malika.greet()` works, although `Student` never defines `greet`.

## Inheritance used wrongly

A stack is like a pile of plates: you add a value on top, and you take the top value off.
Nothing else. A vector can store the values, so inheriting from it looks like a shortcut:

**`stack_is_a.cpp`**
<!-- file: stack_is_a.cpp -->
```cpp
#include <iostream>
#include <vector>

class Stack : public std::vector<int> {     // "a Stack IS a vector": not true
public:
    void push(int value) { push_back(value); }
    void pop() { pop_back(); }
    int top() const { return back(); }
};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack[0] = 99;      // a vector function: it changes the bottom of the stack

    while (!stack.empty()) {
        std::cout << stack.top() << ' ';
        stack.pop();
    }
    std::cout << '\n';
}
```

<!-- output: stack_is_a -->
```text
30 20 99
```

You pushed 10, 20 and 30, and you got back 30, 20 and 99. `Stack` inherited **all**
functions of the vector, `[]` and `clear()` among them. The compiler accepts every one.

## The repair: has-a

Make the vector a private member. Then `Stack` offers only what you write:

<!-- snippet: stack_has_a.cpp -->
```cpp
class Stack {
public:
    void push(int value) { items_.push_back(value); }
    void pop() { items_.pop_back(); }
    int top() const { return items_.back(); }
    bool empty() const { return items_.empty(); }

private:
    std::vector<int> items_;    // a Stack HAS a vector
};
```

<!-- output: stack_has_a -->
```text
30 20 10
```

`main` is the same, but the line `stack[0] = 99;` no longer compiles, so the file has it
commented out. The compiler now finds the mistake.

## Watch out

- Say the test sentence before you inherit. "A car is an engine" is false: use composition.
- Then check the functions. Inherit only when **every** public function of the old class
  makes sense for the new one. `stack[0] = 99` makes no sense for a stack.
- Not sure? Use composition. It is the default choice.

## Try it

1. Has-a or is-a? (a) library and book, (b) graduate student and student,
   (c) cuboid and rectangle.
2. In [`stack_has_a.cpp`](stack_has_a.cpp), remove the `//` before `stack[0] = 99;` and
   build. Read the error message.

<details>
<summary>Answers</summary>

1. (a) Has-a: a library has books. (b) Is-a: every graduate student is a student.
   (c) Has-a. A cuboid has a rectangular base and a height. An inherited `area()` would
   give the area of one side only.
2. `error: no match for 'operator[]'`: a `Stack` has no `[]`.
</details>

**Next:** [Derive a class](../02-derive-a-class/README.md)

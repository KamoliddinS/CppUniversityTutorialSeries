# Redefine a function

> **Goal:** give a derived class its own version of a base function, and predict which version a call runs.

## Same name, new body

`Person::describe()` prints the name. For a student it should print the id too. `Student`
may define a function with the same name:

**`redefine.cpp`**
<!-- file: redefine.cpp -->
```cpp
#include <iostream>
#include <string>

class Person {
public:
    explicit Person(const std::string& name) : name_(name) {}
    void describe() const { std::cout << "Name: " << name_ << '\n'; }

private:
    std::string name_;
};

class Student : public Person {
public:
    Student(const std::string& name, int id) : Person(name), id_(id) {}
    void describe() const {             // the same name as in Person
        Person::describe();             // call the original
        std::cout << "Student id: " << id_ << '\n';
    }

private:
    int id_ = 0;
};

int main() {
    Student malika("Malika", 1042);
    malika.describe();
}
```

<!-- output: redefine -->
```text
Name: Malika
Student id: 1042
```

- `Student::describe` **hides** `Person::describe`: for a `Student`, the name `describe`
  now means the new function.
- `Person::describe()` calls the original. Without `Person::`, the function would call
  itself without end.

## Hiding works by name

Here `Person` has two functions named `describe`, and `Student` redefines one of them:

**`hidden_nocompile.cpp`**
<!-- file: hidden_nocompile.cpp -->
```cpp
#include <iostream>
#include <string>

class Person {
public:
    void describe() const { std::cout << "a person\n"; }
    void describe(const std::string& title) const { std::cout << title << ": a person\n"; }
};

class Student : public Person {
public:
    void describe() const { std::cout << "a student\n"; }    // hides both functions above
};

int main() {
    Student malika;
    malika.describe();
    malika.describe("Guest");
}
```

<!-- errors: hidden_nocompile -->
```text
hidden_nocompile.cpp: In function ‘int main()’:
hidden_nocompile.cpp:18:20: error: no matching function for call to ‘Student::describe(const char [6])’
   18 |     malika.describe("Guest");
      |     ~~~~~~~~~~~~~~~^~~~~~~~~
hidden_nocompile.cpp:12:10: note: candidate: ‘void Student::describe() const’
   12 |     void describe() const { std::cout << "a student\n"; }    // hides both functions above
      |          ^~~~~~~~
hidden_nocompile.cpp:12:10: note:   candidate expects 0 arguments, 1 provided
```

One `describe` in `Student` hides **every** `describe` of `Person`, whatever its parameters.
The line `using Person::describe;` inside `Student` brings the hidden ones back.

## Through a Person reference

The classes are those of `redefine.cpp`. Only `main` is new:

<!-- snippet: which_one_runs.cpp -->
```cpp
int main() {
    Student malika("Malika", 1042);
    malika.describe();

    Person& ref = malika;       // the same object, seen as a Person
    ref.describe();

    Person* ptr = &malika;
    ptr->describe();

    Person copy = malika;       // a new Person
    copy.describe();
}
```

<!-- output: which_one_runs -->
```text
Name: Malika
Student id: 1042
Name: Malika
Name: Malika
Name: Malika
```

Only the first call prints the id. The other three run `Person::describe`.

- `ref` and `ptr` refer to a `Student`, but their type says `Person`. The compiler chooses
  the function from that type, while it builds the program. This is **static binding**.
- `copy` is a new `Person`. It has no room for an id, so only the `Person` part of `malika`
  is copied. This is **slicing**.

| Name | Address | Value |
|------|---------|-------|
| `malika.name_` (the `Person` part) | `0x1000` | `"Malika"` |
| `malika.id_` | `0x1020` | `1042` |
| `copy.name_` | `0x1040` | `"Malika"` |

## Watch out

- A function that takes a `Person` by value slices every `Student` you give it. Take a
  `const Person&` instead.
- A reference does not slice, but it still runs the `Person` version.

## Try it

1. Add `void introduce(const Person& person) { person.describe(); }` above `main` in
   `which_one_runs.cpp`, and call `introduce(malika);`. Predict what it prints.
2. In `hidden_nocompile.cpp`, add `using Person::describe;` under `public:` in `Student`.
   What does the program print?

<details>
<summary>Answers</summary>

1. `Name: Malika`, and no id. The parameter is a `const Person&`, so the compiler chooses
   `Person::describe`.
2. `a student`, then `Guest: a person`. The call with text finds the function of `Person` again.
</details>

Malika is a student, yet the `Person` version runs.
[Chapter 12](../../12-polymorphism/README.md) makes the object's real type decide.

**Next:** [Multiple inheritance](../05-multiple-inheritance/README.md)

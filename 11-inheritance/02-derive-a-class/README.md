# Derive a class

> **Goal:** write a class that inherits from another, and say which inherited members it may use.

## A Student is a Person with more

A student has a name, like every person, and also a student id. `Person` already stores a
name, so `Student` builds on it:

**`student.cpp`**
<!-- file: student.cpp -->
```cpp
#include <iostream>
#include <string>

class Person {
public:
    const std::string& name() const { return name_; }

protected:
    void setName(const std::string& name) { name_ = name; }

private:
    std::string name_ = "no name";
};

class Student : public Person {
public:
    void enrol(const std::string& name, int id) {
        setName(name);      // protected in Person: a Student may call it
        id_ = id;
    }
    int id() const { return id_; }

private:
    int id_ = 0;
};

int main() {
    Student malika;
    malika.enrol("Malika", 1042);
    std::cout << malika.name() << ' ' << malika.id() << '\n';   // name() comes from Person
}
```

<!-- output: student -->
```text
Malika 1042
```

- `Person` is the **base class**. `Student` is the **derived class**: it inherits the
  members of `Person`.
- `: public Person` keeps the public members of `Person` public in `Student`, so `main` can
  call `malika.name()`.

A `Student` object contains a complete `Person` part, the **base part**, and its own members:

| Name | Address | Value |
|------|---------|-------|
| `malika.name_` (the `Person` part) | `0x1000` | `"Malika"` |
| `malika.id_` (added by `Student`) | `0x1020` | `1042` |

## What Student may use

**`protected`** is a third access level: for the class itself and for its derived classes.
With `public` inheritance the rules are:

| A member of `Person` that is | Code in `Student` | Code outside, such as `main` |
|------------------------------|-------------------|------------------------------|
| `public` | can use it | can use it |
| `protected` | can use it | cannot |
| `private` | cannot | cannot |

`name_` is private in `Person`. It is inside every `Student` object, but the code of
`Student` cannot touch it:

<!-- snippet: private_member_nocompile.cpp -->
```cpp
class Student : public Person {
public:
    void printCard() const { std::cout << name_ << '\n'; }      // name_ is private in Person
};
```

<!-- errors: private_member_nocompile -->
```text
private_member_nocompile.cpp: In member function ‘void Student::printCard() const’:
private_member_nocompile.cpp:14:43: error: ‘std::string Person::name_’ is private within this context
   14 |     void printCard() const { std::cout << name_ << '\n'; }      // name_ is private in Person
      |                                           ^~~~~
private_member_nocompile.cpp:9:17: note: declared private here
    9 |     std::string name_ = "Malika";
      |                 ^~~~~
```

The fix: call the public function `name()` instead.

## Watch out

One missing word changes the meaning:

<!-- snippet: missing_public_nocompile.cpp -->
```cpp
class Student : Person {};      // the word "public" is missing
```

<!-- errors: missing_public_nocompile -->
```text
missing_public_nocompile.cpp: In function ‘int main()’:
missing_public_nocompile.cpp:16:29: error: ‘const std::string& Person::name() const’ is inaccessible within this context
   16 |     std::cout << malika.name() << '\n';
      |                  ~~~~~~~~~~~^~
missing_public_nocompile.cpp:6:24: note: declared here
    6 |     const std::string& name() const { return name_; }
      |                        ^~~~
missing_public_nocompile.cpp:16:29: error: ‘Person’ is not an accessible base of ‘Student’
   16 |     std::cout << malika.name() << '\n';
      |                  ~~~~~~~~~~~^~
```

- Without `public`, a class inherits **privately**: the public members of `Person` become
  private in `Student`. Even `malika.name()` fails in `main`. Always write `public`.
- `private` and `protected` inheritance exist, but you will rarely need them.

## Try it

1. Which of these lines compile at the end of `main` in `student.cpp`? Predict, then try.
   (a) `malika.setName("Aziz");` (b) `malika.id_ = 7;` (c) `std::cout << malika.name();`
2. Add `class GraduateStudent : public Student` with a private `std::string thesis_`, and
   the functions `setThesis` and `thesis`. Create one in `main` and call `enrol` on it.

<details>
<summary>Answers</summary>

1. Only (c). `setName` is protected and `id_` is private, so `main` cannot use them.
2. `enrol`, `id()` and `name()` all work on a `GraduateStudent`: it inherits from `Student`
   everything that `Student` inherited from `Person`. The object has three parts: the
   `Person` part, what `Student` adds, and `thesis_`.
</details>

**Next:** [Constructors in a hierarchy](../03-constructors-in-a-hierarchy/README.md)

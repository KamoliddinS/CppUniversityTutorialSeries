# shared_ptr and weak_ptr

> **Goal:** let several owners share one object, and stop owners from keeping each other alive.

## Several owners

A `std::shared_ptr` can be copied, and each copy is one more owner of the same object. The
owners share a **reference count**, the number of owners; `use_count()` returns it. When
the last owner is gone, the object is destroyed.

**`shared.cpp`**
<!-- file: shared.cpp -->
```cpp
#include <iostream>
#include <memory>
#include <string>

struct Song {
    std::string title;
    explicit Song(const std::string& songTitle) : title(songTitle) {}
    ~Song() { std::cout << title << " is destroyed\n"; }
};

void play(std::shared_ptr<Song> song) {     // by value: one more owner while play runs
    std::cout << "playing " << song->title << ", owners: " << song.use_count() << '\n';
}

int main() {
    auto mine = std::make_shared<Song>("Navo");
    std::cout << "owners: " << mine.use_count() << '\n';
    {
        auto yours = mine;                  // a copy: a second owner of the same Song
        std::cout << "owners: " << mine.use_count() << '\n';
        play(yours);
    }                                       // yours is destroyed
    std::cout << "owners: " << mine.use_count() << '\n';
}                                           // mine is destroyed: no owner is left
```

<!-- output: shared -->
```text
owners: 1
owners: 2
playing Navo, owners: 3
owners: 1
Navo is destroyed
```

- `std::make_shared<Song>("Navo")` creates the object and its first owner.
- `play` takes the pointer by value, so there is a third owner while it runs.

## The trap: a cycle of owners

**`cycle_bug.cpp`**
<!-- file: cycle_bug.cpp -->
```cpp
#include <iostream>
#include <memory>
#include <string>

struct Person {
    std::string name;
    std::shared_ptr<Person> student;
    std::shared_ptr<Person> teacher;
    explicit Person(const std::string& personName) : name(personName) {}
    ~Person() { std::cout << name << " is destroyed\n"; }
};

int main() {
    auto nodira = std::make_shared<Person>("Nodira");
    auto laziz = std::make_shared<Person>("Laziz");
    nodira->student = laziz;        // Nodira owns Laziz
    laziz->teacher = nodira;        // Laziz owns Nodira: a cycle
    std::cout << "owners of Nodira: " << nodira.use_count() << '\n';
    std::cout << "end of main\n";
}
```

```text
owners of Nodira: 2
end of main
```

No `is destroyed` line appears. At the end of `main` the variables `nodira` and `laziz` are
destroyed, and each count falls from 2 to 1, never to 0:

```text
nodira ──► Person "Nodira" ───student───► Person "Laziz" ◄── laziz
                  ▲                             │
                  └───────────teacher───────────┘
```

Each person keeps the other alive. Both leak, and the sanitizer reports
`160 byte(s) leaked in 2 allocation(s)`.

## weak_ptr: look, but do not own

A `std::weak_ptr` points to a shared object without owning it, so the count does not change.
To use the object, call `lock()`. It returns a `shared_ptr`, which is empty when the object
is gone.

**`weak.cpp`**
<!-- file: weak.cpp -->
```cpp
#include <iostream>
#include <memory>
#include <string>

struct Person {
    std::string name;
    std::shared_ptr<Person> student;    // owns the student
    std::weak_ptr<Person> teacher;      // only observes the teacher
    explicit Person(const std::string& personName) : name(personName) {}
    ~Person() { std::cout << name << " is destroyed\n"; }
};

void printTeacher(const Person& person) {
    std::shared_ptr<Person> teacher = person.teacher.lock();
    if (teacher != nullptr) {
        std::cout << person.name << "'s teacher is " << teacher->name << '\n';
    } else {
        std::cout << person.name << "'s teacher is gone\n";
    }
}

int main() {
    auto laziz = std::make_shared<Person>("Laziz");
    {
        auto nodira = std::make_shared<Person>("Nodira");
        nodira->student = laziz;
        laziz->teacher = nodira;        // no new owner: Nodira's count stays 1
        printTeacher(*laziz);
    }                                   // nodira is destroyed, and Nodira with it
    printTeacher(*laziz);
}
```

<!-- output: weak -->
```text
Laziz's teacher is Nodira
Nodira is destroyed
Laziz's teacher is gone
Laziz is destroyed
```

Both destructors run now. Use a `shared_ptr` for the link that owns, and a `weak_ptr` for
the link back.

## Watch out

- Never give one raw pointer to two `shared_ptr`s. Each starts its own count, so the object
  is deleted twice. Create the object with `std::make_shared`, then copy the `shared_ptr`.

```cpp
Song* raw = new Song("Navo");
std::shared_ptr<Song> first(raw);
std::shared_ptr<Song> second(raw);      // a second count for the same Song
```

- Prefer `unique_ptr`. Use `shared_ptr` only when an object really has several owners.

## Try it

1. In `shared.cpp`, let `play` take `const std::shared_ptr<Song>& song`. Predict which line
   of the output changes.
2. In `weak.cpp`, add `std::shared_ptr<Person> keeper;` as the first line of `main` and
   `keeper = laziz->teacher.lock();` as the last line of the inner block. Predict the output.

<details>
<summary>Answers</summary>

1. `playing Navo, owners: 2`. A reference is not a new owner.
2. `Laziz's teacher is Nodira` twice, then `Nodira is destroyed` and `Laziz is destroyed`.
   The pointer that `lock()` returns is an owner: while `keeper` holds it, Nodira stays alive.
</details>

**Next:** [Exercises for this chapter](../exercises/README.md)

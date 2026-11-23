# unique_ptr

> **Goal:** own a heap object without writing `delete`.

## One owner, automatic delete

A **smart pointer** is an object that owns a heap object and deletes it in its destructor:
RAII for `new`. The one to use first is `std::unique_ptr`, from `<memory>`.
`Player`, in [`player.h`](player.h), prints a line when it is created and when it is destroyed.

**`unique.cpp`**
<!-- file: unique.cpp -->
```cpp
#include <iostream>
#include <memory>

#include "player.h"

void greet(const Player& player) {          // only uses the player: a reference is enough
    std::cout << "Hello, " << player.name() << "!\n";
}

int main() {
    auto aziz = std::make_unique<Player>("Aziz");       // a Player on the heap; aziz owns it
    greet(*aziz);                                       // *aziz is the Player itself
    std::cout << aziz->name() << " is ready\n";

    auto malika = std::make_unique<Player>("Malika");
    malika.reset();                                     // deletes Malika now; malika is empty
    std::cout << "end of main\n";
}                                                       // aziz is destroyed and deletes Aziz
```

<!-- output: unique -->
```text
Aziz joins
Hello, Aziz!
Aziz is ready
Malika joins
Malika leaves
end of main
Aziz leaves
```

| Code | Meaning |
|------|---------|
| `std::make_unique<Player>("Aziz")` | create a `Player` on the heap and return its owner |
| `auto` | the compiler fills in the type: `std::unique_ptr<Player>` |
| `aziz->name()`, `*aziz` | use the object, as with a raw pointer |
| `malika.reset()` | delete the object now; `malika` becomes empty (`nullptr`) |
| `aziz.get()` | the raw address, for code that needs a `Player*`; `aziz` stays the owner |

A function that only uses the object takes `Player&` or `const Player&`, as `greet` does.

## One owner means no copies

**`copy_nocompile.cpp`**
<!-- file: copy_nocompile.cpp -->
```cpp
#include <memory>

#include "player.h"

int main() {
    auto p = std::make_unique<Player>("Aziz");
    auto q = p;         // a copy would be a second owner
}
```

<!-- errors: copy_nocompile -->
```text
copy_nocompile.cpp: In function ‘int main()’:
copy_nocompile.cpp:7:14: error: use of deleted function ‘std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = Player; _Dp = std::default_delete<Player>]’
    7 |     auto q = p;         // a copy would be a second owner
      |              ^
In file included from /usr/include/c++/13/memory:78,
                 from copy_nocompile.cpp:1:
/usr/include/c++/13/bits/unique_ptr.h:522:7: note: declared here
  522 |       unique_ptr(const unique_ptr&) = delete;
      |       ^~~~~~~~~~
```

The copy constructor is deleted, as for `Ticket` in the last lesson. A `unique_ptr` can
only be moved: the new owner takes the object and the old owner becomes empty.

## Hand ownership over

**`ownership.cpp`**
<!-- file: ownership.cpp -->
```cpp
#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "player.h"

std::unique_ptr<Player> makePlayer(const std::string& name) {
    auto player = std::make_unique<Player>(name);
    return player;                      // plain return: the caller becomes the owner
}

void sendHome(std::unique_ptr<Player> player) {     // by value: sendHome becomes the owner
    std::cout << player->name() << " goes home\n";
}                                                   // player is destroyed and deletes its Player

int main() {
    auto aziz = makePlayer("Aziz");
    auto malika = makePlayer("Malika");

    std::vector<std::unique_ptr<Player>> team;
    team.push_back(std::move(aziz));    // the vector owns Aziz now
    if (aziz == nullptr) {
        std::cout << "aziz is empty\n";
    }

    sendHome(std::move(malika));        // malika hands its Player over
    std::cout << "Team size: " << team.size() << '\n';
}                                       // team is destroyed and deletes Aziz
```

<!-- output: ownership -->
```text
Aziz joins
Malika joins
aziz is empty
Malika goes home
Malika leaves
Team size: 1
Aziz leaves
```

- `makePlayer` returns the pointer with a plain `return player;`. The caller becomes the owner.
- `sendHome` takes the pointer by value, so it becomes the owner. The caller must write
  `std::move`, and everybody can see that `malika` gives its player away.
- A vector of `unique_ptr`s works: `push_back(std::move(aziz))` moves the pointer in.

A `unique_ptr` is as small as a raw pointer, and using it is just as fast.

## Watch out

- After `std::move(aziz)`, `aziz` is empty. `aziz->name()` is then undefined behaviour;
  usually the program crashes.
- `for (auto player : team)` tries to copy every pointer and does not build. Write
  `for (const auto& player : team)`.

## Try it

1. Predict the output when `main` in `unique.cpp` holds only these lines (add `#include <utility>`):

```cpp
auto a = std::make_unique<Player>("Jasur");
auto b = std::move(a);
a = std::make_unique<Player>("Nodira");
b.reset();
std::cout << "end of main\n";
```

2. Repair `copy_nocompile.cpp`: let `q` take the player over from `p`.

<details>
<summary>Answers</summary>

1. `Jasur joins`, `Nodira joins`, `Jasur leaves`, `end of main`, `Nodira leaves`.
   After the move `b` owns Jasur, so `b.reset()` deletes him. `a` got a new player, who
   lives until the end of `main`.
2. `auto q = std::move(p);` and `#include <utility>`.
</details>

**Next:** [shared_ptr and weak_ptr](../06-shared-ptr-and-weak-ptr/README.md)

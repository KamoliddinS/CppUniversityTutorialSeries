# Exercises · Resource management

Do them in order. Each exercise has its own folder with a starter file.

## How to check your work

From the top folder of the course:

```sh
cmake -B build
ctest --test-dir build -R ex-10-02 --output-on-failure
```

Run the first command once. The second one checks exercise 2 of chapter 10.

`Passed` means your program printed exactly the expected text. Spaces at the end of a line
do not matter; everything else does. You can also build and run the file yourself and
compare with the example.

The check does not look for memory bugs. So build exercises 2, 3, 4 and 6 with the
sanitizer as well, and make sure that no report appears:

```sh
g++ -std=c++20 -Wall -Wextra -g -fsanitize=address,undefined exercise.cpp -o exercise
./exercise
```

| # | Exercise | Kind | Level |
|---|----------|------|-------|
| 1 | [Copy or move](#1--copy-or-move) | predict | warm-up |
| 2 | [Two owners](#2--two-owners) | fix | core |
| 3 | [Hand over](#3--hand-over) | complete | core |
| 4 | [No more delete](#4--no-more-delete) | fix | core |
| 5 | [Count the owners](#5--count-the-owners) | predict | core |
| 6 | [Undo and redo](#6--undo-and-redo) | write | stretch |

## 1 · Copy or move

Folder: [`01-copy-or-move`](01-copy-or-move/). Check: `ex-10-01`.

Read [`program.cpp`](01-copy-or-move/program.cpp) **without running it**. A `Box` prints a
line when it is created, copied, moved and destroyed. Type the output you expect into
`prediction.txt`, line for line. Then run the check.

<details>
<summary>Hint</summary>

Ask the same question for every line of `main`: is the box new, a copy of a box that
stays, or does it take over the content of another box? `makeBox()` builds its box directly
in `d`. At each `}`, the boxes of that block are destroyed in the reverse order of their
creation.
</details>

## 2 · Two owners

Folder: [`02-two-owners`](02-two-owners/). Check: `ex-10-02`.

[`exercise.cpp`](02-two-owners/exercise.cpp) reads three prices into `shop`, makes the
copies `sale` and `backup`, and then changes one price in `sale` and one in `shop`. It
builds, but the three objects share one block: the output is wrong, and at the end the
block is deleted more than once (undefined behaviour, usually a crash). Give `PriceList`
what it needs to be copied correctly. Do not change `main`.

When the user types `4500 12000 800`, the program must print:

```text
shop: 0 12000 800
sale: 4000 12000 800
backup: 4500 12000 800
```

<details>
<summary>Hint</summary>

The rule of three: `PriceList` has a destructor, so it also needs a copy constructor and a
copy assignment operator. See [Copying objects](../02-copying-objects/README.md). `main` also
assigns `backup` to itself, so the assignment needs its `if`.
</details>

## 3 · Hand over

Folder: [`03-hand-over`](03-hand-over/). Check: `ex-10-03`.

A `Photo` owns a block of pixels. Complete the move constructor and the move assignment
operator in [`exercise.cpp`](03-hand-over/exercise.cpp). `main` remembers the address of the
block and checks that the block is handed over, not copied. When both functions are right,
the program prints:

```text
a has 0 pixels, b has 4
b has 0 pixels, c has 4
The block changed its owner twice and was never copied.
```

<details>
<summary>Hint</summary>

Both functions end in the same way: this object holds the size and the address of `other`,
and `other` holds `0` and `nullptr`. The assignment must first give back the block that the
object held before. See [Moving objects](../03-moving-objects/README.md).
</details>

## 4 · No more delete

Folder: [`04-no-more-delete`](04-no-more-delete/). Check: `ex-10-04`.

[`exercise.cpp`](04-no-more-delete/exercise.cpp) loads parcels into a van. Each input line
holds a city and a weight in grams. The program uses `new` and `delete`, and one way
through the loop forgets the `delete`, so one line is missing from the output.

Rewrite the program with `std::unique_ptr`. When you are done, the file contains no `new`
and no `delete`. For this input:

```text
Samarkand 12000
Khiva 25000
Bukhara 15000
Nukus 9000
```

the program must print:

```text
Samarkand: loaded
  (parcel for Samarkand deleted)
Khiva: refused
Bukhara: loaded
  (parcel for Bukhara deleted)
Nukus: the van is full
  (parcel for Nukus deleted)
Total: 27000 g
```

<details>
<summary>Hint</summary>

Let `makeParcel` return a `std::unique_ptr<Parcel>`. `return nullptr;` still works: it gives
back an empty pointer. In `main`, write `auto parcel = makeParcel(city, grams);`. The pointer
is destroyed at the end of every round of the loop, and also at `break`.
</details>

## 5 · Count the owners

Folder: [`05-count-the-owners`](05-count-the-owners/). Check: `ex-10-05`.

Read [`program.cpp`](05-count-the-owners/program.cpp) **without running it**. Keep the number
of owners of the book on paper and update it line by line. Type the output you expect into
`prediction.txt`. Then run the check.

<details>
<summary>Hint</summary>

A copy of a `shared_ptr` is one more owner. A reference and a `weak_ptr` are not. `reset()`
makes one pointer give up its share. The book is destroyed when the last owner gives up.
</details>

## 6 · Undo and redo

Folder: [`06-undo-and-redo`](06-undo-and-redo/). Check: `ex-10-06`.

Write the undo and redo of a small text editor. The text is a list of words, and each typed
word is one `Edit` object. The starter in [`exercise.cpp`](06-undo-and-redo/exercise.cpp) holds the
`Edit` type. An `Edit` cannot be copied, so create each one with `std::make_unique` and keep
the owners in two vectors: the edits of the text, and the edits that were undone.

| Command | What it does |
|---------|--------------|
| `type WORD` | adds a new edit to the end of the text, and destroys all undone edits |
| `undo` | moves the last edit of the text to the undone edits; does nothing when the text is empty |
| `redo` | moves the edit that was undone last back to the end of the text; does nothing when no edit is undone |
| `show` | prints `Text:` and the words of the text, then a line with `Edits in memory:` and `Edit::alive` |

The last line of the starter prints how many edits still exist at the end. It must be 0,
and you must not write `delete`. For this input:

```text
type Salom
type dunyo
show
undo
show
type Toshkent
redo
show
```

the program must print:

```text
Text: Salom dunyo
Edits in memory: 2
Text: Salom
Edits in memory: 2
Text: Salom Toshkent
Edits in memory: 2
Edits in memory at the end: 0
```

<details>
<summary>Hint</summary>

An edit changes its owner like this: `undone.push_back(std::move(done.back()));` and then
`done.pop_back();`. The second line removes the empty pointer that the move left behind.
`undone.clear();` removes all elements of a vector, and each `unique_ptr` deletes its `Edit`.
</details>

**Next chapter:** [11 · Inheritance](../../11-inheritance/README.md)

# Exercises · Templates

Do them in order. Each exercise has its own folder with a starter file.

## How to check your work

From the top folder of the course:

```sh
cmake -B build
ctest --test-dir build -R ex-14-02 --output-on-failure
```

Run the first command once. The second one checks exercise 2 of chapter 14.

`Passed` means your program printed exactly the expected text. Spaces at the end of a line
do not matter; everything else does. You can also build and run the file yourself and
compare with the example.

Exercise 3 reads no input. Its `main` calls your functions and prints one line for every
check that fails. You are done when it prints `All checks passed.`

The starters of exercises 2 to 5 do not build at first: a template is used in the wrong
way, or it is not written yet. Build, read the first error, fix it, and build again.

| # | Exercise | Kind | Level |
|---|----------|------|-------|
| 1 | [Which type](#1--which-type) | predict | warm-up |
| 2 | [Fix the calls](#2--fix-the-calls) | fix | warm-up |
| 3 | [From int to any type](#3--from-int-to-any-type) | complete | core |
| 4 | [Pair](#4--pair) | write | core |
| 5 | [Bounded queue](#5--bounded-queue) | write | stretch |

## 1 · Which type

Folder: [`01-which-type`](01-which-type/). Check: `ex-14-01`.

Read [`program.cpp`](01-which-type/program.cpp) **without running it**. For each call,
decide first which type `T` is. Type the output you expect into `prediction.txt`, line for
line. Then run the check.

<details>
<summary>Hint</summary>

Dividing an `int` by 2 drops the part after the point; dividing a `double` does not. In
`half<int>(metres)` you say that `T` is `int`, so the value of `metres` is converted to an
`int` before the function runs.
</details>

## 2 · Fix the calls

Folder: [`02-fix-the-calls`](02-fix-the-calls/). Check: `ex-14-02`.

[`exercise.cpp`](02-fix-the-calls/exercise.cpp) calls the template `larger` four times, and
none of the four calls builds. The template is correct: do not change it. Fix the code
that uses it until the program prints:

```text
12
3.5
Khiva
hall
```

A room is larger when its `area` is larger.

<details>
<summary>Hint</summary>

Three calls give the compiler two different answers for `T`. Say the type yourself, and
think about which type makes the second line print `3.5`. In the messages,
`std::__cxx11::basic_string<char>` is the long name of `std::string`.

The fourth error is reported inside the template. Its `required from here` note points to
your line: `Room` has no `operator>` yet.
</details>

## 3 · From int to any type

Folder: [`03-from-int-to-any-type`](03-from-int-to-any-type/). Check: `ex-14-03`.

In [`exercise.cpp`](03-from-int-to-any-type/exercise.cpp), `swapValues` and `countMatches`
are correct, but they work only for `int`. The checks in `main` also use `char` and
`std::string`, so the file does not build. Turn both functions into function templates.
Do not change `check` and `main`.

| Call | Result |
|------|--------|
| `swapValues(first, second)` with the strings `Aziz` and `Malika` | `first` is `Malika`, `second` is `Aziz` |
| `countMatches(letters, 'a')` with the letters `a n a n a s` | `3` |

<details>
<summary>Hint</summary>

Write `template <typename T>` above each function. Then replace `int` by `T`, but only
where `int` means "the type of the values". The counter in `countMatches` stays an `int`:
a count is a whole number for every `T`.
</details>

The name is `swapValues` because the standard library already has `std::swap`.

## 4 · Pair

Folder: [`04-pair`](04-pair/). Check: `ex-14-04`.

Write a class template `Pair<A, B>` that holds two values. The two types can be different.

| Member | What it does |
|--------|--------------|
| `Pair(const A& first, const B& second)` | stores the two values |
| `first()` | returns the first value |
| `second()` | returns the second value |
| `swapped()` | returns a `Pair<B, A>` with the same two values in the other order |

`main` in [`exercise.cpp`](04-pair/exercise.cpp) is already written: do not change it.
With your class it prints:

```text
Dilnoza is 19
2.5 kg
19 Dilnoza
```

<details>
<summary>Hint</summary>

A template can have two parameters: `template <typename A, typename B>`. The class needs
two data members, one of type `A` and one of type `B`.
</details>

The standard library has a class like this: `std::pair`. You use it in
[Maps and sets](../../15-standard-library/02-maps-and-sets/README.md).

## 5 · Bounded queue

Folder: [`05-bounded-queue`](05-bounded-queue/). Check: `ex-14-05`.

A queue works like a line of people: the value that was added first leaves first. This
queue is bounded: it has room for a fixed number of values. Write the class template
`Queue<T>`:

| Member | What it does |
|--------|--------------|
| `explicit Queue(std::size_t capacity)` | makes an empty queue with room for `capacity` values |
| `push(value)` | adds `value` at the back; throws `std::length_error` if the queue is full |
| `pop()` | removes the front value; throws `std::out_of_range` if the queue is empty |
| `front()` | returns the front value; throws `std::out_of_range` if the queue is empty |
| `size()` | returns the number of values in the queue |
| `empty()` | returns `true` if the queue holds no value |
| `full()` | returns `true` if there is no room for one more value |

Then write the function template `moveAll(from, to)`. It moves values from the front of
the queue `from` to the back of the queue `to`, until `from` is empty or `to` is full. It
returns the number of values that it moved, as an `int`.

`main` in [`exercise.cpp`](05-bounded-queue/exercise.cpp) is already written: do not
change it. With your code it prints:

```text
Aziz is first of 4
The line is full.
3 moved
Nodira still waits
1 moved
Nobody to remove.
Nobody in front.
18 1
```

<details>
<summary>Hint</summary>

Keep the values in a `std::vector<T>`, as the `Stack` in
[Class templates](../02-class-templates/README.md) does. `items_.erase(items_.begin());`
removes the first element of a vector named `items_`
([Iterators](../../15-standard-library/03-iterators/README.md) explains `begin()`).
`std::length_error` is one more exception class from `<stdexcept>`: it says that
something is longer than allowed.

`moveAll` is not a member of the class, so it needs its own `template <typename T>` line.
Both parameters have the type `Queue<T>&`.
</details>

**Next chapter:** [15 · The standard library](../../15-standard-library/README.md)

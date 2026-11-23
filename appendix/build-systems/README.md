# Build systems

> **Goal:** build a program made of several files with one short command.

## Why `g++` by hand is not enough

The folder [`shop`](shop/) holds one small program in three files, split as in
[Headers and source files](../../07-classes/06-headers-and-source-files/README.md).

```text
shop/
    discount.h      declares priceAfterDiscount()
    discount.cpp    includes discount.h and defines the function
    main.cpp        includes discount.h and calls the function
```

It prints:

<!-- output: shop -->
```text
To pay: 10800 so'm
```

Build it by hand:

```sh
cd shop
g++ -std=c++20 -Wall -Wextra main.cpp discount.cpp -o shop
```

With hundreds of files this command gets long, and it compiles every file each time,
changed or not. A **build system** keeps the commands in a file and compiles only what
changed.

## Make

Make reads rules from a file named `Makefile`. A rule says which file to make, from which
files, and with which command.

**`shop/Makefile`**
<!-- file: shop/Makefile -->
```make
shop: main.o discount.o
	g++ main.o discount.o -o shop

main.o: main.cpp discount.h
	g++ -std=c++20 -Wall -Wextra -c main.cpp

discount.o: discount.cpp discount.h
	g++ -std=c++20 -Wall -Wextra -c discount.cpp
```

| Line | Meaning |
|------|---------|
| `shop: main.o discount.o` | `shop` is made from two object files |
| `g++ main.o discount.o -o shop` | the command that makes it: link them |
| `main.o: main.cpp discount.h` | `main.o` is made from `main.cpp`, which includes `discount.h` |
| `g++ ... -c main.cpp` | `-c` means compile only: the result is `main.o` |

The last rule does the same for `discount.cpp`. Make runs a command only when the file on
the left is missing, or older than a file on the right.

```sh
make
./shop
```

On Windows, first install Make in the MSYS2 UCRT64 terminal:
`pacman -S mingw-w64-ucrt-x86_64-make`. Its command is `mingw32-make`.

The first run shows three commands:

```text
g++ -std=c++20 -Wall -Wextra -c main.cpp
g++ -std=c++20 -Wall -Wextra -c discount.cpp
g++ main.o discount.o -o shop
```

## CMake

This Makefile names one compiler, `g++`. With CMake you only list what to build, in
`CMakeLists.txt`. CMake then writes the build files for your computer, for example a
Makefile.

**`shop/CMakeLists.txt`**
<!-- file: shop/CMakeLists.txt -->
```cmake
cmake_minimum_required(VERSION 3.21)
project(shop LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(shop main.cpp discount.cpp)
```

| Line | Meaning |
|------|---------|
| `cmake_minimum_required(VERSION 3.21)` | the oldest CMake that may read this file |
| `project(shop LANGUAGES CXX)` | the name of the project; `CXX` means C++ |
| `set(CMAKE_CXX_STANDARD 20)` | use C++20 |
| `set(CMAKE_CXX_STANDARD_REQUIRED ON)` | stop if the compiler cannot do C++20 |
| `add_executable(shop main.cpp discount.cpp)` | build the program `shop` from these files |

```sh
cmake -B build
cmake --build build
./build/shop
```

The first command reads `CMakeLists.txt` and writes the build files into the folder
`build`. The second compiles and links.

## The course itself uses CMake

The [`CMakeLists.txt`](../../CMakeLists.txt) in the top folder of the course knows every
example and exercise. There, the same two commands build all lesson examples (the first
is needed only once), and a third checks an exercise:

```sh
cmake -B build
cmake --build build
ctest --test-dir build -R ex-03-02 --output-on-failure
```

`ctest` builds and checks exercise 2 of chapter 03. `-R` chooses tests by name, and
`--output-on-failure` shows what a failing program printed.

## Watch out

- A command in a `Makefile` must start with a **tab**. With spaces, Make stops with
  `missing separator`.
- Everything in `build` can be made again. Do not edit it, and do not add it to Git.

## Try it

Run `make` again. Then change the `10` in `main.cpp` to `20` and run `make` once more.
Which commands run each time?

<details>
<summary>Answer</summary>

First none: no source file changed, and Make prints `make: 'shop' is up to date.` Then two: `main.cpp` is compiled, and the program is
linked again. `discount.o` is kept: its sources did not change.
</details>

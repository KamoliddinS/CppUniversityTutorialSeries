# Program arguments

> **Goal:** give a program its values on the command line, and report failure with an exit code.

## Words after the program's name

`g++` asks no questions. You type what it needs after its name: `g++ hello.cpp -o hello`.
Your program receives such **command-line arguments** through two parameters of `main`.

**`show_args.cpp`**
<!-- file: show_args.cpp -->
```cpp
#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "argc is " << argc << '\n';
    for (int i = 1; i < argc; ++i) {
        std::cout << "argv[" << i << "] is " << argv[i] << '\n';
    }
}
```

Start it with two arguments:

```sh
./show_args Samarkand 2026
```

<!-- output: show_args -->
```text
argc is 3
argv[1] is Samarkand
argv[2] is 2026
```

| | Value | Meaning |
|---|-------|---------|
| `argc` | `3` | the number of words on the command line |
| `argv[0]` | `./show_args` | the program's name, as it was typed |
| `argv[1]` | `Samarkand` | the first argument |
| `argv[2]` | `2026` | the second argument: text, not a number |

`char* argv[]` is an old way to write "a list of texts".
[Pointers and arrays](../../09-pointers-and-memory/02-pointers-and-arrays/README.md)
explains the type. Until then, treat `argv[i]` as text: print it, or copy it into a
`std::string`.

## Use the arguments

**`first_lines.cpp`**
<!-- file: first_lines.cpp -->
```cpp
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 3) {                        // the program's name and two arguments
        std::cout << "Usage: first_lines FILE COUNT\n";
        return 1;
    }
    std::string fileName = argv[1];
    int count = std::stoi(argv[2]);         // an argument is text: convert it

    std::ifstream in(fileName);
    if (!in) {
        std::cout << "Cannot open " << fileName << '\n';
        return 1;
    }

    std::string line;
    int shown = 0;
    while (shown < count && std::getline(in, line)) {
        std::cout << line << '\n';
        ++shown;
    }
}
```

Give it a file name and a number:

```sh
./first_lines cities.txt 2
```

<!-- output: first_lines -->
```text
Tashkent
Samarkand
```

- Check `argc` before you use `argv[1]`. Without arguments `argv[1]` holds no text, and
  using it as text is undefined behaviour.
- An argument is always text. `std::stoi` turns it into a number.
- The Run button of VS Code starts a program without arguments. Use the terminal.
- The course's checks take the arguments from `show_args.args` and `first_lines.args`
  ([CONTRIBUTING](../../CONTRIBUTING.md)).

## The exit code

`return 1;` ends `main` and hands the number 1 to the system. This **exit code** tells
whoever started the program how it went: 0 means success, anything else means failure.
A `main` that reaches its end returns 0.

```sh
./first_lines nothing.txt 2
echo $?
```

```text
Cannot open nothing.txt
1
```

`echo $?` prints the exit code of the last program. In PowerShell it is `echo $LASTEXITCODE`.

## Watch out

- `argv[1] == "yes"` does not compare the letters, and g++ warns about it. Copy the
  argument into a `std::string` first. Then `==` works.
- `std::stoi` stops the program when the argument is not a number
  ([Parse lines](../04-parse-lines/README.md)).

## Try it

1. Predict the output of `./show_args one "two three" 4`.
2. Run `./first_lines cities.txt`, then `echo $?`. Explain both lines of output.

<details>
<summary>Answers</summary>

1. `argc is 4`, then `argv[1] is one`, `argv[2] is two three` and `argv[3] is 4`. Quotes
   keep several words together as one argument.
2. `Usage: first_lines FILE COUNT` and `1`. There is only one argument, so `argc` is 2 and
   not 3. The program explains how to start it and returns 1.
</details>

**Next:** [Exercises for this chapter](../exercises/README.md)

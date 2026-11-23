# Install the tools on macOS

These steps follow the official VS Code guide
[Using Clang in Visual Studio Code](https://code.visualstudio.com/docs/cpp/config-clang-mac).
If a step fails, look there.

## 1. Compiler, debugger and Git

Open the **Terminal** app and type:

```sh
xcode-select --install
```

A window asks to install the *command line developer tools*. Accept, and wait until it is done.
If the answer is that the tools `are already installed`, go on.

You now have `clang++` (Apple's C++ compiler), a debugger and `git`.

## 2. `g++` on a Mac is Apple's compiler

The command `g++` also exists on a Mac. It starts the same Apple compiler, so the build
command of this course works as written:

```sh
g++ -std=c++20 -Wall -Wextra hello.cpp -o hello
```

Never leave out `-std=c++20`. Without it, Apple's compiler uses an older version of C++, and
examples that need newer features do not build.

## 3. CMake

| You have | Do this |
|----------|---------|
| [Homebrew](https://brew.sh) | type `brew install cmake` |
| no Homebrew | download the `.dmg` file from [cmake.org/download](https://cmake.org/download/), drag **CMake** to **Applications**, open it, choose **Tools → How to Install For Command Line Use** and do what the window says |

## 4. VS Code

Download it from [code.visualstudio.com](https://code.visualstudio.com/), open the downloaded
file and drag **Visual Studio Code** to **Applications**.

## Check

```sh
g++ --version
git --version
cmake --version
```

Each command must answer with a version number. `g++ --version` answers with
`Apple clang version` and a number. That is correct.

**Back to:** [Install the tools, step 2](README.md#2-get-the-course)

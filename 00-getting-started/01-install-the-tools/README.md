# Install the tools

> **Goal:** install a C++ compiler, VS Code, Git and CMake, and check that all four work.

## What you need

| Tool | What it does |
|------|--------------|
| A C++20 compiler: `g++` 13 or newer, or Apple `clang++` | turns your code into a program |
| VS Code with the C/C++ extension | the editor where you write, build and debug |
| Git | downloads the course and keeps versions of your work |
| **CMake** 3.21 or newer | builds many programs with one command; the course uses it to check your exercises |

## 1. Install: pick your system

| Your computer | Follow |
|---------------|--------|
| Windows 10 or 11 | [Install the tools on Windows](windows.md) |
| macOS | [Install the tools on macOS](macos.md) |
| Linux | [Install the tools on Linux](linux.md) |
| Any computer, nothing to install | [Use a ready machine](codespaces.md) in your browser |

## 2. Get the course

Open a terminal, the window where you type commands (on Windows: PowerShell), and type:

```sh
git clone https://github.com/KamoliddinS/CppUniversityTutorialSeries.git
```

A new folder `CppUniversityTutorialSeries` appears, normally in your home folder. It holds the
course. [Use Git](../03-use-git/README.md) explains this command.

## 3. Open the course in VS Code

1. Choose **File → Open Folder** and pick `CppUniversityTutorialSeries`.
   If VS Code asks whether you trust the authors, answer yes. It does not build or debug otherwise.
2. Choose **View → Extensions**, search for `C/C++` (from Microsoft) and press **Install**.

The folder already contains build and debug settings (in `.vscode/`), so there is nothing to set up:

| In VS Code | What happens |
|------------|--------------|
| **Terminal → Run Build Task** | the file you have open is built |
| **F5** | it is built and started in the debugger |

## Check that it works

Choose **Terminal → New Terminal** in VS Code and type:

```sh
cd 01-first-programs/01-hello-world
g++ -std=c++20 -Wall -Wextra hello.cpp -o hello
./hello
cmake --version
```

| Command | You must see |
|---------|--------------|
| `g++ ...` | nothing. No message means the build worked. |
| `./hello` (in PowerShell: `.\hello.exe`) | `Hello, world!` |
| `cmake --version` | `cmake version 3.21` or a higher number |

The `g++` line is the build command of the whole course. Only the two names change.

**Next:** [Use the terminal](../02-use-the-terminal/README.md)

# Install the tools on Linux

These steps are for Ubuntu and Debian. They follow the official VS Code guide
[Using C++ on Linux in VS Code](https://code.visualstudio.com/docs/cpp/config-linux).
If a step fails, look there.

## 1. Compiler, debugger, CMake and Git

Open a terminal (on Ubuntu: press Ctrl+Alt+T) and type:

```sh
sudo apt update
sudo apt install build-essential gdb cmake git
```

| Package | You get |
|---------|---------|
| `build-essential` | `g++`, the compiler |
| `gdb` | the debugger |
| `cmake`, `git` | CMake and Git |

On Fedora, type `sudo dnf install gcc-c++ make gdb cmake git` instead.

## 2. Check the version of the compiler

```sh
g++ --version
```

The first line of the answer ends with the version:

```text
g++ (Ubuntu 13.3.0-6ubuntu2~24.04.1) 13.3.0
```

The course needs `g++` 13 or newer. Ubuntu 24.04 and Debian 13 have it. Ubuntu 22.04 (`g++` 11)
and Debian 12 (`g++` 12) are too old: upgrade the system, or [use a ready machine](codespaces.md).

## 3. VS Code

| System | Do this |
|--------|---------|
| Ubuntu | type `sudo snap install --classic code` |
| Debian | download the `.deb` file from [code.visualstudio.com](https://code.visualstudio.com/), then type `sudo apt install ./<file>.deb` with the name of that file |

## Check

```sh
g++ --version
gdb --version
cmake --version
git --version
```

Each command must answer with a version number.

**Back to:** [Install the tools, step 2](README.md#2-get-the-course)

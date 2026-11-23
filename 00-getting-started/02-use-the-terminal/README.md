# Use the terminal

> **Goal:** move between folders and run commands in a terminal.

## One window, one current folder

A **terminal** is a window where you type a command and press Enter. In VS Code,
**Terminal → New Terminal** opens one in the folder that is open in VS Code.
On Windows it runs PowerShell, on macOS zsh, on Linux bash.

A terminal is always inside one folder, the **current folder**. Commands work on that folder.
The text before the cursor shows it:

```text
PS C:\Users\Malika\CppUniversityTutorialSeries>       Windows (PowerShell)
malika@laptop:~/CppUniversityTutorialSeries$          Linux (bash); ~ is your home folder
malika@macbook CppUniversityTutorialSeries %          macOS (zsh)
```

A **path** names a file by the folders that lead to it:
`01-first-programs/01-hello-world/hello.cpp`.

## The commands you need

| You want to | Type | In PowerShell, if different |
|-------------|------|-----------------------------|
| see the current folder | `pwd` | |
| list what is in it | `ls` | |
| go into a folder | `cd 01-first-programs` | |
| go up one folder | `cd ..` | |
| make a folder | `mkdir practice` | |
| copy a file | `cp hello.cpp copy.cpp` | |
| copy a folder with everything in it | `cp -r practice backup` | `cp -Recurse practice backup` |
| run a program in the current folder | `./hello` | `.\hello.exe` |

| Key | What it does |
|-----|--------------|
| Ctrl+C | stops the program that is running |
| Up arrow | brings back the command before; Enter runs it again |
| Tab | completes a file or folder name that you started to type |

## Watch out

- `hello` alone does not start your program. A terminal looks in the current folder only
  when you write `./` (PowerShell: `.\`).
- `cp` without `-r` (PowerShell: `-Recurse`) does not copy what is inside a folder.
- `cp` replaces a file that already has the new name, without asking. The old file is lost.
- A name with a space needs quotes: `cd "My Programs"`.
- PowerShell also accepts `/` in a path, so the paths in this course work on Windows as written.

## Check that it works

Open the course folder in VS Code, open a terminal and type these lines. Use Tab for the
long names.

```sh
pwd
cd 01-first-programs/02-output-and-input
ls
g++ -std=c++20 -Wall -Wextra greet.cpp -o greet
./greet
```

| Step | You must see |
|------|--------------|
| `pwd` | a path that ends in `CppUniversityTutorialSeries` |
| `ls` | a list of files with `greet.cpp` in it |
| `./greet` (PowerShell: `.\greet.exe`) | `What is your name?` Then the program waits. |
| press Ctrl+C | the program stops |
| press Up arrow | the last command is on the line again |
| `cd ../..` and then `pwd` | the same path as in the first step |

**Next:** [Use Git](../03-use-git/README.md)

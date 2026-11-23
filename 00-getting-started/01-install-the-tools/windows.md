# Install the tools on Windows

You need 64-bit Windows 10 (version 1809 or later) or Windows 11.

These steps follow the official VS Code guide
[Using GCC with MinGW](https://code.visualstudio.com/docs/cpp/config-mingw).
If a step fails, look there.

## 1. Compiler, debugger and CMake

1. Download the installer from [msys2.org](https://www.msys2.org/) and run it.
   Keep the suggested folder `C:\msys64`.
2. On the last page leave the box **Run MSYS2 now** checked and press **Finish**.
   A terminal opens. (Later you find it in the Start menu as **MSYS2 UCRT64**.)
3. Copy the line below. In that terminal, right-click and choose **Paste** (or press
   Shift+Insert), then press Enter. Press Enter again when it asks
   `Proceed with installation? [Y/n]`.

   ```sh
   pacman -S --needed mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-gdb mingw-w64-ucrt-x86_64-cmake mingw-w64-ucrt-x86_64-ninja
   ```

   You get `g++` (the compiler), `gdb` (the debugger), CMake, and Ninja, the build tool that
   CMake uses here. If `pacman` reports `failed retrieving file`, follow the
   [MSYS2 update guide](https://www.msys2.org/docs/updating/) and repeat this step.

## 2. Add the tools to PATH

**`PATH`** is the list of folders where the system looks for a program when you type its name.
The new tools are not in it yet.

1. Open Windows **Settings** and search for **Edit environment variables for your account**.
2. Under **User variables**, select **Path**, then **Edit**.
3. Select **New** and type `C:\msys64\ucrt64\bin`.
4. Select **OK**, then **OK** again.
5. Close every terminal and VS Code window. Only windows opened after this step know the new `PATH`.

## 3. Git and VS Code

| Tool | Get it from | Install with |
|------|-------------|--------------|
| Git for Windows | [gitforwindows.org](https://gitforwindows.org/) | the default options |
| VS Code | [code.visualstudio.com](https://code.visualstudio.com/) | the default options |

## Check

Open **PowerShell** from the Start menu (not the MSYS2 terminal) and type:

```powershell
g++ --version
gdb --version
cmake --version
git --version
```

Each command must answer with a version number. If PowerShell answers
`The term 'g++' is not recognized`, repeat part 2 and open a new PowerShell window.

## Run a program in PowerShell

`g++ ... -o hello` makes a file named `hello.exe`. Run it like this:

```powershell
.\hello.exe
```

`.\` means "in the current folder". PowerShell does not look there unless you say so.

## Another way: WSL

WSL gives you Ubuntu Linux inside Windows. Follow the official guide
[Using C++ and WSL in VS Code](https://code.visualstudio.com/docs/cpp/config-wsl), and install
the packages listed in [Install the tools on Linux](linux.md).

**Back to:** [Install the tools, step 2](README.md#2-get-the-course)

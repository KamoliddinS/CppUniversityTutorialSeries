# Introduction to  C++ (Getting Started)

## C++ Central Asian University Course

Welcome to the C++ course repository. Each directory in this repository represents a lesson. Each lesson has a `src` directory that contains the source code for that particular lesson.

## Setting Up

### 1. Installing g++

Before you can compile and run C++ programs, you need to have the `g++` compiler installed.

#### On Ubuntu/Linux:

```bash
sudo apt update
sudo apt install g++ 
```

#### On macOS:

If you have Homebrew installed:

```bash
brew install gcc
```
to varify installation, open a new terminal and type:
    
    ```bash
    g++ --version
    ```
    
or you can install the Xcode Command Line Tools, which include `g++`:

```bash
sudo xcode-select --install
```

Otherwise, you can install Xcode from the App Store, which will also provide you with the necessary compiler.

#### On Windows:

We recommend installing [MinGW](https://winlibs.com/#download-release).
Download the latest version and appropiate architecture (x86_64 for 64-bit and i686 for 32-bit).
Extract it on your C: drive. It will create a folder called `mingw64` or `mingw32` depending on the architecture you chose.
Then Put the path to the bin directory in your system's PATH. For example, if you installed MinGW in `C:\mingw64`, you would add `C:\mingw64\bin` to your system's PATH.
    1. Open the Control Panel (Start > Control Panel) and Edit the system environment variables.
    2. Click on Environment Variables.
    3. Under System Variables, select Path, then click Edit.
    4. Add the path of your MinGW bin directory to the list. For example, `C:\mingw64\bin`.

To verify installation, open a new terminal and type:
    
    ```bash
    g++ --version
    ```

### 2. Installing Visual Studio Code (VSCode) or Clion

#### VSCode

Visual Studio Code is a lightweight and powerful code editor. It's available for Linux, macOS, and Windows.

[Download VSCode](https://code.visualstudio.com/)

After installation, you can enhance your C++ development experience with the [C++ extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) for VSCode.

#### Clion (optional)

CLion is a cross-platform C/C++ IDE that works on Linux, macOS, and Windows.

[Download CLion](https://www.jetbrains.com/clion/)
for this you need to have a student account, you can get one [here](https://www.jetbrains.com/community/education/#students)

### 3. Configuring Visual Studio Code for C++

After installing Visual Studio Code and the C++ extension, you might want to configure it to make the most out of your C++ coding experience.

#### 1. Install the C++ Extension

If you haven't already, you need to install the C++ extension for VSCode:

- Launch VSCode.
- Go to Extensions (you can use the `Ctrl+Shift+X` shortcut, macos `CMD+Shift+X`).
- Search for `C++` and install the one by Microsoft.

This extension provides debugging, IntelliSense, and code navigation features for C++.


##### for more information on how to configure VSCode for C++ you can check out this [link](https://code.visualstudio.com/docs/languages/cpp)

---

This setup should give you a smooth experience when writing and debugging C++ in VSCode. Remember, there are many extensions and settings in VSCode, so feel free to explore and customize your environment further!
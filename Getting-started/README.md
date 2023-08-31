

# Getting Started with C++ (Introduction)

## C++ Central Asian University Course

Welcome to the C++ course repository. Each directory in this repository represents a lesson, starting from "Getting-started" and ending with "Lesson14". Each lesson has a `src` directory that contains the source code for that particular lesson.

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


### 3. Cloning the Repository

To clone this repository to your local machine, use the following command:

```bash
git clone [repository_url]
```

Replace `[repository_url]` with the actual URL of this repository.

### 4. Running the Code

To compile and run a C++ program, navigate to the `src` directory of the desired lesson. For instance:

```bash
cd Getting Started/src
```

Compile the code with:

```bash
g++ filename.cpp -o outputname
```

Replace `filename.cpp` with the name of the C++ file and `outputname` with whatever you wish to name the executable. Then, run the program with:

```bash
./outputname
```

## Lessons Overview

Each lesson has its own directory, and inside each directory is a `src` folder with the source code and a `README.md` file. The `README.md` will provide a title, a short description of the lesson, and instructions on how to run the specific code for that lesson.

---

Students can now navigate to individual lesson directories for further details and examples. For each lesson's README.md, you might want to provide the title, objectives, and any special compilation or runtime instructions. 

Good luck with your course!
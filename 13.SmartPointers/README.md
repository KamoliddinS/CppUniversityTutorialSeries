# C++ Smart Pointer Overview

Welcome to the comprehensive guide and source code repository for learning about C++ smart pointers. This repository contains detailed documentation and source code examples that explain various aspects of smart pointers in C++, from basic concepts to more advanced topics.

## Repository Structure

The repository is organized into two main directories:

- `docs`: Contains the detailed markdown files explaining different smart pointer concepts.
- `src`: Houses the accompanying C++ source code examples that illustrate the concepts explained in the `docs`.

Here's a quick overview of what you can find in each directory:

### `docs` Directory

Each topic about smart pointers is covered in its own markdown file within the `docs` directory. The topics include:

- `Raw_Pointers_Issues.md`: Discusses the issues and pitfalls of using raw pointers in C++ and the motivation behind smart pointers.
- `Smart_Pointers_Introduction.md`: Provides an introduction to smart pointers, explaining their purpose and importance.
- `Unique_Pointers.md`: Goes into detail about `std::unique_ptr`, how to use it, and its advantages over raw pointers.
- `Shared_Pointers.md`: Explains `std::shared_ptr`, its use cases, and the internals of reference counting.
- `Weak_Pointers.md`: Describes `std::weak_ptr`, when to use it, and how it complements `std::shared_ptr`.
- `Custom_Deleters.md`: Discusses how to provide custom deleter functions to smart pointers for resource management beyond memory deallocation.

Each document is structured to provide a clear and detailed explanation of each concept, with examples and best practices.

### `src` Directory

Corresponding to each markdown file in the `docs` directory, the `src` directory contains C++ source files that provide hands-on examples:

- `RawPointersIssuesExample.cpp`: Demonstrates the problems that can arise when using raw pointers.
- `SmartPointersIntroductionExample.cpp`: Contains introductory examples showcasing the basic usage of smart pointers.
- `UniquePointersExample.cpp`: Provides examples on how to work with `std::unique_ptr`.
- `SharedPointersExample.cpp`: Includes examples that use `std::shared_ptr` and illustrates reference counting behavior.
- `WeakPointersExample.cpp`: Contains examples on the usage of `std::weak_ptr` to avoid memory leaks and dangling pointers.
- `CustomDeletersExample.cpp`: Shows how to implement and use custom deleters with both `std::unique_ptr` and `std::shared_ptr`.

## How to Use This Repository

To make the most of this repository:

1. Start by reading the documentation in the `docs` directory. Each markdown file is meant to be read in sequence to build up your understanding of smart pointers in C++.
2. After reading each markdown file, navigate to the corresponding source code in the `src` directory. Compile and run the examples to see smart pointers in action.
3. Experiment with the source code. Modify the examples, recompile, and run to observe the changes. This hands-on experience will reinforce your understanding.

## Compiling the Examples

To compile the source code examples, you will need a C++ compiler that supports C++11 or later. You can compile each example using the following command:

```bash
g++ -std=c++17 -o output_filename src/ExampleFileName.cpp
```
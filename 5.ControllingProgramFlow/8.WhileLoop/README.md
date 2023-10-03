
# While Loops in C++

## Introduction
A "while" loop is one of the fundamental control flow structures in C++. It allows you to repeatedly execute a block of code as long as a specified condition is true. While loops are valuable for tasks that require repetitive execution until a particular condition is met.

## Syntax
The syntax of a "while" loop in C++ is as follows:

```cpp
while (condition) {
    // Code to be executed repeatedly as long as the condition is true
}
```

- `condition` represents the Boolean expression that is evaluated before each iteration of the loop. If the condition is true, the loop's body is executed.

## Example
Here's a simple example of a "while" loop that counts from 1 to 5:

```cpp
#include <iostream>

int main() {
    int count = 1;
    while (count <= 5) {
        std::cout << count << " ";
        count++;
    }
    return 0;
}
```

In this example, the loop continues executing as long as the condition `count <= 5` is true. It prints the value of `count` and increments it in each iteration.

## Key Points
- The condition in a "while" loop is evaluated before entering the loop body. If the condition is initially false, the loop body is never executed.
- It's essential to include code within the loop body that eventually changes the condition to false. Otherwise, you may create an infinite loop.
- "While" loops are suitable when the number of iterations is unknown in advance and depends on runtime conditions.

## Infinite Loops
Be cautious when using "while" loops, as they can lead to infinite loops if the condition is never false. To prevent this, ensure that the condition can become false at some point during execution. Commonly, you'll use variables or user input to change the condition.

## Conclusion
"While" loops are a powerful tool in C++ for repetitive tasks that depend on a condition. They offer flexibility in handling situations where the number of iterations is uncertain. Understanding how to use "while" loops effectively is crucial for efficient program flow control.

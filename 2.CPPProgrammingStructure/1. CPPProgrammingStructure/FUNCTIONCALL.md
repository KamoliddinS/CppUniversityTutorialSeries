
# Function Calls in C++: Expressions vs. Statements

In the world of C++ programming, function calls can wear two different hats – they can be both expressions and statements. But what does this mean, and how can the same function serve two roles? Let's dive in.

## 🎭 When is a Function Call an Expression?

An expression is something that gives us a value. When a function returns a value, its call can be used as part of a larger computation or assigned to a variable.

```cpp
int add(int a, int b) {
    return a + b;
}

int sum = add(3, 4);  // Here, add(3, 4) is an expression that evaluates to 7.
```

In this case, `add(3, 4)` gives us the value `7`, so it's an expression.

## 🎭 When is a Function Call a Statement?

Statements are like commands. They tell the computer to do something, but they don't necessarily give us back a value. If you're calling a function just for its side effects (maybe it prints something or modifies a global variable) and you're not using its returned value, then it's a statement.

```cpp
void display() {
    std::cout << "Hello!";
}

display();  // Here, display() is a statement.
```

In this scenario, the `display()` function call doesn't give us a value; it just prints "Hello!" on the screen. So, it's a statement.

## 🤔 Conclusion

In C++, a function call can be both an expression and a statement, depending on how it's used. If we care about the value it returns, it's an expression. If we just want it to do something without using its return value, it's a statement.

Remember, C++ is versatile, and how we use functions can determine their role in our code!

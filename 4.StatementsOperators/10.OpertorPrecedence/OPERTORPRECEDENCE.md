# Operator Precedence in C++

Operator precedence determines the order in which operators are evaluated in expressions. In C++, operators with higher precedence are evaluated before operators with lower precedence.

## Table of Operator Precedence

| Precedence | Operator | Description |
|------------|----------|-------------|
| 1 | `::` | Scope resolution |
| 2 | `a++`, `a--` | Postfix increment and decrement |
| 3 | `++a`, `--a` | Prefix increment and decrement |
| 4 | `+`, `-`, `!`, `~` | Unary plus, unary minus, logical NOT, bitwise NOT |
| 5 | `*`, `/`, `%` | Multiplication, division, modulus |
| 6 | `+`, `-` | Addition, subtraction |
| 7 | `<<`, `>>` | Bitwise left shift, bitwise right shift |
| 8 | `<`, `<=`, `>`, `>=` | Relational operators |
| 9 | `==`, `!=` | Equality and inequality |
| 10 | `&` | Bitwise AND |
| 11 | `^` | Bitwise XOR |
| 12 | `|` | Bitwise OR |
| 13 | `&&` | Logical AND |
| 14 | `||` | Logical OR |
| 15 | `=`, `+=`, `-=`, `*=`, `/=`, `%=`, `<<=`, `>>=`, `&=`, `^=`, `|=` | Assignment operators |
| 16 | `,` | Comma operator |

## Examples

1. **Scope resolution**:
   ```cpp
   namespace MyNamespace {
       int x = 10;
   }
   int main() {
       int x = MyNamespace::x;  // Uses the scope resolution operator
   }
   ```

2. **Postfix vs Prefix**:
   ```cpp
   int a = 5;
   int b = a++;  // b = 5, a = 6
   int c = ++a;  // c = 7, a = 7
   ```

3. **Multiplication before Addition**:
   ```cpp
   int result = 3 + 4 * 2;  // result = 11, not 14
   ```

4. **Logical AND before Logical OR**:
   ```cpp
   bool result = true || false && false;  // result = true, because && has higher precedence than ||
   ```

5. **Using Parentheses to Override Precedence**:
   ```cpp
   int result = (3 + 4) * 2;  // result = 14, parentheses override the default precedence
   ```

Remember, when in doubt, it's always a good practice to use parentheses to make the order of operations explicit.

## Further Reading
- [cppreference - Operator Precedence](https://en.cppreference.com/w/cpp/language/operator_precedence)
# SOLID principles

> **Goal:** name the five SOLID principles and find code that breaks one of them.

**SOLID** is a set of five design principles for classes that stay easy to change. Each
letter stands for one of them. Below, every principle has two programs: `_bad` works, but
its design makes the next change hard, and `_good` does the same job without that problem.

## S · Single responsibility

A class has one job, so only one kind of change makes you edit it.

**`srp_bad.cpp`**
<!-- file: srp_bad.cpp -->
```cpp
#include <iostream>
#include <vector>

// Breaks single responsibility: Bill has two jobs. It adds up the prices AND it
// decides how a bill looks. A new price rule and a new layout both mean editing it.
class Bill {
public:
    void add(int price) { prices_.push_back(price); }

    void print() const {
        int total = 0;
        for (int price : prices_) {
            std::cout << price << " so'm\n";
            total += price;
        }
        std::cout << "Total: " << total << " so'm\n";
    }

private:
    std::vector<int> prices_;
};

int main() {
    Bill bill;
    bill.add(45000);
    bill.add(8000);
    bill.print();
}
```

<!-- output: srp_bad -->
```text
45000 so'm
8000 so'm
Total: 53000 so'm
```

**`srp_good.cpp`**
<!-- file: srp_good.cpp -->
```cpp
#include <iostream>
#include <vector>

// Job 1: keep the prices and add them up.
class Bill {
public:
    void add(int price) { prices_.push_back(price); }
    const std::vector<int>& prices() const { return prices_; }

    int total() const {
        int sum = 0;
        for (int price : prices_) {
            sum += price;
        }
        return sum;
    }

private:
    std::vector<int> prices_;
};

// Job 2: decide how a bill looks on the screen.
void print(const Bill& bill) {
    for (int price : bill.prices()) {
        std::cout << price << " so'm\n";
    }
    std::cout << "Total: " << bill.total() << " so'm\n";
}

int main() {
    Bill bill;
    bill.add(45000);
    bill.add(8000);
    print(bill);
}
```

<!-- output: srp_good -->
```text
45000 so'm
8000 so'm
Total: 53000 so'm
```

- Now other code can ask for `total()` without printing anything.
- A second layout is a second function. `Bill` stays as it is.

## O · Open/closed

You add new behaviour by writing new code, not by editing code that already works.

**`ocp_bad.cpp`**
<!-- file: ocp_bad.cpp -->
```cpp
#include <iostream>

enum class Discount { none, student };

// Breaks open/closed: every new discount means editing this function,
// although it already works.
void printPrice(Discount discount, int price) {
    int toPay = price;
    if (discount == Discount::student) {
        toPay = price / 2;
    }
    std::cout << toPay << " so'm\n";
}

int main() {
    printPrice(Discount::none, 3000);
    printPrice(Discount::student, 3000);
}
```

<!-- output: ocp_bad -->
```text
3000 so'm
1500 so'm
```

**`ocp_good.cpp`**
<!-- file: ocp_good.cpp -->
```cpp
#include <iostream>

class Discount {
public:
    virtual ~Discount() = default;
    virtual int apply(int price) const = 0;
};

class NoDiscount : public Discount {
public:
    int apply(int price) const override { return price; }
};

class StudentDiscount : public Discount {
public:
    int apply(int price) const override { return price / 2; }
};

// This function is finished. A new discount is a new class; nothing here changes.
void printPrice(const Discount& discount, int price) {
    std::cout << discount.apply(price) << " so'm\n";
}

int main() {
    NoDiscount none;
    StudentDiscount student;
    printPrice(none, 3000);
    printPrice(student, 3000);
}
```

<!-- output: ocp_good -->
```text
3000 so'm
1500 so'm
```

A third discount in the bad version means a new `if` in `printPrice`, and in every other
function that asks which discount it is. In the good version it means one new class.

## L · Liskov substitution

Where a base class is expected, an object of any derived class must work too, without
surprises.

**`lsp_bad.cpp`**
<!-- file: lsp_bad.cpp -->
```cpp
#include <iostream>

class Account {
public:
    virtual ~Account() = default;
    // Promise: after withdraw(amount) the balance is smaller by amount.
    virtual void withdraw(int amount) { balance_ -= amount; }
    void deposit(int amount) { balance_ += amount; }
    int balance() const { return balance_; }

private:
    int balance_ = 100000;
};

// Breaks Liskov substitution: LockedAccount does not keep the promise of
// Account::withdraw. Code that is correct for an Account now goes wrong.
class LockedAccount : public Account {
public:
    void withdraw(int) override {}   // locked: the amount is ignored, nothing happens
};

void transfer(Account& from, Account& to, int amount) {
    from.withdraw(amount);
    to.deposit(amount);
}

int main() {
    LockedAccount savings;
    Account card;
    transfer(savings, card, 30000);
    std::cout << "Savings: " << savings.balance() << ", card: " << card.balance() << '\n';
}
```

<!-- output: lsp_bad -->
```text
Savings: 100000, card: 130000
```

The two accounts had 200000 so'm together. Now they have 230000: `transfer` trusted the
promise, and `LockedAccount` broke it.

**`lsp_good.cpp`**
<!-- file: lsp_good.cpp -->
```cpp
#include <iostream>

class Account {
public:
    virtual ~Account() = default;
    // Promise: true means the money was taken out, false means nothing changed.
    virtual bool withdraw(int amount) {
        balance_ -= amount;
        return true;
    }
    void deposit(int amount) { balance_ += amount; }
    int balance() const { return balance_; }

private:
    int balance_ = 100000;
};

// LockedAccount keeps the promise: "false, nothing changed" is an allowed answer.
class LockedAccount : public Account {
public:
    bool withdraw(int) override { return false; }
};

void transfer(Account& from, Account& to, int amount) {
    if (from.withdraw(amount)) {
        to.deposit(amount);
    }
}

int main() {
    LockedAccount savings;
    Account card;
    transfer(savings, card, 30000);
    std::cout << "Savings: " << savings.balance() << ", card: " << card.balance() << '\n';
}
```

<!-- output: lsp_good -->
```text
Savings: 100000, card: 100000
```

The base class now promises only what every derived class can keep.

## I · Interface segregation

No class should have to offer a function it cannot do: several small
[interfaces](../../12-polymorphism/04-abstract-classes/README.md#interfaces) are better
than one big one.

**`isp_bad.cpp`**
<!-- file: isp_bad.cpp -->
```cpp
#include <iostream>

// Breaks interface segregation: one big interface. Every device must have
// print() AND scan(), even a device that cannot scan.
class Device {
public:
    virtual ~Device() = default;
    virtual void print() const = 0;
    virtual void scan() const = 0;
};

class Copier : public Device {
public:
    void print() const override { std::cout << "Copier prints\n"; }
    void scan() const override { std::cout << "Copier scans\n"; }
};

class SimplePrinter : public Device {
public:
    void print() const override { std::cout << "Printer prints\n"; }
    void scan() const override {}   // forced to exist: does nothing
};

void scanPage(const Device& device) {
    device.scan();
}

int main() {
    Copier copier;
    SimplePrinter printer;
    printer.print();
    scanPage(copier);
    scanPage(printer);   // builds and runs, but nothing is scanned
}
```

<!-- output: isp_bad -->
```text
Printer prints
Copier scans
```

**`isp_good.cpp`**
<!-- file: isp_good.cpp -->
```cpp
#include <iostream>

class Printer {
public:
    virtual ~Printer() = default;
    virtual void print() const = 0;
};

class Scanner {
public:
    virtual ~Scanner() = default;
    virtual void scan() const = 0;
};

class Copier : public Printer, public Scanner {
public:
    void print() const override { std::cout << "Copier prints\n"; }
    void scan() const override { std::cout << "Copier scans\n"; }
};

class SimplePrinter : public Printer {
public:
    void print() const override { std::cout << "Printer prints\n"; }
};

void scanPage(const Scanner& device) {
    device.scan();
}

int main() {
    Copier copier;
    SimplePrinter printer;
    printer.print();
    scanPage(copier);
}
```

<!-- output: isp_good -->
```text
Printer prints
Copier scans
```

`scanPage` now asks for exactly what it needs: a `Scanner`. And `scanPage(printer)` no
longer compiles, so the mistake is found before the program runs.

## D · Dependency inversion

A class depends on an abstract class, not on one concrete class; the concrete object is
passed in from outside.

```text
bad:     Order ──► SmsSender                      ──► means "depends on"
good:    Order ──► Sender ◄── SmsSender
```

**`dip_bad.cpp`**
<!-- file: dip_bad.cpp -->
```cpp
#include <iostream>
#include <string>

class SmsSender {
public:
    void send(const std::string& text) const {
        std::cout << "SMS: " << text << '\n';
    }
};

// Breaks dependency inversion: Order can only work with SmsSender. To send an
// e-mail instead, or to test Order without sending anything, you must edit Order.
class Order {
public:
    void finish() const { sender_.send("Your order is ready"); }

private:
    SmsSender sender_;
};

int main() {
    Order order;
    order.finish();
}
```

<!-- output: dip_bad -->
```text
SMS: Your order is ready
```

**`dip_good.cpp`**
<!-- file: dip_good.cpp -->
```cpp
#include <iostream>
#include <memory>
#include <string>
#include <utility>

class Sender {
public:
    virtual ~Sender() = default;
    virtual void send(const std::string& text) const = 0;
};

class SmsSender : public Sender {
public:
    void send(const std::string& text) const override {
        std::cout << "SMS: " << text << '\n';
    }
};

// Order knows only the abstract Sender.
// The code that creates an Order chooses the real one.
class Order {
public:
    explicit Order(std::unique_ptr<Sender> sender) : sender_(std::move(sender)) {}
    void finish() const { sender_->send("Your order is ready"); }

private:
    std::unique_ptr<Sender> sender_;
};

int main() {
    Order order(std::make_unique<SmsSender>());
    order.finish();
}
```

<!-- output: dip_good -->
```text
SMS: Your order is ready
```

`Order` no longer names `SmsSender`. An `EmailSender` is one new class and one changed
line in `main`.

## Watch out

- The principles are advice, not laws. For a program of 30 lines the `_bad` versions are
  fine. Use a principle when its problem appears: the second discount, the second sender.
- Every `_good` version is longer. Extra classes cost reading time, so add one only when
  it removes a real problem.

## Try it

1. Pensioners pay nothing. Add this discount to `ocp_bad.cpp` and to `ocp_good.cpp`.
   In which file did you edit code that already worked?
2. Which principle does this class break?

   ```cpp
   class Student {
   public:
       double average() const;
       void saveToFile(const std::string& path) const;
       void printAsTable() const;
   };
   ```

<details>
<summary>Answers</summary>

1. In `ocp_bad.cpp`: the `enum` and `printPrice` both change. In `ocp_good.cpp` you only
   add a class and use it in `main`.
2. Single responsibility. Calculating, saving and printing are three jobs, so three kinds
   of change touch this class.
</details>

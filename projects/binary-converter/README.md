# Binary converter

A small program that converts whole numbers between decimal and binary, and adds binary
numbers. It has one step and does not need the gradebook.

| Step | Do it after | What you build |
|------|-------------|----------------|
| 1 · [Convert and add](01-convert-and-add/README.md) | [05 · Vectors and strings](../../05-vectors-and-strings/README.md) | the commands `to-binary`, `to-decimal` and `add` |

The appendix page [Number systems and bits](../../appendix/number-systems-and-bits/README.md)
explains binary numbers. Read it first.

Like the [gradebook](../gradebook/README.md), the program reads commands, one per line,
and prints only results. Check it from the top folder of the course:

```sh
cmake -B build
ctest --test-dir build -R ex-binary-converter-01 --output-on-failure
```

Run the first command once. The second one runs every test case.

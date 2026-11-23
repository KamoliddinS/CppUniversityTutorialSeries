# 06 · Structs and files

After this chapter you can group related data, save it to a file and load it again.

| # | Lesson | You learn to |
|---|--------|--------------|
| 1 | [Structs](01-structs/README.md) | group the values that describe one thing into a type of your own |
| 2 | [Enums](02-enums/README.md) | give names to a fixed set of choices |
| 3 | [Write and read files](03-write-and-read-files/README.md) | save text in a file, read it back, and notice a file that is missing |
| 4 | [Parse lines](04-parse-lines/README.md) | split a line of text into its parts and turn them into numbers |
| 5 | [Format output](05-format-output/README.md) | print aligned tables and numbers with a fixed number of decimals |
| 6 | [Program arguments](06-program-arguments/README.md) | receive values from the command line and report failure with an exit code |

**Practice:** [Exercises](exercises/README.md)

## Key terms

| Term | Meaning |
|------|---------|
| struct | a type you define that groups several values under one name |
| member | one of the values inside a struct; you reach it with a dot, as in `student.age` |
| enum | a type whose only values are the names you list, such as `Level::beginner` |
| file stream | a variable connected to a file; you read from it with `>>` and write to it with `<<` |
| string stream | like a file stream, but it reads from a string instead of a file |
| parse | split text into its parts and convert each part to the right type |
| manipulator | something you send to `std::cout` or a file stream to change how the next values are printed, such as `std::setw(10)` |
| command-line argument | a word typed after the program's name when the program is started |
| exit code | the number `main` returns to the system; 0 means success |

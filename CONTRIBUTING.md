# How this course is written

These are the rules every lesson, example and exercise follows. A script checks most of
them, so you find out quickly when something is off:

```sh
python3 tools/check.py
python3 tools/check.py 03-control-flow
python3 tools/check.py --fix 03-control-flow
```

The first line checks the whole course, the second one chapter. `--fix` refreshes the code
and output blocks in the pages.

It needs Python 3.9+, `g++` 13 or newer, and Linux or macOS (the dev container works).

## 1. The reader

A first-year student who has never programmed and who reads English as a second language.
The reader should understand a lesson in **five minutes**, with the code open next to it.

## 2. A lesson

One lesson teaches **one idea**. It is a folder with a `README.md` and the example files:

```text
03-control-flow/
    README.md                 chapter page: lesson table, key terms
    05-for-loops/
        README.md             the lesson
        count_up.cpp          one small program per file
        count_up.in           (optional) what the user types when it runs
    exercises/
        README.md             all tasks of the chapter
        01-some-task/         one folder per task
```

The page has these parts, in this order. Leave a part out only when it truly has nothing to say.

````markdown
# Title

> **Goal:** one sentence that starts with a verb: what the student can do afterwards.

## (a heading that names the idea)
Start from a problem or a question. Two to five short sentences, a small table, or a picture
made of text. Show the failing or awkward case first when there is one.

<!-- file: example.cpp -->
```cpp
```

<!-- output: example -->
```text
```

Two to four bullets: what to notice in the example.

## Watch out
One to three mistakes beginners really make: the wrong line, what happens, the fix.

## Try it
One or two small tasks: predict the output, change the example, fix a bug.
Put answers inside <details><summary>Answer</summary> ... </details>.

**Next:** [Title of the next lesson](../06-next-lesson/README.md)
````

Limits the checker enforces for a lesson page:

- at most **400 words** of text (code blocks do not count); aim for 250;
- the `> **Goal:**` line, a `## Try it` section, and the `**Next:**` line;
- no heading called Conclusion, Introduction or Overview.

## 3. Writing

- Short sentences. One idea per sentence. Present tense. Say "you".
- Use the plain word: "use", not "utilize"; "shows", not "demonstrates".
- No filler ("it is important to note", "powerful", "crucial"), no welcome or goodbye lines,
  no summary that repeats the lesson.
- Introduce a term once, in **bold**, with its meaning in the same sentence. Then add it to
  the chapter's "Key terms" table.
- No idioms and no jokes that need cultural background.
- Prefer a table or a numbered list to a paragraph. Prefer an example to an explanation.
- No emoji and no decorative symbols. Arrows (`→`) and box-drawing characters in diagrams are fine.
- Never put a `# comment` after a command in a `sh` block. The default shell on macOS does not
  ignore it when the line is pasted. Explain the command in the text.
- Say what really happens. If the language does not define a result, write
  "undefined behaviour: anything may happen", not "this will crash".
- Do not use a feature before the lesson that teaches it. If you must, add one sentence and
  a link to that lesson.

## 4. Pictures

Use text, so pictures work everywhere and are easy to edit.

Memory is always drawn as a table with these columns:

| Name | Address | Value |
|------|---------|-------|
| `count` | `0x1000` | `42` |
| `p` | `0x1008` | `0x1000` (points to `count`) |

Class relations and program flow are drawn with box characters inside a `text` block.

## 5. Code

- C++20, built with `g++ -std=c++20 -Wall -Wextra`. Every example must build **without
  warnings** and run cleanly under the sanitizers.
- A program is short: aim for 25 lines, never more than 45. One idea per file.
- Always write `std::`. Never `using namespace std;`.
- End lines with `'\n'`, not `std::endl`.
- Four spaces, opening brace on the same line.
- Names: `camelCase` for variables and functions, `PascalCase` for types, a trailing
  underscore for private data members (`balance_`). Constants are `const` or `constexpr`
  variables in `camelCase`; ALL_CAPS is for macros only, and the course avoids macros.
- Give every variable a starting value: `int total = 0;`.
- Index a container with `std::size_t`; prefer a range-based `for` when you do not need the index.
- No raw `new` and `delete` outside the lessons that teach them.
- Programs that read input must stop cleanly when the input ends. Never loop forever on bad input.
- `main` has no `return 0;` unless the lesson is about exit codes.
- Comments explain *why*, or mark the line the lesson is about. Do not narrate the code.
- Use names and data the students know: Aziz, Malika, Dilnoza, Jasur, Laziz, Nodira;
  Tashkent, Samarkand, Bukhara, Khiva; prices in so'm.

### File names tell the checker what to expect

| File | Meaning | The checker makes sure that |
|------|---------|-----------------------------|
| `name.cpp` | a correct program | it builds without warnings, runs, and exits with 0 |
| `name_bug.cpp` | builds, but has a bug on purpose | it builds |
| `name_nocompile.cpp` | does not build, on purpose | the build fails |
| `name.in` | what the user types | the program reads every line |
| `name.args` | command-line arguments | |
| `name.exitcode` | expected exit code if not 0 | |
| `folder/*.cpp` | one program made of several files | as for `name.cpp` |
| `*.txt`, `*.csv` | data the programs read | (copied next to the program when it runs) |

Names use lowercase letters, digits, `_` and `-` only. Folders are numbered `NN-like-this`.

## 6. Code and output in a page come from the files

Never type code or output into a page by hand. Put a marker above an empty block and run
`python3 tools/check.py --fix`. The checker fills the block and later fails if it goes stale.

| Marker | The block shows |
|--------|-----------------|
| `<!-- file: name.cpp -->` | the whole file |
| `<!-- snippet: name.cpp -->` | a few lines you typed; each must exist in the file |
| `<!-- output: name -->` | what the program prints |
| `<!-- session: name -->` | a run as seen in a terminal, with the lines of `name.in` typed in |
| `<!-- errors: name_nocompile -->` | the compiler's or linker's messages (also for `_bug` files that warn) |
| `<!-- no-output: name -->` | nothing: says on purpose that this program's output is not shown |

- `--fix` also puts a caption such as **`hello.cpp`** above every `file` block, because
  readers cannot see the markers. Do not type the file name above the block yourself.
- Every correct program must have an `output` or `session` block (or `no-output`).
- An `errors` block is filled once. To refresh it, empty the block and run `--fix` again.
- A code block without a marker is a **sketch**: at most 8 lines, never a full program.
  Use it for the general form of a statement, not for examples.
- Memory addresses differ from run to run; the checker ignores them when it compares output.

## 7. Exercises

Each chapter has about five tasks, from easy to hard. Mix the kinds:

| Kind | The student | Files in the task folder |
|------|-------------|--------------------------|
| predict | writes down what a program prints | `program.cpp`, `prediction.txt` |
| fix | repairs a program that does not build, crashes, or gives a wrong answer | `exercise.cpp`, `tests/` |
| complete | fills in the `// TODO` parts | `exercise.cpp`, `tests/` |
| write | writes the program from a description | `exercise.cpp`, `tests/` |

- A test case is `tests/1.out` (the exact expected output) plus an optional `tests/1.in`
  (what is typed). Give at least two cases when the program reads input.
- A task may check itself instead: no `tests/` folder, and `main` returns a non-zero value
  when a check fails. Use this for tasks about writing a function.
- The starter must build, and must **not** pass. If the starter does not build on purpose,
  its first comment says "This file does not compile yet."
- Programs in tasks print no questions, only results, so the output can be compared exactly.
- The chapter's `exercises/README.md` describes every task: what to do, one example of
  input and output, and a hint inside `<details>`.
- The task's check name is `ex-<chapter>-<task>`, for example `ex-03-02`.
- The last lesson of a chapter links to the exercises page. The exercises page ends with
  `**Next chapter:** [NN · Title](../../NN-next-chapter/README.md)`.

Solutions are **not** in this repository. They live in `solutions/`, which mirrors the task
folders (`solutions/03-control-flow/exercises/02-some-task/solution.cpp`) and is kept in a
separate private repository. When that folder is present, the checker builds every solution
and runs it against the tests.

## 8. The chapter page

- One or two sentences: what the student can do after the chapter.
- A table of the lessons with a link and a "you learn to" column.
- A link to the exercises.
- `## Key terms`: a table with the columns Term and Meaning. `GLOSSARY.md` is built from
  these tables by `python3 tools/check.py --fix`.

## 9. Before you commit

1. `python3 tools/check.py` prints `OK`.
2. Read the page once more as a beginner would. Cut every sentence that does not help.

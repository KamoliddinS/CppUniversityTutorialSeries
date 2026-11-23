# Open-source licences

> **Goal:** read the name of a licence and say what you may do with the code.

This page is general information, not legal advice.

## No licence means no permission

The author of code or text holds its **copyright** automatically: only the author decides
who may copy, change and share it. This also holds for code that everyone can see on
GitHub: you may read it, but not copy it into your project.

A **licence** is a text in which the author gives everyone that permission and states the
conditions. Code with such a licence is **open source**. Look for the file `LICENSE`
in the top folder of a project.

## Five common licences

| Licence | You may | You must |
|---------|---------|----------|
| MIT | use, change, share and sell the code | keep the copyright line and the licence text |
| Apache-2.0 | the same, and use the authors' patents on the code | the same, mark the files you changed, and keep the `NOTICE` file if there is one |
| GPL-3.0 | use, change, share and sell the code | when you share your program, pass on its full source code, under GPL-3.0 too |
| CC BY 4.0 | copy, change, share and sell the work | name the author, link to the licence, say what you changed |
| CC0 1.0 | do anything: the author gave up the copyright, as far as the law allows | nothing |

- GPL-3.0 is a **copyleft** licence: what you build with the code may only be shared
  under the same licence. The compiler `g++` is under GPL-3.0.
- CC means Creative Commons. Its licences are made for text, pictures and data: CC BY is
  not meant for code, but CC0 is used for code too.
- All five give no warranty: the author is not responsible if the code fails.

## This course is CC0 1.0

The file [`LICENSE`](../../LICENSE) in the top folder of the course says so. For you it means:

- you may copy every lesson and every program, change it, publish it and even sell it;
- you need not ask anyone, and you need not name the source.

## Watch out

- A licence answers a legal question only. The rules of your university still apply: in
  an assignment, always say which parts you did not write yourself.
- Read the licence before you copy code. One GPL file puts the GPL condition on your
  whole program when you share it.

## Try it

1. A GitHub project has no `LICENSE` file. May you copy a function from it into your
   program?
2. `g++` is under GPL-3.0. Must the programs that you build with it be under GPL-3.0 too?

<details>
<summary>Answers</summary>

1. No. Without a licence the author keeps all rights. Write your own version, or ask the
   author.
2. No. The GPL covers the code of the compiler, not the programs it builds for you. The
   parts of library code that `g++` puts into your program come with an extra permission,
   the GCC Runtime Library Exception, so your program may have any licence.
</details>

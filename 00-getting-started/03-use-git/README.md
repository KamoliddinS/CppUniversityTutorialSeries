# Use Git

> **Goal:** download the course, save your own work, and send a fix to the course.

**Git** is a program that records versions of the files in a folder, so you can go back to
an earlier one. **GitHub** is a website where people store and share such folders, called
**repositories**.

## Once: tell Git who you are

```sh
git config --global user.name "Malika Karimova"
git config --global user.email "malika@example.com"
git config --global pull.rebase true
```

Type your own name and e-mail. Without them, your first commit usually fails with
`Please tell me who you are`. The third line makes `git pull` put your commits after the
new lessons.

## The commands you need

They work in any course folder. Name a file as `git status` shows it.

| You want to | Type |
|-------------|------|
| make a **clone**, your own copy of the course (done in lesson 1) | `git clone https://github.com/KamoliddinS/CppUniversityTutorialSeries.git` |
| get new lessons | `git pull` |
| see which files you changed | `git status` |
| choose what to save: one file, or all changes | `git add hello.cpp` or `git add -A` |
| save a **commit**: a version with a message, kept on your computer | `git commit -m "Solve exercise 3"` |
| throw away your changes to one file (**destructive**: cannot be undone) | `git restore hello.cpp` |

## Watch out

- Commit before you pull. Otherwise Git answers `cannot pull with rebase`.
- `CONFLICT` after `git pull` means you and the course changed the same lines.
  `git rebase --abort` takes you back to before the pull. Then ask your teacher.

## Check that it works: your first pull request

A **pull request** asks the owner of a repository to take your change.

1. Sign in to [GitHub](https://github.com) (it is free). Open the
   [course](https://github.com/KamoliddinS/CppUniversityTutorialSeries), press **Fork**, then
   **Create fork**. A **fork** is your own copy of a repository on GitHub.
2. Clone your fork into a folder named `my-fork`. Put your user name in the address.
   (In a codespace, follow [these steps](../01-install-the-tools/codespaces.md#your-first-pull-request-in-a-codespace) instead.)

   ```sh
   cd ~
   git clone https://github.com/YOUR-USERNAME/CppUniversityTutorialSeries.git my-fork
   ```

3. Open `my-fork` in VS Code. Fix or improve one sentence in any lesson, and save.
4. In the VS Code terminal, save the change and send it to your fork:

   ```sh
   git status
   git add -A
   git commit -m "Fix a typo in the terminal lesson"
   git push
   ```

   At the first `git push`, sign in to GitHub in the browser.
5. On your fork's page press **Contribute**, then **Open pull request** and
   **Create pull request**.

Your pull request must appear in
[this list](https://github.com/KamoliddinS/CppUniversityTutorialSeries/pulls).

Only found a problem? Choose **Problem in a lesson** on the
[new issue page](https://github.com/KamoliddinS/CppUniversityTutorialSeries/issues/new/choose).

GitHub's guides: [signing in for `git push`](https://docs.github.com/en/get-started/git-basics/caching-your-github-credentials-in-git),
[SSH instead of HTTPS](https://docs.github.com/en/authentication/connecting-to-github-with-ssh).

**Next:** [01 · First programs](../../01-first-programs/README.md)

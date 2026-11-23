# Use a ready machine

The course has a folder named `.devcontainer`. It describes a Linux machine that already
contains `g++`, the debugger, CMake, Git and the VS Code extension. There are two ways to start it.

## Way 1: GitHub Codespaces, in your browser

You install nothing. You need a free account on [github.com](https://github.com).

1. Sign in and open the [course page](https://github.com/KamoliddinS/CppUniversityTutorialSeries).
2. Press the green **Code** button, open the **Codespaces** tab and press
   **Create codespace on main**.
3. Wait a few minutes. VS Code opens in the browser with the course folder and a terminal.

| Good to know | |
|--------------|---|
| Free use | 120 core hours each month. That is 60 hours on the standard machine with 2 cores. |
| Not used for 30 minutes | the machine stops. Start it again from the same **Codespaces** tab. |
| Not used for 30 days | the machine is deleted, with all work that was not pushed to GitHub. |

Official guide: [Creating a codespace for a repository](https://docs.github.com/en/codespaces/developing-in-a-codespace/creating-a-codespace-for-a-repository).

## Way 2: a dev container on your own computer

1. Install [Docker Desktop](https://www.docker.com/products/docker-desktop/), Git and VS Code.
2. In VS Code choose **View → Extensions** and install **Dev Containers**.
3. Do steps 2 and 3 of [Install the tools](README.md#2-get-the-course): get the course and open it in VS Code.
4. Press **F1**, type `Dev Containers: Reopen in Container` and press Enter.

Official guide: [Developing inside a Container](https://code.visualstudio.com/docs/devcontainers/containers).

## Check

The course is already open and the C/C++ extension is installed, so go directly to
[Check that it works](README.md#check-that-it-works). Type the commands in the terminal of the
codespace or the container.

## Git in a codespace

When you type `git commit`, Codespaces asks whether to link the codespace to a fork (your own
copy of the course on GitHub). Answer `n`. Your commits then stay in the codespace, and
`git pull` brings new lessons as [Use Git](../03-use-git/README.md) describes.

If you answered `y`, or committed in the **Source Control** panel (it links without asking),
new lessons come with `git pull upstream main` instead.

Official guide: [Using source control in your codespace](https://docs.github.com/en/codespaces/developing-in-a-codespace/using-source-control-in-your-codespace).

## Your first pull request in a codespace

Do step 1 of [your first pull request](../03-use-git/README.md#check-that-it-works-your-first-pull-request).
Then open your fork's page on GitHub and create a second codespace there, as in Way 1.
That codespace replaces the folder `my-fork`: do steps 3 to 5 in it.

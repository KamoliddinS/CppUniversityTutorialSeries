# Git Installation and Basic Commands
for more information, visit [here](ABOUT_GIT_GITHUB.md).

**Note**: This guide is designed for non-native English speakers. We'll keep it simple and straightforward. 

## Step 1: Install Git

### Mac:
1. Open **Terminal**.
2. Install Git using Homebrew: 
```
$ brew install git
```
If you don't have Homebrew installed, visit their [official website](https://brew.sh/) for installation instructions.

### Linux:
1. Open **Terminal**.
2. Use the package manager specific to your distribution. For example:

- **Debian/Ubuntu**:
```
$ sudo apt-get update
$ sudo apt-get install git
```

- **Fedora**:
```
$ sudo dnf install git
```

### Windows:
1. Visit the [Git for Windows download page](https://git-scm.com/download/win).
2. Download and run the installer, following on-screen instructions.

## Step 2: Create a GitHub Account

1. Visit [GitHub](https://github.com/).
2. Click on "Sign up".
3. Follow the on-screen instructions to create your account.

## Step 3: Authenticate with GitHub using SSH Key [For more information, click here](https://docs.github.com/en/authentication)

1. Open **Terminal** (or **Git Bash** on Windows).
2. Generate a new SSH key:
```
$ ssh-keygen -t rsa -b ed25519 -C "your_email@example.com"
```
(Replace `your_email@example.com` with your GitHub email address.)

3. Press `Enter` to save the key in the default location.
4. Start the ssh-agent in the background:
```
$ eval "$(ssh-agent -s)"
```
5. Add your SSH key to the ssh-agent:
```
$ ssh-add ~/.ssh/id_rsa
```
6. Install xclip (Linux only):
```
$ sudo apt-get install xclip
```
Copy the SSH key to your clipboard:
- **Mac**:
```
$ pbcopy < ~/.ssh/id_ed25519.pub
```
- **Linux**:
```
$ xclip -sel clip < ~/.ssh/id_ed25519.pub
```
- **Windows**: Manually open the file using a text editor, then copy the contents.

7. Go to GitHub -> Settings -> SSH and GPG keys -> New SSH key. Paste your key and save.

## Step 4: Basic Git Commands

1. **Clone a Repository**:
```
$ git clone [URL]
```
Replace `[URL]` with the link to the GitHub repository.

2. **Make Changes and Commit**:

- Check the status of your changes:
```
$ git status
```
- Add changes to be committed:
```
$ git add .
```
- Commit the changes:
```
$ git commit -m "Your message here"
```
3. **List Commits**:

-- List all commits:
```
$ git log
```
-- List the last 5 commits in one line:
```
$ git log --oneline -5
```
3. **Go Back to Previous Changes**:

- To undo the last commit:
```
$ git reset HEAD^
```
- To go back to a specific commit:
```
$ git reset [COMMIT_ID]
```
Replace `[COMMIT_ID]` with the commit ID.

- To bring back the changes:
```
$ git reset --hard
```


4. **Push Changes to Repository**:
```
$ git push origin main
```
Replace `main` with the branch name if you're not on the master branch.

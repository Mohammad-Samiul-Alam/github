# Windows Credential Manager — Git & GitHub Guide

## Contents

1. [Windows Credential Manager](#1-windows-credential-manager)
2. [Check Git Email](#2-check-git-email)
3. [Change Git Email](#3-change-git-email)
4. [Git Branch Management](#4-git-branch-management)
5. [GitHub Project Upload](#5-github-project-upload)
6. [GitHub Repository Update](#6-github-repository-update)
7. [GitHub Repository Remote Management](#7-github-repository-remote-management)
8. [Git Troubleshooting](#8-git-troubleshooting)

---

## 1. Windows Credential Manager

### Open Credential Manager

1. Press `Windows + S`.
2. Search `Credential Manager`.
3. Open Windows Credentials.
4. Find GitHub-related credentials.
5. Select the credential to view or remove it.

**Note:** Removing a credential may require you to authenticate again.

### Check Git Credential Manager

```bash
git credential-manager --version
```

### GitHub Authentication

```bash
gh auth login
```

Check authentication:

```bash
gh auth status
```

---

## 2. Check Git Email

Check local repository email:

```bash
git config user.email
```

Check global email:

```bash
git config --global user.email
```

Check username:

```bash
git config user.name
```

Check all Git configurations:

```bash
git config --list
```

---

## 3. Change Git Email

### Change email for current repository

```bash
git config user.email "your-new-email@example.com"
```

### Change email globally

```bash
git config --global user.email "your-new-email@example.com"
```

### Change Git username

```bash
git config --global user.name "Your Name"
```

**Important:** Git email configuration changes the author information on future commits. It does not change your email address in your GitHub account.

---

## 4. Git Branch Management

### Check current branch

```bash
git branch
```

### Create a new feature branch

```bash
git checkout -b feature
```

Modern alternative:

```bash
git switch -c feature
```

### Switch to main branch

```bash
git switch main
```

### Switch to feature branch

```bash
git switch feature
```

### List all branches

```bash
git branch -a
```

### Push a new branch to GitHub

```bash
git push -u origin feature
```

### Merge feature into main

```bash
git switch main
git pull origin main
git merge feature
git push origin main
```

---

## 5. GitHub Project Upload

### Requirements

- Git installed
- GitHub account
- GitHub CLI (`gh`) installed (optional for manual remote setup)

### Method 1: Create Repository Using GitHub CLI

```bash
gh auth login

git init

git add .

git config user.name "Your Name"
git config user.email "your-email@example.com"

git commit -m "Initial commit"

git branch -M main

gh repo create
```

Follow the interactive prompts to create the repository and configure its remote.

### Method 2: Create Repository with a Specific Name

```bash
gh auth login

git init

git add .

git config user.name "Your Name"
git config user.email "your-email@example.com"

git commit -m "Initial commit"

git branch -M main

gh repo create my-awesome-project --public --source=. --remote=origin

git push -u origin main
```

### Short Form

```bash
gh repo create my-awesome-project -p -s . -r origin
```

### Method 3: Connect an Existing GitHub Repository Manually

```bash
git init

git add .

git commit -m "Initial commit"

git branch -M main

git remote add origin https://github.com/USERNAME/REPOSITORY.git

git push -u origin main
```

Replace `USERNAME` and `REPOSITORY` with your actual GitHub username and repository name.

---

## 6. GitHub Repository Update

### Step 1: Open your project folder

```bash
cd "path/to/your/project"
```

### Step 2: Check repository status

```bash
git status
```

### Step 3: Check remote connection

```bash
git remote -v
```

If `origin` is already configured, do not add it again.

If no remote exists:

```bash
git remote add origin https://github.com/USERNAME/REPOSITORY.git
```

### Step 4: Pull latest GitHub changes

```bash
git pull --rebase origin main
```

Resolve any conflicts if necessary.

### Step 5: Add updated files

```bash
git add .
```

To include all additions, modifications and deletions:

```bash
git add -A
```

### Step 6: Commit changes

```bash
git commit -m "Update project files"
```

### Step 7: Push to GitHub

```bash
git push -u origin main
```

### Complete Update Command

Use this sequence when your local and remote histories are synchronized:

```bash
git pull --rebase origin main
git add -A
git commit -m "Update project files"
git push -u origin main
```

If Git reports that there is nothing to commit, skip the commit command and push only if needed.

---

## 7. GitHub Repository Remote Management

### Check remote URL

```bash
git remote -v
```

### Add a new remote

```bash
git remote add origin https://github.com/USERNAME/REPOSITORY.git
```

### Change existing remote URL

```bash
git remote set-url origin https://github.com/USERNAME/REPOSITORY.git
```

### Remove remote

```bash
git remote remove origin
```

### Verify remote

```bash
git remote -v
```

---

## 8. Git Troubleshooting

### Problem 1: Origin does not appear to be a Git repository

Error:

```text
fatal: 'origin' does not appear to be a git repository
```

Solution:

```bash
git remote -v

git remote add origin https://github.com/USERNAME/REPOSITORY.git

git push -u origin main
```

If `origin` already exists but has the wrong URL:

```bash
git remote set-url origin https://github.com/USERNAME/REPOSITORY.git
```

### Problem 2: Nested Git Repository

Error:

```text
error: 'folder-name/' does not have a commit checked out
fatal: adding files failed
```

Check the nested folder:

```bash
ls -la folder-name/
```

If it contains `.git`, determine whether it is an intentional separate repository.

If you want the folder's contents to become normal files in the parent repository, and do not need its separate Git history:

```bash
rm -rf folder-name/.git
```

Then:

```bash
git add -A
git commit -m "Add project files"
git push origin main
```

### Problem 3: Pull and Push Rejected

```bash
git pull --rebase origin main
```

Resolve conflicts, then:

```bash
git add -A
git rebase --continue
git push origin main
```

If no rebase is in progress, do not run `git rebase --continue`.

### Problem 4: Check Current Repository

```bash
pwd
git rev-parse --show-toplevel
git status
git branch
git remote -v
```

### Problem 5: Force Push

Use only when you intentionally need to overwrite remote history and understand the consequences.

```bash
git push --force-with-lease origin main
```

Avoid using `--force` as a routine repository update command.

---

## Quick Reference: Most Used Git Commands

| Task | Command |
|---|---|
| Initialize | `git init` |
| Check status | `git status` |
| Add files | `git add .` |
| Add all changes/deletions | `git add -A` |
| Commit | `git commit -m "message"` |
| Push | `git push origin main` |
| Pull | `git pull origin main` |
| Pull with rebase | `git pull --rebase origin main` |
| Check branch | `git branch` |
| Create branch | `git switch -c feature` |
| Switch branch | `git switch main` |
| Check remote | `git remote -v` |
| Set remote | `git remote set-url origin URL` |
| Check GitHub login | `gh auth status` |

---

**Repository:** https://github.com/

**Remember:** Always check `git status` and `git remote -v` before updating an existing repository.

# -- Windows - Credential Manager --
# Git & GitHub Guide

## Contents

- [Check email on GitHub](#check-email-on-github)
- [Change email on GitHub](#change-email-on-github)
- [Git change main → feature branch (new)](#git-change-main--feature-branch-new)
- [GitHub project upload](#github-project-upload)
- [GitHub repository update](#github-repository-update)
- [Nested Git Repository Fix](#nested-git-repository-fix)

---

## Check email on GitHub

```bash
git config user.email
```

or

```bash
git config --global user.email
```

## Change email on GitHub

```bash
git config user.email "your-new-email@example.com"
```

or

```bash
git config --global user.email "your-new-email@example.com"
```

## Git change main → feature branch (new)

```bash
git checkout -b feature
```

or

```bash
git switch -c feature
```

Switch back to main:

```bash
git switch main
```

---

## GitHub project upload

### Method 1

```bash
gh auth login
git init
git add .
git config user.email "your-new-email@example.com"
git commit -m "first commit"
git branch -M main
gh repo create
```

### Method 2

```bash
gh auth login
git init
git add .
git config user.email "your-new-email@example.com"
git commit -m "first commit"
git branch -M main
gh repo create <repository-name> --public --source=. --remote=origin
git push -u origin main
```

Short form of the `gh repo create` command:

```bash
gh repo create my-awesome-project -p -s . -r origin
```

Or add the remote manually:

```bash
git remote add origin https://github.com/your-username/repo-name.git
git push -u origin main
```

---

## GitHub repository update

### 1st step: Authentication

```bash
gh auth login
```

### Check existing repository

```bash
git status
git remote -v
git branch
```

For creating a new repository:

```bash
git init
git add .
```

For connecting an existing GitHub repository:

```bash
git remote add origin https://github.com/yourusername/your-repo.git
```

If origin already exists, update its URL instead:

```bash
git remote set-url origin https://github.com/yourusername/your-repo.git
```

### 2nd step: GitHub project update

First, get the latest changes from GitHub:

```bash
git pull --rebase origin main
```

### Update files (including deleted files)

```bash
git add -A
git commit -m "Update project files"
git push origin main
```

### Only update existing files

```bash
git add .
git commit -m "Update project files"
git push origin main
```

**Note:** `git add .` also stages new files and modifications, but `git add -A` additionally stages deletions.

---

## Nested Git Repository Fix

### Problem

Error:

```text
error: 'folder-name/' does not have a commit checked out
fatal: adding files failed
```

**Reason:** A Git repository exists inside another Git repository (Nested Git Repository).

### Step 1: Check nested Git folder

```bash
ls -la folder-name/
```

If you see `.git/`, the folder contains another Git repository.

### Step 2: Remove the nested Git repository

If you want to upload the folder contents as normal files to the parent repository, and do not need the nested repository's Git history:

```bash
rm -rf folder-name/.git
```

If the nested folder contains no required project files and you only want to remove that empty nested repository:

```bash
rm -rf folder-name/
```

**Important:** The second command deletes the entire folder and its contents. Use it only after checking the folder.

### Step 3: Add all files

```bash
git add .
```

or

```bash
git add -A
```

### Step 4: Commit changes

```bash
git commit -m "Update image restoration project"
```

### Step 5: Push to GitHub

```bash
git push origin main
```

### Complete command (if removing the entire unwanted nested folder)

```bash
rm -rf folder-name/
git add -A
git commit -m "Update image restoration project"
git push origin main
```

### Complete command (if keeping nested folder contents)

```bash
rm -rf folder-name/.git
git add -A
git commit -m "Update image restoration project"
git push origin main
```

---

## Quick GitHub Update Commands

```bash
git status
git pull --rebase origin main
git add -A
git commit -m "Update project files"
git push origin main
```

**Remember:**
- Check `git remote -v` before pushing.
- Do not add `origin` again if it already exists.
- Resolve merge conflicts before pushing.
- Never use `git push --force` as a routine update command.
- Check nested `.git` folders if `git add .` fails.

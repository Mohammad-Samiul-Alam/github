# Git & GitHub Guide

## Contents

- [Check email on GitHub](#check-email-on-github)
- [Change email on GitHub](#change-email-on-github)
- [Git change main → feature branch (new)](#git-change-main--feature-branch-new)
- [GitHub project upload](#github-project-upload)
- [GitHub repository update](#github-repository-update)

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

---

## GitHub project upload

### Method 1

```bash
gh auth login
git init
git add .
git commit -m "first commit"
git config user.email "your-new-email@example.com"
git branch        # checking branch
gh repo new
```

### Method 2

```bash
gh auth login
git init
git add .
git commit -m "first commit"
git branch        # not required
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
```

---

## GitHub repository update

### 1st step

```bash
gh auth login
```

For creating a new repository:

```bash
git init
git add .
```

For updating an old repository:

```bash
git remote add origin https://github.com/yourusername/your-repo.git
```

### 2nd step: GitHub project update

Remove everything if you delete something:

```bash
git add .
git commit -m "Merge conflict resolved"
git push --force origin main
```

Only update, nothing deleted:

```bash
git pull origin main --rebase
git push -u origin main
git add .
git commit -m "Merge conflict resolved"
git push -u origin main
```

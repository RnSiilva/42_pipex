<h1 align="center">
  ┃ pipex
</h1>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/RnSiilva/42_pipex?color=blueviolet" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/RnSiilva/42_pipex?color=blue" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/RnSiilva/42_pipex?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/RnSiilva/42_pipex?color=brightgreen" />
</p>

<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#-index">Index</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
	<span> · </span>
	<a href="#-testing">Testing</a>
	<span> · </span>
	<a href="#-useful-links">Useful Links</a>
	<span> · </span>
	<a href="#-concepts">Concepts</a>
</h3>

---

## 💡 About the project

> _This project will let you discover in detail a UNIX mechanism that you already know
by using it in your program._

Pipex reproduces the behaviour of the shell pipe | command in C.

It launches as `./pipex infile cmd1 cmd2 outfile` and behaves as this line does in the shell `< infile cmd1 | cmd2 > outfile`.

## 📑 Index

* [**📁 includes:**](pipex/inc/) contains the program's headers.
* [**📁 src:**](pipex/src/) contains the source code of the program.
* [**📁 libft:**](pipex/libft/) contains the source code of the libft library, which is used in the program.
* [**📁 my_tutorials:**](my_tutorials/) contains some test codes to improve knowledge.
* [**Makefile**](pipex/Makefile) - contains instructions for compiling the program and testing it.

_Note: only mandatory requirements of the project's subject are covered._

## 🛠️ Usage

### Requirements

The program is written in C language for **Linux** distributions and thus needs the **`clang` compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling the program**

To compile the program, run:

```shell
$ make
```
This will compile the source files and generate the `pipex` executable.


**2. Executing the program**

To execute the program, run:

```shell
$ ./pipex file1 cmd1 cmd2 file2
```
The file1 must be created by the user before running the program (or use one that I left available in the `infile` directory).
The output file is created automatically if it does not exist.

**3. Example**

```shell
$ ./pipex infile/in.txt "grep airline." "cat" out.txt
```

**4. Memory Leaks Test**
```shell
valgrind --leak-check=full --trace-children=yes ./pipex file1 cmd1 cmd2 file2
```

---
## Grade: 100 / 100

## 📋 Testing

You can use this third party tester to fully test the project:

- PIPEXaminator: https://github.com/mariadaan/PIPEXaminator
- pipex-tester: https://github.com/vfurmane/pipex-tester

## 📌 Useful Links

* [[YOUTUBE] Unix process in C](https://www.youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY)
* [[MEDIUM] Pipex tutorial](https://csnotes.medium.com/pipex-tutorial-42-project-4469f5dd5901)

## 🕮 Concepts

- **Subprocesses**: Let's work with different processes. One for the first command to be executed, and one to the second.For this, we will use the fork() function that creates a child process.
- **Pipes**: To connect the processes, let's use pipes. Pipes are bufffers that allow communication between processes. To create a pipe, we use the pipe() function.
- **Redirection**: To redirect the input and output of the processes, we will use the dup2() function.It receives two file descriptors as a parameter, and causes the file descriptor received as a second parameter to be a copy of the file descriptor received as the first parameter. Thus, we can redirect the input and exit of the processes to the pipes.
- **Execution of commands**: To execute the commands, we will use the execve() function. It receives as parameters the path of the executable file, a string array with the command arguments. With this, in the command being called, the process that called it is replaced by the command process.

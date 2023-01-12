<h1 align="center">
	Get Next Line
</h1>

<p align="center">
	<b><i>Reading a line on a fd is way too tedious</i></b><br>
</p>

<p align="center">
  <img alt="File count" src="https://img.shields.io/github/directory-file-count/JJunghyunY/Ecole-42/get_next_line" />
	<img alt="Keywords" src="https://img.shields.io/badge/keyword-Unix%20logic-red" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/surfi89/get_next_line?color=blue" />
</p>

<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
	<span> · </span>
	<a href="#-testing">Testing</a>
</h3>

---

## 💡 About the project

> _This project is about programming a function that returns a line read from a file descriptor_
```
  This project will not only allow you to add a very convenient function to your collection,
  but it will also make you learn a highly interesting new concept in C programming: static variables.
```
	You will understand how files are opened, read and closed in an OS,
	and how they are interpreted by a programming language for further analysis.
	This task is crucial to understand for a future programmer since much of the time is based
	on manipulating files for data management and persistence.
  
	This project consists of coding a function that returns one line at a time from a text file.

## 🛠️ Usage

### Requirements

The function is written in C language and thus needs the **`cc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Using it in your code**

To use the function in your code, simply include its header:

```C
#include "get_next_line.h"
```

and, when compiling your code, add the source files and the required flag:

```shell
get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=<size>
```
**if you don't define BUFFER_SIZE, it will define the BUFFER_SIZE to 42**

## 📋 Testing

You only have to edit the get_next_line.c file and uncomment the main function and headers inside it.
You can edit test.txt files to put another text if you wish to test othe cases.
Then simply run this command (change "<size>" with desired buffer size) :

```shell
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=<size> get_next_line.c get_next_line_utils.c && ./a.out
```

Or you can also use this third party tester to fully test the project

* [Tripouille/gnlTester](https://github.com/Tripouille/gnlTester)

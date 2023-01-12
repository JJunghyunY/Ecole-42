<h1 align="center">
	push_swap
</h1>

<p align="center">
	<b><i>Because Swap_push isn’t as natural</i></b><br>
</p>

<p align="center">
	<img alt="Number of files" src="https://img.shields.io/github/directory-file-count/JJunghyunY/Ecole-42/push_swap" />
 	<img alt="Clang" src="https://img.shields.io/badge/c-100%25-blue" />
	<img alt="Keyword name" src="https://img.shields.io/badge/keyword-Sorting%20algorithms-red" />
 	<img alt="Keyword name" src="https://img.shields.io/badge/keyword-Battery%20concept%20and%20handling%20elements-red" />
	<img alt="Keyword name" src="https://img.shields.io/badge/keyword-Algorithm%20implementation-red" />
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

> _This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed you’ll have to manipulate various
types of algorithms and choose the one (of many) most appropriate solution for an
optimized data sorting._

	The Push swap project is a very simple and a highly straightforward algorithm project: data must be sorted.

## 🛠️ Usage

### Requirements

The function is written in C language and thus needs the **`cc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling the program**

To compile, go to the program path and run:

```shell
$ make
```

**2. Executing the program**

To execute the program, run:

```C
$ ./push_swap $ARG
```

where `$ARG` is a space separated list of integers, e.g. `ARG="1 5 2 4 3"`

**3. Checking the program work**

To execute the checker program, run:

```C
$ ./push_swap $ARG | checker_Mac $ARG
```


### Actions

**PUSH**

Take the first element at the top of one stack and put it at the top of the other; do nothing if the origin stack is empty.

* **`pa`** - top element of _stack b_ goes to top of _stack a_.
* **`pb`** - top element of _stack a_ goes to top of _stack b_.

**SWAP**

Swap the first 2 elements at the top of the stack; do nothing if there is only one or no elements.

* **`sa`** - swap  _stack a_.
* **`sb`** - swap  _stack b_.
* **`ss`** - `sa` and `sb` at the same time.

**ROTATE**

Shift up all elements of the stack by one; the first element becomes the last.

* **`ra`** - rotate stack a.
* **`rb`** - rotate stack b.
* **`rr`** - `ra` and `rb` at the same time.

**REVERSE ROTATE**

Shift down all elements of the stack by one; the last element becomes the first.

* **`rra`** - reverse rotate stack a.
* **`rrb`** - reverse rotate stack b.
* **`rrr`** - `rra` and `rrb` at the same time.

## 📋 Testing

You can use this third party testers to fully test the project:

* [LeoFu9487/push_swap_tester](https://github.com/LeoFu9487/push_swap_tester)

And a useful to visualize the movements:

* [o-reo/push_swap_visualizaer](https://github.com/o-reo/push_swap_visualizer)

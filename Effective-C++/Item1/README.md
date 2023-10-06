# Item 1. View C++ as a federation of language

## Table of contents

- [View C++ as a federation of language](#View-C++-as-a-federation-of-language)

## View C++ as a federation of language

In the past day, C++ is just an OOP extension of the C language.

But today's C++ can be viewed as a **multiparadigm programming language**, one supporting a combination of the following paradigms:

- procedural paradigm
- functional paradigm
- OOP paradigm
- generic paradigm 
- metaprogramming paradigm

What is the programming paradigm? We can learn it from [Programming Paradigm](https://www.youtube.com/watch?v=Ps8jOj7diA0&list=PL9D558D49CA734A02).

To make sense of the C++ language, we can recognize the  following 4 sub-languages:

1. **C**: The following features all come from C:
	- blocks
	- statements
	- preprocessor
	- built-in data types
	- arrays
	- pointers
	- etc.
2. **Objected-Oriented C++**: The following parts provide C++ the classic rules for OOP design:
	- classes
	- objects
	- constructors
	- deconstructors
	- encapsulation
	- inheritance
	- polymorphism
	- virtual class and virtual function
	- friend class
3. **Template C++**: The is the part of the generic programming in C++.
4. **STL**: STL stands for standard template library, which is regarding to:
	- containers
	- iterators
	- algorithms
	- function objects

	
Sometimes, we need to change the strategy when we switch from one sub-language to another.

For example:

pass-by-value is usually efficient than pass-by-reference, but when we are using the Objected-Oriented C++, the existence of the user-defined constructors means that **pass-by-reference-to-const is better**.

However, when we come accross into the STL. Iterators and function objects are modeled on the pointers in C, so the old C pass-by-value rule applies again.
# Item 2. Prefer complier to the pre-processor

## Table of contents

- [Advantages of avoiding `#define`](#advantages-of-avoiding-define)
  - [Symbols enter the symbol table](#constant-can-be-entered-the-symbol-table)
  - [Results in smaller object code](#less-copies-in-the-object-code--smaller-code)
  - [Encapsulation is maintained](#provide-the-encapsulation)
  - [Explanation: Constant vs `#define`](#when-we-do-something-like-this)

- [Two special cases when replacing `#define` with constants](#two-special-cases-when-replacing-define-with-constants)
  - [Special case 1: constant pointers](#special-case-1-constant-pointers)
  - [Special case 2: class-specific constants](#special-case-2-class-specific-constants)

- [enum hack](#enum-hack)

- [Use inline instead of `#define` directive](#use-inline-instead-of-define-directive)
  - [Problem in `#define` macros](#problem-in-define-macros)
  - [Use inline function instead](#use-inline-function-instead)

## Advantages of avoiding ```#define```

1. Constant can be entered the symbol table
2. Less copies in the object code -> smaller code
3. Provide the encapsulation

When we do something like this:

```
#define PI 3.14159
```

The ```PI``` may never be seen by the compiler. It's removed by the preprocessor before the source code ever gets to the complier.

Therefore, the name ```PI``` may not get entered into the symbol table. It can be confusing when we encounter an error message refer to ```3.14159``` instead of ```PI```.

This may make us have no idea where the ```3.14159``` comes from.

One solution is to replace the macro with a constant:

```
const double Pi = 3.14159;
```

Since we define the variable as a constant, ```Pi``` can be seen by compilers and be entered into the symbol table.

The second advantage of using ```const``` instead of ```#define``` is that it yields a smaller code.

## Two special cases when replacing ```#define``` with constants

1. constant pointers
2. class-specific constants

### Special case 1: constant pointers

> It's important that the pointer be declared const usually in addition to what the pointer points to.

To define a constant char*-based string in a header file, we have to write const twice like:

```
const char* const authorName = "Chih-Hao Huang"
```

Here, string object is preferable to the char*-based progenitors.

```
const std::string authorName("Chih-Hao Huang"
```

### Special case 2: class-specific constants

```#define``` can not be used to create the class-specific constant, because ```#define``` doesn't respect scope.

To limit the scope of a constant to class, we need to make it a **static member**.

For example:

```
class Circle {
	private:
		static const int Pi = 3.14159;
		int center;
		int radius;
};
```

In C++, class-specific constants that are static and integral type (e.g., integers, chars, bools) can provide the declaration instead of definition.

However, if we want to take the address of that constant, we can provide a definition like:

```
const int Circle::Pi;
```

Therefore, a more general way is:

```
class Circle {
	private:
		static const int Pi;
		...
};
const int Circle::Pi = 3.14159;
```

And we need to put the definition in the implementation file instead of header file.

## enum hack

Consider the following case:

```
class GamePlayer {
	private:
		static const int NumTurns = 5;
		int scores[NumTurns];
	...
};
```

Compiler may insist on knowing the size of the ```scores```, we need the value of the class constant during the compilation.

We cannot declare the class constant first then provide the definition in this case.

Therefore, we can apply the enum hack to compensate for compilers.

```
class GamePlayer {
	private:
		enum { NumTurns = 5 };
		int scores[NumTurns];
	...
};
```

The enum hack makes ```NumTurns``` a symbolic name for 5.

Enum Hack has some advantages:

1. Disable taking the address of an enum
2. Some sloppy compilers may set aside memory for const objects
3. It's a fundamental technique in template metaprogramming

## Use inline instead of #define directive

### Problem in #define macros

Someone may use the ```#define``` directive to implement macros like:

```
#define CALL_WITH_MAX(a,b) f((a) > (b) ? (a): (b)) 
```

Using macros will not incur the overhead of a function call, however, macros like this have many drawbacks.

See the following example:

```
#include <iostream>
#define CALL_WITH_MAX(a, b) f((a) > (b) ? (a) : (b))

using namespace std;

void f(int n) {
	cout << "n: " << n << endl;
}

int main(void) {
	int a = 5, b = 0;
	CALL_WITH_MAX(++a, b); // a is incremented twice
	CALL_WITH_MAX(++a, b+10); // a is incremented once
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	return 0;
}
```

Since marcos are processed by the preprocessor before the actual compilation, and they are just textual replacements.

When arguments are used multiple times inside a macro, side effects, such as increments, will happen multiple times.

For the first ```CALL_WITH_MAX(++a, b);```:

It will be replaced with:

```
f((++a) > (b) ? (++a) : (b));
```

It evaluates ```(++a) > (b)``` first and this increments ```a``` by 1.

After that, since the condition is true, the true branch ```(++a)``` of the ternary operation is taken.

However, for the second ```CALL_WITH_MAX(++a, b+10);```, the true branch ```(++a)``` of the ternary operation isn't taken.

Therefore, ```a``` is incremented once for the second time.

**The number of times that a incremented before calling f depends on what it's being compared with.**


### Use inline function instead

We can get all the efficiency of a macro plus all the predicatble behavior by using a template for an inline function.

For example:

```
template<typename T> inline void callWithMax(const T& a, const T& b) {
	f(a > b ? a : b);
}
```

Functions (including template functions) evaluate their arguments exactly once.

See the example again:

```
#include <iostream>

using namespace std;

void f(int n) {
	cout << "n: " << n << endl;
}

template<typename T> inline void callWithMax(const T& a, const T& b) {
	f(a > b ? a : b);
}

int main(void) {
	int a = 5, b = 0;
	callWithMax(++a, b);
	callWithMax(++a, b+10);
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	return 0;
}
```

When we call ```callWithMax(++a, b)```:

1. ```++a``` is evaluated once, incrementing ```a``` by 1
2. ```b``` is evaluated without any side effect

In conclusion, given the ```consts```, ```enums``` and ```inlines```, our need for preprocessor is reduced.
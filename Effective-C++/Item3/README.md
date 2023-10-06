# Item 3. Use ```const``` whenever possible

## Table of contents

## Use ```const``` whenever possible

### const pointers

```const``` allows us to specify a semantic constraint - a object should not be modified.

It provides us a way to communicate between compilers and programmers that a value should remain invariant.

```const``` is flexible, one can see the following example:

```
char greeting[] = "Hello, World!";

char *p = greeting; // non-const pointer non-const data

const char *p = greeting; // non-const pointer const data

char* const p = greeting; // const pointer non-const data

const char* const p = greeting; // const pointer const data
```

We can specify whether the pointer or the date pointed by the pointer be a constant.

> we can read pointer declarations right to left, e.g., to read ```const char* const p``` is a constant pointer to  constant chars

### const STL iterators

Since the STL iterators are modeled on pointers, declaring constant iterators is like declaring a constant pointer.

If we want an iterator that points to something that can't be modified.

We should use a ```const_iterator```:

```
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	vector<int> nums;
	const vector<int>::iterator iter = nums.begin();
	*iter = 10;
	++iter; // error: increment of const iterator 'iter'

	vector<int>::const_iterator citer = nums.begin();
	*citer = 10; // error: assignment of read-only location '* citer'
	++citer; // ok
	return 0;
}
```

### const in function declaration

Within a function declaration, const can refer to the function's return value.

Having a function return a constant value is generally inappropriate, but sometimes it can reduce the incidence of client errors without giving up safety.

For example:

```
class Rational(...);
const Rational operator*(const Rational& lhs, const Rational& rhs);
```

This can avoid the following usage from the clients:

```
Rational a, b, c;
(a * b) = c;
```

Since some programmers may have tried to do it without wanting to:

```
if (a * b = c)... // meant to do a comparison
```

By declaring ```operator*``` return value ```const```, we can avoid the situation.

### const member functions

const on member functions are important for two reasons:

1. it makes the interface of a class easier to understand.
2. it's possible to work with ```const``` objects.

> One of the fundamental ways to improve a C++ program's performance is to pass objects by reference-to-const.


# 1. Introduction

## Table of Contents
- [Initialization](#initialization)
- [Copy Constructor](#copy-constructor)
- [Undefined Behavior](#undefined-behavior)
- [Client](#client)

## Initialization

Constructors declared explicit are usally preferable to non-explicit ones.

Self-defined constructors can prevent compilers from performing unexpected type conversions.

## Copy Constructor

The copy constructor defines how an object is passed by value.

For example:

```
double twoPointsDistance(Point p1, Point p2);

Point p3(10, 20);
Point p4(30, 40);
std::cout << "Distance between p1 and p2: " << twoPointsDistance(p1, p2) << std::endl;
```

The parameter ```p3``` is passed to the ```twoPointsDistance``` function by value.

```p3``` is copied into ```p1```. The copying is done by the copy constructor.

We need to specify the copy constructor to fully control what we want to pass to the function.

## Undefined Behavior

The behavior of some constructs in C++ is not defined.

Therefore, we can not predict what will happen at runtime.

For example:

Compare the difference of the two programs:

```
#include <iostream>

using namespace std;

int main(void) {
	int *p = new int;
	*p = 10;
	cout << *p << endl;
	return 0;
}
```

```
#include <iostream>

using namespace std;

int main(void) {
	int *p = 0;
	cout << *p << endl;
	return 0;
}
```

In the second program, we are dereferencing a null pointer.

This is as called **"undefined behavior"**.

Since we cannot predict the result of the undefined behavior, we should do our best to steer clear of the undefined behavior.

## Client

A client is someone or something that uses the code we write.

Since we are the clients who use the code we wrote most of the time, we need to keep client concerns in mind.
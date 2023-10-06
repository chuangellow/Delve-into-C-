# Effective C++

## Things to Remember

### Item 1. View C++ as a federation of languages

1. Rules for effective C++ programming vary, depending on the sub-languages we are using.

### Item 2. Prefer consts, enums, and inlines to #defines

1. For simple constants, prefer ```const``` or ```enum``` to ```#define```.
2. For function-like macros, prefer ```inline``` functions to ```#define```.
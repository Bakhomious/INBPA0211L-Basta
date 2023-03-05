# High Level Programming Languages 1 — Lab 03 Overview

## Functions

A function is a group of statements that together perform a task. Every C program has at least one function, which is **`main()`**, and all the most trivial programs can define additional functions.

You can divide up your code into separate functions. How you divide up your code among different functions is up to you, but logically the division is such that **each function performs a specific task**.

### Defining a Function

```C
return_type function_name( parameter list ) {
   body of the function
}
```

Example [Pythagorean theorem](P103212-e.c):

```C
float pythagorean(float a, float b) {
    return sqrt((a * a) + (b * b));
}
```

### Calling a function

To use a function, you will have to call that function to perform the defined task.

When a program calls a function, the program control is transferred to the called function. A called function performs a defined task and when its return statement is executed or when its function-ending closing brace is reached, it returns the program control back to the main program.

To call a function, you simply need to pass the required parameters along with the function name, and if the function returns a value, then you can store the returned value.

Example:

```C
#include <stdio.h>
#include <math.h>

float pythagorean(float a, float b) { return sqrt((a * a) + (b * b)); }

int main() {

    float result = pythagorean(5, 6);
    printf("%f", result);

    return 0;
}
```

### Function Arguments

If a function is to use arguments, it must declare variables that accept the values of the arguments. These variables are called the **formal parameters** of the function.

Formal parameters behave like other local variables inside the function and are created upon entry into the function and destroyed upon exit.

While calling a function, there are two ways in which arguments can be passed to a function −

|Call type | Description|
|----------|------------|
|Call by value | This method copies the actual value of an argument into the formal parameter of the function. In this case, changes made to the parameter inside the function have no effect on the argument.|
|Call by reference| This method copies the address of an argument into the formal parameter. Inside the function, the address is used to access the actual argument used in the call. This means that changes made to the parameter affect the argument.|

By default, C uses **call by value** to pass arguments. In general, it means the code within a function cannot alter the arguments used to call the function.

---

## C Recursion

Recursion is the technique of making a function call itself. This technique provides a way to break complicated problems down into simple problems which are easier to solve.

[Fibonoacci Sequence](P103303-e.c) Example:

```C
#include <stdio.h>

int n_fibonacci(int n) {

    if (n <= 1)
        return 1;
    return (n_fibonacci(n - 1) + n_fibonacci(n - 2));
}

int main() {
    
    int next_term = n_fibonacci(5);
    printf("%d", next_term);

    return 0;
}
```

> Note: You can modify this program to produce a complete sequence to the terminal, i.e, $0, 1, 1, 2, 3, 5, \dots$ think about how can you implement it.

Programmers need to be careful to define an exit condition from the function, otherwise it will go into an **infinite loop**, this can easily cause what is known as **Stack Overflow**.


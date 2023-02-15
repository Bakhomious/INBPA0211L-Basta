# High Level Programming Languages 1 &mdash; Lab 01 Overview

## The GCC compiler

To install the `gcc` compiler on your personal computers, you can follow this detailed [guide](https://code.visualstudio.com/docs/cpp/config-mingw).

### Usage

`gcc --help`: Print (on the standard output) a description of the command-line options understood by gcc.

`-c`: Compile or assemble the source files, but do not link. The linking stage simply is not done. The ultimate output is in the form of an object file for each source file.
By default, the object file name for a source file is made by replacing the suffix '.c', with '.o'.
Unrecognized input files, not requiring compilation or assembly, are ignored.

`-o <file>`: Place the primary output in file file. This applies to whatever sort of output is being produced, whether it be an executable file, an object file, an assembler file or preprocessed C code.

If `-o` is not specified, the default is to put an executable file in `a.out`.

`-E`: Stop after the preprocessing stage; do not run the compiler proper. The output is in the form of preprocessed source code, which is sent to the standard output. Input files that don’t require preprocessing are ignored.

---

## First steps: Hello, World!

```c
#include <stdio.h>

int main() {
   // printf() displays the string inside quotation
   printf("Hello, World! \n");
   return 0;
}
```

Moving on to the compilation process. First of all navigate to the directory containing the source code. We can compile the program if we execute the following.

```bash
$ gcc hello.c -o hello
$ ./hello
Hello, World!
```

---

## Data Types

|Type | Storage Size|
|------|------------|
|char| 1 byte |
|int | 2 or 4 byte |
|float| 4 byte |
|double | 8 byte |

### Limits of Data Types

Compile this code below and see the output

```c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

int main() {

    printf("CHAR_MAX    :   %d\n", CHAR_MAX);
    printf("CHAR_MIN    :   %d\n", CHAR_MIN);

    printf("INT_MAX     :   %d\n", INT_MAX);
    printf("INT_MIN     :   %d\n", INT_MIN);

    printf("FLT_MAX     :   %g\n", (float) FLT_MAX);
    printf("FLT_MIN     :   %g\n", (float) FLT_MIN);

    printf("DBL_MAX     :   %g\n", (double) DBL_MAX);
    printf("DBL_MIN     :   %g\n", (double) DBL_MIN);

    return 0;
}
```

---

## Defining Variables

```c
// Definition
int    i, j, k;
char   c, ch;
float  f, salary;
double d;

// Initialization

i = 5;
j = 30;
k = i + j;

// Definition and Initializaiton
int a = 3, b = 5;
char x = 'x';
```

---

## Input/Output

We use `printf()` to produce an output. *See [Hello World](#first-steps-hello-world)*.

```c
#include <stdio.h>
int main()
{
    int a = 5;
    float f = 13.5;
    double d = 12.4;
    char chr = '+';

    printf("a = %d \n", a);
    printf("number1 = %f \n", f);
    printf("number2 = %lf \n", d);
    printf("char = %c", chr);

    return 0;
}
```

To take input from the user we use `scanf()`.

```c
#include <stdio.h>
int main()
{
    int number1;

    printf("Enter an integer: ");

    scanf("%d", &number1);

    printf("Number = %d", number1);
    return 0;
}
```

> Notice, that we have used `&number1` inside `scanf()`. It is because `&number1` gets the address of `number1`, and the value entered by the user is stored in that address.

----

## Control Statements

### if-else else-if statement

```c
if(boolean_expression 1) {
   /* Executes when the boolean expression 1 is true */
} else if( boolean_expression 2) {
   /* Executes when the boolean expression 2 is true */
} else if( boolean_expression 3) {
   /* Executes when the boolean expression 3 is true */
} else {
   /* executes when the none of the above condition is true */
}
```

---

### The `?` Operator

This can be used to replace the classic if-else statements. `Exp2` is evaluated if `true`, otherwise `Exp3` is evaluated.

```c
Exp1 ? Exp2 : Exp3;
```

---

### Switch Statement

```c
switch(expression) {

   case constant-expression  :
      statement(s);
      break; /* optional */
	
   case constant-expression  :
      statement(s);
      break; /* optional */
  
   /* you can have any number of case statements */
   default : /* Optional */
   statement(s);
}
```

---

## Loops

### For Loop

```c
for ( init; condition; increment ) {
   statement(s);
}
```

---

### While Loop

```c
while(condition) {
   statement(s);
}
```

---

### Do-While Loop

```c
do {
   statement(s);
} while( condition );
```

---

## Type Casting

Converting one data type to another

```c
(type_name) expression
```
### Example

```c
#include <stdio.h>

main() {

   int sum = 17, count = 5;
   double mean;

   mean = (double) sum / count;
   printf("Value of mean : %f\n", mean );
}
```

---

## Homework for the week

Solve the following:

- [PC200783](https://github.com/INBPA0212L-2023/exercises/blob/main/week-01/PC200783.md)
- [PC200785](https://github.com/INBPA0212L-2023/exercises/blob/main/week-01/PC200785.md)
- [PC200790](https://github.com/INBPA0212L-2023/exercises/blob/main/week-01/PC200790.md)

Method of Submission:

TO BE DISCUSSED
# High Level Programming Languages 1 — Lab 10 Overview

## `strtok()`

### Declaration

```C
char *strtok(char *str, const char *delim)
```

The C library function `strtok()` breaks breaks string `str` into a series of tokens using the delimiter `delim`.
Note that: The `const` keyword allows a programmer to tell the compiler that a particular variable should not be modified after the initial assignment in its declaration.

### Parameters

- `str` − The contents of this string are modified and broken into smaller strings (tokens).
- `delim` − This is the C string containing the delimiters. These may vary from one call to another.

### Return Value

This function returns a pointer to the first token found in the string. A null pointer is returned if there are no tokens left to retrieve.

### Example

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char line[101];

    gets(line);
    char *token = strtok(line, ";");
    while(token != NULL) {
        puts(token);
        token = strtok(NULL, ";");
    }

    return EXIT_SUCCESS;
}
```

What this little code snippet does is: it splits the string whenever it encounters the delimiter `;`. For example if we passed `John;Paul;George;Ringo;` this would print out the following:

```text
John
Paul
George
Ringo
```

---

## Structures

Arrays allow to define type of variables that can hold several data items of the same kind. Similarly structure is another user defined data type available in C that allows to combine data items of different kinds. Structures are used to represent a record.

Let's consider the [Airports](https://github.com/INBPA0212L-2023/exercises/blob/main/week-10/P110101.md) exercise to explain this further and break it down.

We want to keep track of the following information:

- Name of Airport &mdash; `string`
- Name of the City &mdash; `string`
- Number of Runways &mdash; `int`
- Transfer Time &mdash; `int`

## Defining a Structure

```C
struct [structure tag] {

   member definition;
   member definition;
   ...
   member definition;
} [one or more structure variables];  
```

Note that: structure tags and variables are optional but they are recommended for readability, scope and typing.

In the example here's our definition:

```C
struct Airport {
    char name[31];
    char city[31];
    int  runaways;
    int  time;
} AIRPORT;
```

## Accessing Structure Members

To access any member of a structure, we use the member access operator `.`. Which is a period.

In our `main()` let's define a `struct` and make it hold some data:

```C
    struct Airport a1;
    strcpy(a1.name, "Zurich Kloten");
    strcpy(a1.city, "Zurich");
    a1.runaways = 3;
    a1.time = 360;

    printf("%s, %s, %d, %d", a1.name, a1.city, a1.runaways, a1.time);
```

## Structures as Function Arguments

No fancy declarations or anything, you can pass a structure as a function argument in the same way as you pass any other variable or pointer.

```C
void print_struct(struct Airport airport) {
    printf("Name: %s\n", airport.name);
    printf("City: %s\n", airport.city);
    printf("Runaways: %d\n", airport.runaways);
    printf("Transfer Time: %d\n", airport.time);
}
```

## Pointers to Structures

You can define pointers to structures in the same way as you define pointer to any other variable and store the address of a structure variable using the `&` operator as follows &mdash;

```C
struct Airport *a1_ptr = &a1;
```

To access the members of a structure using a pointer to that structure, you must use the `->` (arrow) operator as follows &mdash;

```C
a1_ptr -> name;
```

To demonstrate the usage of this, let us edit `print_struct()`

```C
void print_struct(struct Airport *airport) {
    printf("Name: %s\n", airport -> name);
    printf("City: %s\n", airport -> city);
    printf("Runaways: %d\n", airport -> runaways);
    printf("Transfer Time: %d\n", airport -> time);
}
```

## Bit Fields

Bit Fields allow the packing of data in a structure. This is especially useful when memory or data storage is at a premium. 
    e.g Flag variables, i.e. `int` variables that holds either `0` or `1`

C allows us to do this in a structure definition by putting `:bit_length` after the variable.

### Example

```C
struct {
    unsigned int isTriangle : 1;
    unsigned int isSquare : 1;
} status;
```

Here, the struct holds 2 members each of width 1 bit.

Recommended Reading: [Tutorialspoint - Bit Fields](https://www.tutorialspoint.com/cprogramming/c_bit_fields.htm)

## `typedef`

The C programming language provides a keyword called `typedef`, which you can use to give a type a new name. This allows for a shorter declaration as follows &mdash;

```C
typedef struct Airports {
    char name[31];
    char city[31];
    int  runaways;
    int  time;
} AIRPORT;

int main() {
    AIRPORT a1;
    ...
}
```

Notice how we did not need to specify `struct` before declaring the airport.
By convention, uppercase letters are used for these definitions to remind the user that the type name is really a symbolic abbreviation.

*Remark: Do not confuse `typedef` with `#define`. Recommended Reading: [Microsoft - #define directive](https://learn.microsoft.com/en-us/cpp/preprocessor/hash-define-directive-c-cpp?view=msvc-170)*

---

## `qsort()`

A C library function sorts an array.

```C
void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
```

### Parameters

- **base** − This is the pointer to the first element of the array to be sorted.
- **nitems** − This is the number of elements in the array pointed by base.
- **size** − This is the size in bytes of each element in the array.
- **compar** − This is the function that compares two elements.

This function does not return any value.

### Example

Here is our input from the exercise:

```text
Zurich Kloten;Zurich;3;360
London Heathrow;London;2;240
Istanbul Ataturk;Istambul;3;120
Barcelona El Prat;Barcelona;3;150
```

Here is our main function that reads the input

```C
int main() {

    char line[101];

    gets(line);
    int n = atoi(line);
    AIRPORT airports[n];

    for(int i=0; i<n; i++) {
        gets(line);
        char *name = strtok(line, ";");
        char *city = strtok(NULL, ";");
        char *runways = strtok(NULL, ";");
        char *time = strtok(NULL, ";");

        strcpy(airports[i].name, name);
        strcpy(airports[i].city, city);
        airports[i].runways = atoi(runways);
        airports[i].time = atoi(time);
    }
}
```

Let us take a look at our parameters:

- **base** − `airports`
- **nitems** − `n`
- **size** − `sizeof(AIRPORT)`
- **compar** − `cmp`

The compar parameter is the complex one as we need to sort according to the following criteria:

1. number of runways (descending)
2. transfer time (descending)
3. name (ascending)

Hence we need to define `cmp()` according to the following definition `int (*compar)(const void *, const void*)`:
Note that the compar function returns **an integer that represents two elements relative order**.

```C
int cmp(const void *a, const void *b) {
    AIRPORT *left = (AIRPORT *)a;
    AIRPORT *right = (AIRPORT *)b;

    // Number of runways in descending order
    if (left -> runways != right -> runways) {
        return -(left -> runways - right -> runways);
    }

    // Transfer time in descending order
    if (left -> time != right -> time) {
        return -(left -> time - right -> time);
    }

    // Name in ascending order
    return strcmp(left -> name, right -> name);
}
```

All we need now is to invocate the `qsort()` in the `main()`

```C
int main() {
    ...
    qsort(airports, n, sizeof(AIRPORT), cmp);
}
```

---

## `bsearch()`

Uses Binary Search to search an array for a specific value

```C
void *bsearch(const void *key, const void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *))
```

### Parameters

- **key** − This is the pointer to the object that serves as key for the search, type-casted as a void*.
- **base** − This is the pointer to the first object of the array where the search is performed, type-casted as a void*.
- **nitems** − This is the number of elements in the array pointed by base.
- **size** − This is the size in bytes of each element in the array.
- **compare** − This is the function that compares two elements.

This function returns a pointer to an entry in the array that matches the search key. If key is not found, a NULL pointer is returned.

### Example

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int values[] = {5, 20, 29, 32, 63, 40, 90};

int cmp (const void *a, const void *b) {
    return ( *(int *)a - *(int *)b);
}

int main() {
    int *item;
    int key = 99;

    item = (int *) bsearch(&key, values, 7, sizeof(int), cmp);

    if (item != NULL) {
        printf("Founded %d\n", *item);
    } else {
        printf("Item couldn't be found\n");
    }

    return EXIT_SUCCESS;

}
```
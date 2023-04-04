# High Level Programming Languages 1 — Lab 08 Overview

## Command Line Arguments

It is possible to pass values from the command line to your C programs when they are being executed. They are important to maintain flexibility in your program if you do not want to hard code those values in code. Useful examples of this might be clear when you are doing file handling. 

Those command line arguments are handled via `main()` function where `argc` refers to the number of arguments passed, and `argv[]` is a pointer array which points to each argument passed to the program.

### Main Function Declaration

```C
int main(int argc, char *argv[]) { /* ... */ }
            // or
int main(int argc, char **argv) { /* ... */ }
```

### Example

Execute the following snippet:

```C
int main(int argc, char *argv[])
{
    printf("argc: %d\n", argc);
    for (int i = 0; i <= argc; i++)
    {
        printf("#%d %p", i, argv[i], argv[i]);
        if (argv[i] != NULL)
        {
            printf(" %s\n", argv[i]);
        }
        else
        {
            printf("\n");
        }
    }
    return EXIT_SUCCESS;
}
```

Observations:

- You can easily notice from the following code snippet that `argv[argc]` is always a `NULL` pointer.
- `argv[0]` holds the program name.
- `argv[`*n*`]` holds whatever arguments passed at *n*.
- It is quite obvious that you can use `argv[argc - 1]` to get the last argument entered.

Another way to access command line arguments would be using a [pointer to a pointer](https://www.tutorialspoint.com/cprogramming/c_pointer_to_pointer.htm).

```C
int main(int argc, char *argv[])
{
    // This is a pointer to a pointer
    char **arg = &argv[0];
    while (*arg)
    {
        puts(*arg);
        arg++;
    }

    return EXIT_SUCCESS;
}
```

You pass all the command line arguments separated by a space, but if argument itself has a space then you can pass such arguments by putting them inside double quotes `" "` or single quotes `' '`.

## Two-dimensional Arrays

A two-dimensional array is, in essence, a list of one-dimensional arrays.

```C
type arrayName [ x ][ y ];
```

Where type can be any valid C data type.

![Two Dimensional Arrays Representation](https://www.tutorialspoint.com/cprogramming/images/two_dimensional_arrays.jpg)

Initializing an array:

```C
int a[3][4] = {  
   {0, 1, 2, 3} ,   /*  initializers for row indexed by 0 */
   {4, 5, 6, 7} ,   /*  initializers for row indexed by 1 */
   {8, 9, 10, 11}   /*  initializers for row indexed by 2 */
};
```

Note that the nested braces are optional, we can alternatively use:

```C
int a[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
```

Hence we can use subscripts to access an individual element of an array:

```C
int val = a[2][3];
```

When we use pointers to access array elements in two-dimensional arrays we use the following formula to access using a single pointer:

### Example of passing to functions

```C
void print_matrix(int *numbers, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        printf("%d", numbers[i * cols + 0]);
        for (int j = 1; j < cols; j++)
        {
            printf(" %d", numbers[i * cols + j]);
        }
        putchar('\n');
    }
}

int main()
{
    int numbers1[3][4] = {{1, 2, 3, 4},
                          {2, 4, 3, 1},
                          {3, 1, 4, 2}};

    print_matrix(&numbers1[0][0], 3, 4);

    return EXIT_SUCCESS;
}
```

Notice `numbers[i * cols + j]` when accessing elements in this array (we can call it matrix), an alternative approach would be like this:

```C
void print_array(int *numbers, int length)
{
    printf("%d", numbers[0]);
    for (int i = 1; i < length; i++)
    {
        printf(" %d", numbers[i]);
    }
    putchar('\n');
}

void print_matrix(int *numbers, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        print_array(numbers + (i * cols), cols);
    }
}
```

Notice again `(numbers + (i * cols))` which passes a pointer as we know.

We can also typecast `numbers1` pointer in the previous `main` function and pass it like this `print_matrix((int *)numbers1, 3, 4);`

Alternatively we can also use:
*Note: this approach works if the compiler is C99 compatible.*

```C
// The following program works only if your compiler is C99 compatible.
#include <stdio.h>

// n must be passed before the 2D array
void print(int m, int n, int arr[][n])
{
    int i, j;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            printf("%d ", arr[i][j]);
    printf("\n");
}

int main()
{
    int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int m = 3, n = 3;
    print(m, n, arr);
    return 0;
}
```

There are many other ways that you can read about [here](https://www.geeksforgeeks.org/pass-2d-array-parameter-c/).


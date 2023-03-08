# High Level Programming Languages 1 — Lab 04 Overview

## Arrays

Generally speaking we can define arrays in the following way *based on [Data Structures and Algorithms course](https://bakhomious.notion.site/Data-Structures-and-Algorithms-6cb7d1da236c4091bca28bdcf3168f88)*:

- Consists of a fixed number of elements, each identified by a sequence of integers.
- One dimensional array is called **vector**, and its elements are identified by "index"
- Two dimensional array is called **matrix,** and its elements are identified by two integers. (Row major and Column major order)

- **Array Properties**
  - Solid *(Homogneous)*
  - Associative
  - Static *(Fixed-Size)*
  - Continuously represented

<p align="center">
  <img src="https://www.tutorialspoint.com/cprogramming/images/arrays.jpg" />
</p>


### Declarying Arrays

```C
// type arrayName [ arraySize ];
int numbers[10];
```

### Initializing Arrays

Just as the other data types we can initialize the array

```C
int numbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
```

If we omitted the `arraySize`, an array just big enough to hold the initialization is created

```C
int numbers[] = {1, 2, 3, 4, 5};    // Size of 5
```

### Accessing an element

Given the following code snippet:

```C
int numbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int size = sizeof(numbers) / sizeof(int);

for(int i = 0; i < size; i++)
    printf("%d %p\n", numbers[i], &numbers[i]);
```

This will produce the following output

```bash
1 0x7fff46226220
2 0x7fff46226224
3 0x7fff46226228
4 0x7fff4622622c
5 0x7fff46226230
6 0x7fff46226234
7 0x7fff46226238
8 0x7fff4622623c
9 0x7fff46226240
10 0x7fff46226244
```

Here is how we can explain this code snippet:

- `sizeof(numbers)` would return the value of `40`, the reason for this is that it returns the size of the used memory by the array. i.e. an `int` is `4 bytes`, the array consists of `10` elements, therefore $4 \times 10 = 40$. That's why we divide by `sizeof(int)`.
- In `printf()`, you can notice we used `%p` and `&numbers[i]`.
  - `%p` is a special place holder for memory addresses.
  - `&numbers[i]` is a reference to the memory address.

Using `%d` for printing memory addresses would result in a very strange phenomenon. See the code result below:

```bash
1  985067376
2  985067380
3  985067384
4  985067388
5  985067392
6  985067396
7  985067400
8  985067404
9  985067408
10 985067412
```

This is the integer value representation of the variable which is only the lower **32 bits** of the **64 bit** value. It might be negative sometimes because it is [signed](https://www.ibm.com/docs/en/aix/7.2?topic=types-signed-unsigned-integers). As a pointer representation (since it's an address and sign doesn't matter) it is unsigned hex value and looks positive, though both are the same value in memory (At least the 32 bits that are equal). This is happening because of different width of variable and something called [Two's complement](https://www.cs.cornell.edu/~tomf/notes/cps104/twoscomp.html).

This explaination will lead us to introduce a very important concept in C programming.

---

## Pointers

Every variable is a memory location and every memory location has its address defined which can be accessed using ampersand (`&`) operator, which denotes an address in memory, check the previous [example](#accessing-an-element).

A pointer is a variable whose value is the address of another variable, i.e., direct address of the memory location. Like any variable or constant, you must declare a pointer before using it to store any variable address.

### Example:

```C
#include <stdio.h>

int main () {

   int x = 20;   // actual variable declaration
   int *p;      // pointer variable declaration

   p = &x;    // store address of var in pointer variable

   printf("Address of x variable: %x\n", &x);

   // address stored in pointer variable
   printf("Address stored in p variable: %x\n", p);

   // access the value using the pointer
   printf("Value of *p variable: %d\n", *p);

   return 0;
}
```

This compiles to produce the following

```text
Address of x variable: e24494fc
Address stored in p variable: e24494fc
Value of *p variable: 20
```

### `NULL` Pointers

A pointer that is assigned NULL is called a null pointer.

The NULL pointer is a constant with a value of zero defined in several standard libraries.

---

## Pointer to an Array

```C
double numbers[50];
```

`numbers` is a pointer to `&numbers[0]`, which is the address of the first element of the array balance.

It is legal to use array names as constant pointers, and vice versa. Therefore, `*(numbers + 4)` is a legitimate way of accessing the data at `numbers[4]`.

Once you store the address of the first element in a pointer `p` for example, you can access the array elements using `*p`, `*(p+1)`, `*(p+2)` and so on.

### Example:

```C
#include <stdio.h>

int main () {

   /* an array with 5 elements */
   double balance[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
   double *p;
   int i;

   p = balance;
 
   /* output each array element's value */
   printf( "Array values using pointer\n");
	
   for ( i = 0; i < 5; i++ ) {
      printf("*(p + %d) : %f\n",  i, *(p + i));
   }

   printf( "Array values using balance as address\n");
	
   for ( i = 0; i < 5; i++ ) {
      printf("*(balance + %d) : %f\n",  i, *(balance + i));
   }
 
   return 0;
}
```

This would produce

```text
Array values using pointer
*(p + 0) : 1000.000000
*(p + 1) : 2.000000
*(p + 2) : 3.400000
*(p + 3) : 17.000000
*(p + 4) : 50.000000

Array values using balance as address
*(balance + 0) : 1000.000000
*(balance + 1) : 2.000000
*(balance + 2) : 3.400000
*(balance + 3) : 17.000000
*(balance + 4) : 50.000000
```

---

## Passing Arrays as Function Arguments

There are three ways to pass the array to a function

### Using a Pointer

```C
void myFunction(int *param) {}
```

### A Sized Array

```C
void myFunction(int param[10]) {}
```

### Unsized Array

```C
void myFunction(int param[]) {}
```

### Example:

```C
#include <stdio.h>

double getAverage(int arr[], int size) {

   int i;
   double avg;
   double sum = 0;

   for (i = 0; i < size; i++) {
      sum += arr[i];
   }

   avg = sum / size;

   return avg;
}

int main () {

   /* an int array with 5 elements */
   int balance[5] = {1000, 2, 3, 17, 50};
   double avg;

   /* pass pointer to the array as an argument */
   avg = getAverage(balance, 5);
 
   /* output the returned value */
   printf("Average value is: %f ", avg);
    
   return 0;
}
```

---

## Return array from function

C programming language does not allow you to return an array from a function, however you can return a pointer to an array.

```C
int * myFunction() {}
```

### Example:

```C
#include <stdio.h>

int * assignValues() {

    static int tens[10];    

    for(int i = 0; i < 10; i++) {
        tens[i] = i * 10;
    }

    return tens;
}

int main () {

    int *p; // a pointer to an int

    p = assignValues();
	
    for (int i = 0; i < 10; i++) {
        printf("*(p + %d) : %d\n", i, *(p + i));
    }

    return 0;
}
```

C does not advocate to return the address of a local variable to outside of the function, so you would have to define the local variable as a [`static`](https://www.geeksforgeeks.org/static-variables-in-c/) variable.

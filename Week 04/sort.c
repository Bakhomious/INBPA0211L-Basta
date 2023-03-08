#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
A procedure that generates random numbers.
a[]  : an array
size : size of array
limit: upper bound of the generated numbers
*/
void generate(int a[], int size, int limit) {

    srand ((unsigned) time (NULL));  // pass the srand() parameter

    // generate random number between 0 to limit and assign to array
    for (int i = 0; i < size; i++)
        a[i] = rand() % limit + 1;

}


void display(int a[], int size){

    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");

}

void swap(int a[], int i, int j) {

    int tmp;
    tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;

}

void bubble_sort(int a[], int size) {

    for(int i = size - 1; i > 0; i--)
        for (int j = 0; j < i; j++)
            if(a[j] > a[j + 1])
                swap(a, j, j + 1);

}

int main() {

    int size, limit;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the upper bound for the random numbers: ");
    scanf("%d", &limit);

    int a[size];

    generate(a, size, limit);

    printf("Unsorted Array: \n");
    display(a, size);

    bubble_sort(a, size);

    printf("Sorted Array: \n");
    display(a, size);

    return EXIT_SUCCESS;
}
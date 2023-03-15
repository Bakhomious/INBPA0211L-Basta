/*
Implementing exercises in the same program using functions. 
Exercises in order of appearance: P104101-n, P104104-n, P104106-n and P104108-n 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Exercise    : P104101-n
Input file  : odd.txt
*/
int count_of_odds(int *numbers, int length) {
    
    int count = 0;
    for(int i = 0; i < length; i++)
        if(numbers[i] % 2 != 0)
            count++; 

    return count;

}

/*
Exercise    : P104104-n
Input file  : squares.txt
*/
int count_of_squares(int *numbers, int length) {

    int count = 0;
    
    for(int i = 0; i < length; i++)
        for(int j = 0; j <= sqrt(numbers[i]); j++)
            if(numbers[i] == j * j)
                count++;
    
    return count;

}

/*
Exercise    : P104106-n
Input file  : negatives.txt
*/

int count_of_negatives(int *numbers, int length) {

    int count = 0;

    for (int i = 0; i < length; i++)
        if(numbers[i] < 0)
            count++;
    
    return count;
}

/*
Exercise    : P104108-n
Input file  : localmin.txt
*/
int count_of_local_minimums(int* numbers, int length) {

    int count = 0;

    for(int i = 1; i < length - 1; i++)
        if( (numbers[i] < numbers[i + 1]) && (numbers[i] < numbers[i - 1]) )
            count++;

    return count;
}

int main() {

    int cases, length;

    scanf("%d", &cases);

    for(int i = 0; i < cases; i++) {

        scanf("%d", &length);
        int numbers[length];
        for(int j = 0; j < length; j++) {
            scanf("%d", &numbers[j]);
        }
        
        // printf("%d\n", count_of_odds(numbers, length));
        // printf("%d\n", count_of_squares(numbers, length));
        // printf("%d\n", count_of_negatives(numbers, length));
        printf("%d\n", count_of_local_minimums(numbers, length));
    }

    return EXIT_SUCCESS;
}

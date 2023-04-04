#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    
    int max = INT_MIN;
    for (int i = 1; i < argc; i++) {
        int number = atoi(argv[i]);
        if (number > max) {
            max = number;
        }
    }
    printf("%d\n", max);

    return EXIT_SUCCESS;
}
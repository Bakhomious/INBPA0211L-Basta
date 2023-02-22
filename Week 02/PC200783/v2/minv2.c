#include <stdio.h>
#include <limits.h>

int main() {

    int num = 0, min = INT_MAX;

    while ((scanf("%d", &num)) != EOF) {

        if (num < min)
            min = num;
    }

    printf("%d\n", min);

    return 0;

}
#include <stdio.h>
#include <limits.h>

int main() {

    int num = 0, max = INT_MIN;

    while ((scanf("%d", &num)) != EOF) {

        if (num > max)
            max = num;
    }

    printf("%d\n", max);

    return 0;

}
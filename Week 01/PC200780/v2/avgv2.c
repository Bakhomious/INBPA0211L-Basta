#include <stdio.h>

int main () {

    int n = 0, num = 0;
    double sum = 0.0;

    while ((scanf("%d", &num)) != EOF) {

        sum += num;
        n++;
    }

    printf("%.2lf \n", sum/n);
    return 0;
}
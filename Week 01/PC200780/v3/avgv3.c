#include <stdio.h>

int main () {

    int n = 0, num = 0;
    double sum = 0.0;

    while ((scanf("%d", &num)) != EOF) {

        if (num != 0) {
            sum += num;
            n++;
        }

    }

    printf("%.2lf \n", sum/n);
    return 0;
}
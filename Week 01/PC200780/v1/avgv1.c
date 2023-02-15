#include <stdio.h>

int main () {

    int n = 0, num = 0;
    double sum = 0.0;

    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        sum += num;
    }

    printf("%.2lf \n", sum/n);
    return 0;
}
#include <stdio.h>
#include <math.h>

int main () {
    int n, i, flag = 0;

    scanf("%d", &n);

    // Exclude 0, 1

    if (n < 2)
        flag = 1;

    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        printf("YES\n");
    } else
        printf("NO\n");
}

#include <stdio.h>
#include <limits.h>

int main() {

    int n = 0, num = 0, max = INT_MIN;
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {

        scanf("%d", &num);

        if (num > max)
            max = num;
    }

    printf("%d\n", max);

    return 0;

}
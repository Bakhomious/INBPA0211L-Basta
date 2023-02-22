#include <stdio.h>
#include <limits.h>

int main() {

    int n = 0, num = 0, min = INT_MAX;
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {

        scanf("%d", &num);

        if (num < min)
            min = num;
    }

    printf("%d\n", min);

    return 0;

}
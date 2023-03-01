#include <stdio.h>

int echo(int n) { return n; }

int main() {

    int n = 0;

    for (int i = 0; i < 10; i++) {

        scanf("%d", &n);

        if (n == 999)
            break;
        else
            printf("%d\n",echo(n));
    }

    return 0;
}
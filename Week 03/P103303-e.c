#include <stdio.h>

int n_fibonacci(int n) {

    if (n <= 1)
        return 1;
    return (n_fibonacci(n - 1) + n_fibonacci(n - 2));
}

int main() {
    
    int number;

    while(scanf("%d", &number) != EOF) {
        printf("%d\n", n_fibonacci(number));
    }

    return 0;
}
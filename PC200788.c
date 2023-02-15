#include <stdio.h>

int main() {

    int a, b;

    scanf("%d %d", &a, &b);

    while (a != b)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    
    if (a == 1)
        printf("IGEN\n");
    else
        printf("NEM\n");

    return 0;
}



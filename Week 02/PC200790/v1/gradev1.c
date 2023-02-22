#include <stdio.h>

int main() {

    int n = 0, score = 0;

    scanf("%d", &n);

    if (n < 0 || n > 100)
        printf("Invalid number of students");

    for(int i = 0; i < n; i++) {

        scanf("%d", &score);

        if (score >= 80)
            printf("Excellent\n");
        else if (score >= 70)
            printf("Good\n");
        else if (score >= 60)
            printf("Satisfactory\n");
        else if (score >= 50)
            printf("Pass\n");
        else
            printf("Fail\n");
    }

    return 0;

}
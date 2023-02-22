#include <stdio.h>

int main() {

    int score = 0;


    while((scanf("%d", &score)) != EOF) {

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
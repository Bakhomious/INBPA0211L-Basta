#include <stdio.h>

#define _USE_MATH_DEFINES
#include <math.h>

float circle_area (float r) { return (M_PI * r * r); }

int main() {

    int n = 0;
    scanf("%d", &n);

    float r = 0;

    for (int i = 0; i < n; i++) {
        scanf("%f", &r);

        printf("%f\n", circle_area(r));
    }


    return 0;
}
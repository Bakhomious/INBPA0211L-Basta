#include <stdio.h>
#include <math.h>

float pythagorean(float a, float b) { return sqrt((a * a) + (b * b)); }

int main() {
    
    float a, b;

    while(scanf("%f %f", &a, &b) != EOF) {
        printf("%f\n", pythagorean(a,b));
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int foo(int *array, int rows, int cols) {

    if (rows != cols)
        return 0;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (array[i * cols + j] != array[j * cols + i]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {

    int m[3][3] = {{1, 2, 3},
                   {2, 3, 1},
                   {3, 1, 2}};
    if (foo(&m[0][0], 3, 3))
        puts("YES");
    else
        puts("NO");
    return EXIT_SUCCESS;
}
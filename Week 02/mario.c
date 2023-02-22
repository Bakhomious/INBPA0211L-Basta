#include <stdio.h>

int main(void)
{
    int height = 0;
    scanf("%d", &height);

    // Row counter, mother loop
    for (int row = 0; row < height; row ++)
    {
        // Space counter
        for (int spaces = height - row - 1; spaces > 0; spaces--)
        {
            printf(" ");
        }
        // Hash counter
        for (int hash = row + 1; hash > 0; hash--)
        {
            printf("#");
        }
        // Two spaces
        printf("  ");
        // Right side counter
        for (int hash_r = row + 1; hash_r > 0; hash_r--)
        {
            printf("#");
        }
        printf("\n");
    }

}
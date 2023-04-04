#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int count = 1;
    for (int i = 2; i < argc; i++)
    {
        if (strcmp(argv[i], argv[1]) == 0)
        {
            count += 1;
        }
    }
    printf("%d\n", count);

    return EXIT_SUCCESS;
}
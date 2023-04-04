#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int min_length = strlen(argv[1]);
    for (int i = 1; i < argc; i++)
    {
        if (strlen(argv[i]) < min_length)
        {
            min_length = strlen(argv[i]);
        }
    }

    for (int i = 1; i < argc; i++)
    {
        if (strlen(argv[i]) == min_length)
        {
            puts(argv[i]);
        }
    }

    return EXIT_SUCCESS;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *decrement_lowers(char *original)
{

    char *result = (char *)calloc(strlen(original) + 1, sizeof(char));

    for (int i = 0; i < strlen(original) + 1; i++)
    {
        if (islower(original[i]))
        { 
        /*
        Refer to ASCII table. Let original[i] = 'a', where 'a' in ASCII = 97;
        The following formula would be = (97 - 97 - 1 + 26) % 26 + 97 = 122;
        'z' is ASCII is 122;
        Notice that 26 is the number of alphabets, we get the position of the letter relating to the alphabets then get its corresponding ASCII.
         */
            result[i] = (original[i] - 'a' - 1 + 26) % 26 + 'a';
        }
        else
            result[i] = original[i];
    }
    return result;
}

int main()
{
    char line[101];

    int n;
    fgets(line, sizeof(line), stdin);
    n = atoi(line);

    for (int i = 0; i < n + 1; i++)
    {
        gets(line);
        char *result = decrement_lowers(line);
        puts(result);
        free(result);
    }

    return EXIT_SUCCESS;
}
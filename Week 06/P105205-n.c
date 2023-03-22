#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *double_vowels(char *original)
{
    // Allocate double size (worst case scenario).
    char *result = (char *)calloc(strlen(original) * 2 + 1, sizeof(char));

    
    /*
    // Counting vowels.
    int count_vowels = 0;

    for(int i = 0; i < strlen(original) + 1; i++) {
        if(strchr("aeiou", tolower(original[i])))
            count_vowels++;
    }
    
    char *result = (char *)calloc(strlen(original) + 1 + count_vowels, sizeof(char));
    */

    int j = 0;
    for (int i = 0; i < strlen(original) + 1; i++)
    {
        if (strchr("aeiou", tolower(original[i])))
        {
            result[j] = original[i];
            j++;
        }
        result[j] = original[i];
        j++;
    }
    return result;
}

int main()
{
    char line[101];

    int n;
    fgets(line, sizeof(line), stdin);
    n = atoi(line);

    for (int i = 0; i < n; i++)
    {
        gets(line);
        char *result = double_vowels(line);
        puts(result);
        free(result);
    }

    return EXIT_SUCCESS;
}
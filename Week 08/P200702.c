#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LENGTH 11

int are_same(char *left, char *right)
{
    /*
    if (strlen(left) != strlen(right))
    {
        return 0;
    }

    for (int i = 0; i < strlen(left); i++)
    {
        if (tolower(left[i]) != tolower(right[i]))
        {
            return 0;
        }
    }
    */

    for (int i = 0; i < strlen(left); i++)
    {
        if (tolower(left[i]) != tolower(right[i]))
        {
            return 0;
        }
    }

    return 1;
}

int foo(char *words[], int rows, int cols)
{
    /*
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (!are_same(words[0], words[i * cols + j]))
            {
                return 0;
            }
        }
    }
    */

    for (int i = 1; i < rows * cols; i++)
    {
        if (!are_same(words[0], words[i]))
        {
            return 0;
        }
    }

    return 1;
}

char **read_words(int rows, int cols)
{
    char **words = (char **)calloc(rows * cols, sizeof(char *));
    /*
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            words[i * cols + j] = (char *)calloc(LENGTH, sizeof(char));
            scanf("%s", words[i * cols + j]);
        }
    }
    */

    for (int i = 0; i < rows * cols; i++)
    {
        words[i] = (char *)calloc(LENGTH, sizeof(char));
        scanf("%s", words[i]);
    }
    return words;
}

int main()
{
    int rows, cols;
    scanf("%d %d", &rows, &cols);

    char **words = read_words(rows, cols);
    puts(foo(words, rows, cols) ? "YES" : "NO");

    for (int i = 0; i < rows * cols; i++)
    {
        free(words[i]);
    }
    free(words);

    return EXIT_SUCCESS;
}
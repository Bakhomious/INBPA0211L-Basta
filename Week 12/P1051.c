/**
 * @file P1051.c
 * @author Tóth Róbert
 * @brief A code for all the strings exercise in one file. Try to understand it, it's nice to have :)
 * @date 2023-05-02
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *delete_spaces(char *original)
{
    char *result = (char *)calloc(strlen(original) + 1, sizeof(char));
    int pos = 0;
    for (int i = 0; i <= strlen(original); i++)
    {
        if (original[i] != ' ')
        {
            result[pos] = original[i];
            pos++;
        }
    }
    return result;
}

char *delete_lowers(char *original)
{
    char *result = (char *)calloc(strlen(original) + 1, sizeof(char));
    int pos = 0;
    for (int i = 0; i <= strlen(original); i++)
    {
        if (!islower(original[i]))
        {
            result[pos] = original[i];
            pos++;
        }
    }
    return result;
}

char *delete_uppers(char *original)
{
    char *result = (char *)calloc(strlen(original) + 1, sizeof(char));
    int pos = 0;
    for (int i = 0; i <= strlen(original); i++)
    {
        if (!isupper(original[i]))
        {
            result[pos] = original[i];
            pos++;
        }
    }
    return result;
}

char *delete_digits(char *original)
{
    char *result = (char *)calloc(strlen(original) + 1, sizeof(char));
    int pos = 0;
    for (int i = 0; i <= strlen(original); i++)
    {
        if (!isdigit(original[i]))
        {
            result[pos] = original[i];
            pos++;
        }
    }
    return result;
}

char *delete_vowels(char *original)
{
    char *result = (char *)calloc(strlen(original) + 1, sizeof(char));
    int pos = 0;
    for (int i = 0; i <= strlen(original); i++)
    {
        if (!strchr("aeiou", tolower(original[i])))
        {
            result[pos] = original[i];
            pos++;
        }
    }
    return result;
}

char *delete_consonants(char *original)
{
    char *result = (char *)calloc(strlen(original) + 1, sizeof(char));
    int pos = 0;
    for (int i = 0; i <= strlen(original); i++)
    {
        if (!strchr("bcdfghjklmnpqrstvwxyz", tolower(original[i])))
        {
            result[pos] = original[i];
            pos++;
        }
    }
    return result;
}

char *delete_even_digits(char *original)
{
    char *result = (char *)calloc(strlen(original) + 1, sizeof(char));
    int pos = 0;
    for (int i = 0; i <= strlen(original); i++)
    {
        if (!(isdigit(original[i]) && original[i] - '0' % 2 == 0))
        {
            result[pos] = original[i];
            pos++;
        }
    }
    return result;
}

char *delete_odd_digits(char *original)
{
    char *result = (char *)calloc(strlen(original) + 1, sizeof(char));
    int pos = 0;
    for (int i = 0; i <= strlen(original); i++)
    {
        if (!(isdigit(original[i]) && original[i] - '1' % 2 == 0))
        {
            result[pos] = original[i];
            pos++;
        }
    }
    return result;
}

char *(*functions[])(char *) = {delete_spaces,
                                delete_lowers,
                                delete_uppers,
                                delete_digits,
                                delete_vowels,
                                delete_consonants,
                                delete_even_digits,
                                delete_odd_digits};

int main(int argc, char *argv[])
{
    char line[32];
    if (argc == 1)
    {
        fprintf(stderr, "Missing exercise_id\n");
    }
    char *exercise_id = argv[1];
    char input_type = exercise_id[strlen(exercise_id) - 1];
    exercise_id[strlen(exercise_id) - 1] = '\0';
    int exercise_number = (atoi(exercise_id + 1) % 100) - 1;

    if (input_type == 'n')
    {
        int n = atoi(gets(line));
        for (int i = 0; i < n; i++)
        {
            gets(line);
            char *result = functions[exercise_number](line);
            puts(result);
            free(result);
        }
    }
    else if (input_type == 't')
    {
        while (gets(line))
        {
            if (strcmp(line, "END") == 0)
            {
                break;
            }
            char *result = functions[exercise_number](line);
            puts(result);
            free(result);
        }
    }
    else if (input_type == 'e')
    {
        while (gets(line))
        {
            char *result = functions[exercise_number](line);
            puts(result);
            free(result);
        }
    }

    return EXIT_SUCCESS;
}
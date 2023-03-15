#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char s[50];
    printf("Input a string: ");

    fgets(s, sizeof(s), stdin);

    int i, digits = 0, letters = 0, punct = 0, spaces = 0, others = 0;
    for (i = 0; i < strlen(s) - 1; i++)
        if (isdigit(s[i]))
            digits++;
        else if (isalpha(s[i]))
            letters++;
        else if (ispunct(s[i]))
            punct++;
        else if (isspace(s[i]))
            spaces++;
        else
            others++;

    printf("Digits = %d\nLetters = %d\nPunctuation = %d\nSpaces = %d\nOther Charcaters = %d\n", digits, letters, punct, spaces, others);
    return 0;
}

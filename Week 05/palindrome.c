#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
Function that takes a string and reverses it.
*/
void reverse_string(char *s)
{

    int i, j;
    char c;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/*
Transforms the string to lower case to be able to compare it case-insensitve
*/
void string_tolower(char *s)
{
    for (int i = 0; i < strlen(s); i++)
        s[i] = tolower(s[i]);
}


int main()
{
    char s[50], o[50];

    printf("Input a word: ");
    scanf("%s", s);

    string_tolower(s);
    strcpy(o, s);
    reverse_string(o);

    if (strcmp(o, s) == 0)
        printf("Palindrome!\n");
    else
        printf("Not Palindrome\n");

    return 0;
}

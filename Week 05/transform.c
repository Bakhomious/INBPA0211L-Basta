#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
The function transforms lower-case letters to upper-case and vice versa.
*/
void transform(char string[])
{

    for (int i = 0; i < strlen(string); i++)
    {
        if (isupper(string[i]))
            string[i] = tolower(string[i]);
        else if (islower(string[i]))
            string[i] = toupper(string[i]);
    }
}

int main()
{
    char string[50];
    printf("Input a string: ");

    // scanf("%s", string);
    fgets(string, sizeof(string), stdin);

    transform(string);

    printf("%s", string);

    return 0;
}

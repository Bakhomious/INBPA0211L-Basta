#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *delete_spaces (char *original) {
    char *result = (char *) calloc(strlen(original) + 1, sizeof(char)); //fills with zeros
    // char *result = malloc(strlen(original) + 1 * sizeof(char));

    int j = 0;
    for (int i = 0; i < strlen(original) + 1; i++) {
        if(original[i] != ' ') {
            result[j] = original[i];
            j++;
        }
    }
    return result;
}


int main()
{
    char line[101];

    while(1) {
        gets(line);
        if (strcmp(line, "") == 0) break;
        char *result = delete_spaces(line);
        puts(result);
        free(result);
    }

    return EXIT_SUCCESS;
}
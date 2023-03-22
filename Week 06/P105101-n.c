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

    int n;
    fgets(line, sizeof(line), stdin);
    n = atoi(line);
    
    for(int i = 0; i < n + 1; i++){
        gets(line);
        char *result = delete_spaces(line);
        puts(result);
        free(result);
    }

    return EXIT_SUCCESS;
}
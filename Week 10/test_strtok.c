/**
 * @file test_strtok.c
 * @author Robert Toth
 * @brief This code is purely for demonstration purposes about strtok() function and memory dumbing when defining strings.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dump_memory(char *s, int length) {
    for(int i=0; i<length; i++) {
        printf("#%d *%c* %d %p\n", i, s[i], s[i], &s[i]);
    }
}

int main() {
    char line[101];

    gets(line);
    puts(line);
    dump_memory(line, 15);

    puts("=====");

    char *first = strtok(line, ";");
    dump_memory(line, 15);

    puts(first);

    char *second = strtok(NULL, ";");
    dump_memory(line, 15);

    puts(second);

    char *third = strtok(NULL, ";");
    dump_memory(line, 15);

    puts(third);

    char *fourth = strtok(NULL, ";");
    dump_memory(line, 15);

    puts(fourth);

    printf("%p\n", strtok(NULL, ";"));

    return EXIT_SUCCESS;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Roller_Coaster {
    char name[31];
    char world[31];
    int height;
    int time;
} ROLLER_COASTER; 

int cmp(const void *a, const void *b) {
    ROLLER_COASTER *left = (ROLLER_COASTER *)a;
    ROLLER_COASTER *right = (ROLLER_COASTER *)b;

    // Waiting time ascending

    if (left -> time != right -> time) {
        return (left -> time - right -> time);
    }
    
    if (left -> height != right -> height) {
        return -(left -> height - right -> height);
    }

    return strcmp(left->name, right->name);
}

void print_array(ROLLER_COASTER *rollers, int n) {
    for (int i= 0; i < n; i++) {
        printf("%s (%s): %d\n", rollers[i].name,
        rollers[i].world, rollers[i].time);
    }
}

int main() {
    
    char line[101];
    gets(line);
    int n = atoi(line);
    ROLLER_COASTER rollers[n];

    for (int i = 0; i < n; i++) {
        gets(line);
        char *name = strtok(line, ";");
        char *world = strtok(NULL, ";");
        char *height = strtok(NULL, ";");
        char *time = strtok(NULL, ";");

        strcpy(rollers[i].name, name);
        strcpy(rollers[i].world, world);
        rollers[i].height = atoi(height);
        rollers[i].time = atoi(time);
    }
    qsort(rollers, n, sizeof(ROLLER_COASTER), cmp);

    print_array(rollers, n);

    return EXIT_SUCCESS;
}
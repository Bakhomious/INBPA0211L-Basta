#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Airports
{
    char name[31];
    char city[31];
    int runways;
    int time;
} AIRPORT;

void print_array(AIRPORT *airports)
{
    for (int i = 0; i < sizeof(airports); i++)
    {
        printf("%s (%s): %d\n", airports[i].name,
            airports[i].city, airports[i].time);
    }
}

int cmp(const void *a, const void *b)
{
    AIRPORT *left = (AIRPORT *)a;
    AIRPORT *right = (AIRPORT *)b;

    // Number of runways in descending order
    if (left->runways != right->runways)
    {
        return -(left->runways - right->runways);
    }

    // Transfer time in descending order
    if (left->time != right->time)
    {
        return -(left->time - right->time);
    }

    // Name in ascending order
    return strcmp(left->name, right->name);
}

int main()
{

    char line[101];

    gets(line);
    int n = atoi(line);
    AIRPORT airports[n];

    for (int i = 0; i < n; i++)
    {
        gets(line);
        char *name = strtok(line, ";");
        char *city = strtok(NULL, ";");
        char *runways = strtok(NULL, ";");
        char *time = strtok(NULL, ";");

        strcpy(airports[i].name, name);
        strcpy(airports[i].city, city);
        airports[i].runways = atoi(runways);
        airports[i].time = atoi(time);
    }
    printf("Before Sort: \n");
    print_array(airports);

    qsort(airports, n, sizeof(AIRPORT), cmp);
    
    printf("======= \nAfter Sort: \n");
    print_array(airports);

    return EXIT_SUCCESS;
}

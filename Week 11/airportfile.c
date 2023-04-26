#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[31];
    char city[31];
    int runways;
    int time;
} AIRPORT;

void print_array(AIRPORT *airports, int n)
{
    for (int i = 0; i < n; i++)
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

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "No input file provided.\n");
        return 1;
    }

    FILE *fin = fopen(argv[1], "r");
    if (!fin)
    {
        fprintf(stderr, "Input file does not exist.\n");
        return 2;
    }
    
    char line[101];
    AIRPORT airports[20];
    int counter = 0;

    while(fgets(line, sizeof(line), fin))
    {
        strcpy(airports[counter].name, strtok(line, ";"));
        strcpy(airports[counter].city, strtok(NULL, ";"));
        airports[counter].runways = atoi(strtok(NULL, ";"));
        airports[counter].time = atoi(strtok(NULL, ";"));
        counter++;
    }

    fclose(fin);

    qsort(airports, counter, sizeof(AIRPORT), cmp);

    if (argc < 3)
    {
        fprintf(stderr, "No output file provided.\n");
        return 3;
    }
    
    FILE *fout = fopen(argv[2], "w");
    if (!fout)
    {
        fprintf(stderr, "Output file cannot be opened.\n");
        return 4;
    }
    
    for (int i = 0; i < counter; i++)
    {
        fprintf(fout, "%s (%s): %d\n", airports[i].name,
            airports[i].city, airports[i].time);
    }
    fclose(fout);

    return EXIT_SUCCESS;
}

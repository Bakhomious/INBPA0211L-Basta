#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct NODE
{
    int value;
    struct NODE *next;
} NODE;

NODE *create_list(int value)
{
    NODE *node = (NODE *)calloc(1, sizeof(NODE));
    node->value = value;
    return node;
}

void insert_node(NODE *head, int value)
{
    if (head->next)
    {
        insert_node(head->next, value);
    }
    else
    {
        head->next = (NODE *)calloc(1, sizeof(NODE));
        head->next->value = value;
    }
}

int get_node(NODE *head, int key)
{
    return key == 0 ? head->value : get_node(head->next, key - 1);
}

void clear_list(NODE *head)
{
    if (head->next)
    {
        clear_list(head->next);
    }

    free(head);
}

int list_size(NODE *head)
{
    return head == NULL ? 0 : 1 + list_size(head->next);
}

void print_list(NODE *head)
{
    if (!head)
    {
        puts("empty list");
    }
    else if (!head->next)
    {
        printf("%d\n", head->value);
    }
    else
    {
        printf("%d ", head->value);
        print_list(head->next);
    }
}


int main()
{
    NODE *list = NULL;

    char line[101];
    while(gets(line))
    {
        char *command = strtok(line, " ");
        
        if(strcmp(command, "create") == 0)
        {
            if(list)
            {
                clear_list(list);
            }

            list = create_list(atoi(strtok(NULL, " ")));
        }
        else if (!list)
        {
            fprintf(stderr, "A list does not exist\n");
        }
        else if (strcmp(command, "insert") == 0)
        {
            insert_node(list, atoi(strtok(NULL, " ")));
        }
        else if (strcmp(command, "get") == 0)
        {
            printf("%d\n", get_node(list, atoi(strtok(NULL, " "))));
        }
        else if (strcmp(command, "print") == 0)
        {
            print_list(list);
        }
        else if (strcmp(command, "clear") == 0)
        {
            clear_list(list);
            list = NULL;
        } else if (strcmp(command, "size") == 0)
        {
            printf("Size of the list: %d\n", list_size(list));
        }
    }

    if (list)
    {
        clear_list(list);
    }

    return 0;
}
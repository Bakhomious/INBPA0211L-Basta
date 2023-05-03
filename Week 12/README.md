# High Level Programming Languages 1 — Lab 12 Overview

## Linked Lists

![Linked List Visual Representation](https://www.tutorialspoint.com/data_structures_algorithms/images/singly_linked_lists.jpg)

A linked list is a linear data structure, in which the elements are not stored at contiguous memory locations. The elements in a linked list are linked using pointers.


### Representation

**Each element contain:**

- **Value**
- **Pointer** - stores a memory address of another element.

**Head -** points to the first element of the list.
Head = `NULL`, list is empty

### Basic Operations

- $\text{LIST-INSERT}$ &mdash; Adds an element
- $\text{LIST-DELETE}$ &mdash; Deletes an element 
- $\text{LIST-SEARCH}$ &mdash; Searches using a given key

## Linked Lists &mdash; Implementation in C

First we need to define something to hold a $\text{NODE}$, the candidate for this implementation is a `struct`. We will have to use memory management techniques to dynamically allocate enough memory for the list and lots of recursive functions. 

```C
typedef struct NODE
{
    int value;
    struct NODE *next;
} NODE;
```

The first operation we do is $\text{CREATE}$ the list.

```C
NODE *create_list(int value)
{
    NODE *node = (NODE *)calloc(1, sizeof(NODE));
    node->value = value;
    return node;
}
```

This is pretty straight forward, we allocate the memory for a $\text{NODE}$ and access its value and assign the passed value.

Next operation is $\text{INSERT}$

```C
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
```

It starts to get a little tricky from here, first of all we check if `head->next` isn't `NULL`. The if condition won't break unless it gets a NULL, inside it we keep recursively calling the function so we can reach the `else` branch. Which then adds the $\text{NODE}$ to the end of the list. We allocate the memory for the $\text{NEXT NODE}$ and assign the passed value to it, i.e `head->next->value`.

Next operation would be $\text{SEARCH}$, we will call it `get_node` for simplicity.

```C
int get_node(NODE *head, int key)
{
    return key == 0 ? head->value : get_node(head->next, key - 1);
}
```

Similarly, we keep recursively calling the function till we find the element that is associated with the `key` or you can call it `index`.

Now let's make a little function to clear up the list with the same techniques we have been using.

```C
void clear_list(NODE *head)
{
    if (head->next)
    {
        clear_list(head->next);
    }

    free(head);
}
```

Refer to [`linkedlist.c`](linkedlist.c).

-----

***Recommended Readings:***

- Introduction to Algorithms - Chapter 10. *Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein*.
- Geeks for Geeks - [Linked List Data Structure](https://www.geeksforgeeks.org/data-structures/linked-list/).
- Tutorialspoint - [Linked List Program in C](https://www.tutorialspoint.com/data_structures_algorithms/linked_list_program_in_c.htm)


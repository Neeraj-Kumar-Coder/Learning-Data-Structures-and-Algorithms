#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traverse(struct Node *ptr);
struct Node *insert(struct Node *head, struct Node *ptr, int index);
struct Node *del(struct Node *head, int index);
int length(struct Node *head);

int main(void)
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 5;
    head->next = second;
    second->data = 10;
    second->next = third;
    third->data = 15;
    third->next = NULL;

    printf("Before insertion\n");
    traverse(head);

    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = 7;
    int index = 1;
    head = insert(head, new, index);

    printf("\nAfter insertion\n");
    traverse(head);

    index = 2;
    printf("\nAfter deletion\n");
    head = del(head, index);
    traverse(head);

    printf("The length of the linked list is = %d\n", length(head));
    return 0;
}

void traverse(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element = %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *insert(struct Node *head, struct Node *ptr, int index)
{
    struct Node *temp_ptr = head;
    struct Node *prev_ptr;

    if (!index)
    {
        ptr->next = head;
        head = ptr;
        return head;
    }

    while (index--)
    {
        prev_ptr = temp_ptr;
        temp_ptr = temp_ptr->next;
    }

    prev_ptr->next = ptr;
    ptr->next = temp_ptr;
    return head;
}

struct Node *del(struct Node *head, int index)
{
    struct Node *temp_ptr = head;

    if (!index)
    {
        head = temp_ptr->next;
        free(temp_ptr);
        return head;
    }

    struct Node *prev_ptr;
    while (index--)
    {
        prev_ptr = temp_ptr;
        temp_ptr = temp_ptr->next;
    }

    if (temp_ptr->next == NULL)
    {
        prev_ptr->next = NULL;
        free(temp_ptr);
        return head;
    }

    prev_ptr->next = temp_ptr->next;
    free(temp_ptr);
    return head;
}

int length(struct Node *head)
{
    // int count = 0;
    // while (head != NULL)
    // {
    //     head = head->next;
    //     count++;
    // }
    // return count;

    if (head == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + length(head->next);
    }
}
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define ERROR -1

struct Node
{
    int value;
    struct Node *next;
};

void create_queue(struct Node **frontInd, struct Node **backInd, int value);
int enqueue(struct Node **frontInd, struct Node **backInd, int value);
void traverse(struct Node *frontInd);
int dequeue(struct Node **frontInd);
int peek(struct Node *frontInd, int index);

int main(void)
{
    struct Node *frontInd = NULL;
    struct Node *backInd = NULL;
    printf("Printing before enqueuing...\n");
    traverse(frontInd);
    create_queue(&frontInd, &backInd, 10);
    enqueue(&frontInd, &backInd, 17);
    enqueue(&frontInd, &backInd, 13);
    enqueue(&frontInd, &backInd, 11);
    dequeue(&frontInd);
    dequeue(&frontInd);
    printf("Printing after enqueuing...\n");
    traverse(frontInd);
    printf("The peeked value is = %d\n", peek(frontInd, 1));
    return 0;
}

void create_queue(struct Node **frontInd, struct Node **backInd, int value)
{
    struct Node *temp_node = (struct Node *)malloc(sizeof(struct Node));
    temp_node->value = value;
    temp_node->next = NULL;
    *frontInd = temp_node;
    *backInd = temp_node;
}

int enqueue(struct Node **frontInd, struct Node **backInd, int value)
{
    struct Node *temp_node = (struct Node *)malloc(sizeof(struct Node));
    if (temp_node == NULL) // Checking for full queue
    {
        printf("Queue is full!!!\n");
        return ERROR;
    }
    else
    {
        if (*frontInd == NULL) // Checking for empty queue
        {
            temp_node->value = value;
            temp_node->next = NULL;
            *frontInd = temp_node;
            *backInd = temp_node;
            return TRUE;
        }
        else // Executed when the queue is neither empty nor full
        {
            temp_node->value = value;
            temp_node->next = NULL;
            (*backInd)->next = temp_node;
            *backInd = temp_node;
            return TRUE;
        }
    }
}

int dequeue(struct Node **frontInd)
{
    if (frontInd)
    {
        struct Node *temp = *frontInd;
        *frontInd = (*frontInd)->next;
        free(temp);
        return TRUE;
    }
    return ERROR;
}

void traverse(struct Node *frontInd)
{
    while (frontInd)
    {
        printf("%d\n", frontInd->value);
        frontInd = frontInd->next;
    }
}

int peek(struct Node *frontInd, int index)
{
    while (index--)
    {
        frontInd = frontInd->next;
    }
    return frontInd->value;
}
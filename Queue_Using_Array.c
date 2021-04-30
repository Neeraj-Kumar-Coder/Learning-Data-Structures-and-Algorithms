#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define ERROR -1

struct queue
{
    int size;
    int frontIndex;
    int backIndex;
    int *array;
};

struct queue *create_queue(int size);
int isFull(struct queue *member);
int isEmpty(struct queue *member);
int enqueue(struct queue *member, int value);
int dequeue(struct queue *member);
int peek(struct queue *member, int index);

int main(void)
{
    struct queue *member = create_queue(10);
    printf("Is empty = %d\n", isEmpty(member));
    printf("Is full = %d\n", isFull(member));
    enqueue(member, 5);
    enqueue(member, 51);
    enqueue(member, 17);
    printf("The dequeue element is = %d\n", dequeue(member));
    printf("Is empty = %d\n", isEmpty(member));
    printf("Is full = %d\n", isFull(member));
    printf("The peeked element is = %d\n", peek(member, 1));
    return 0;
}

struct queue *create_queue(int size)
{
    struct queue *member = (struct queue *)malloc(sizeof(struct queue));
    member->size = size;
    member->backIndex = member->frontIndex = -1;
    member->array = (int *)malloc(size * sizeof(int));
    return member;
}

int isFull(struct queue *member)
{
    if (member->backIndex == member->size - 1)
    {
        return TRUE;
    }
    return FALSE;
}

int isEmpty(struct queue *member)
{
    if (member->frontIndex == member->backIndex)
    {
        return TRUE;
    }
    return FALSE;
}

int enqueue(struct queue *member, int value)
{
    if (!isFull(member))
    {
        return member->array[++member->backIndex] = value;
    }
    return ERROR;
}

int dequeue(struct queue *member)
{
    if (!isEmpty(member))
    {
        return member->array[++member->frontIndex];
    }
    return ERROR;
}

int peek(struct queue *member, int index)
{
    if (!isEmpty(member) && index < member->backIndex)
    {
        return member->array[index];
    }
    return ERROR;
}
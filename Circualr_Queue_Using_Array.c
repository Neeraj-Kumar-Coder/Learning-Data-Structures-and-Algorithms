#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define ERROR -1

struct circularQueue
{
    int size;
    int frontInd;
    int backInd;
    int *array;
};

struct circularQueue *create_circular_queue(int size);
int isEmpty(struct circularQueue *member);
int isFull(struct circularQueue *member);
int enqueue(struct circularQueue *member, int value);
int dequeue(struct circularQueue *member);
int peek(struct circularQueue *member, int index);

int main(void)
{
    struct circularQueue *member = create_circular_queue(6);

    printf("is full = %d\n", isFull(member));
    printf("is empty = %d\n", isEmpty(member));

    enqueue(member, 15);
    enqueue(member, 10);
    enqueue(member, 12);
    enqueue(member, 11);
    enqueue(member, 17);
    enqueue(member, 16);

    printf("is full = %d\n", isFull(member));
    printf("is empty = %d\n", isEmpty(member));

    printf("The element dequeued is = %d\n", dequeue(member));
    printf("The element dequeued is = %d\n", dequeue(member));
    printf("The element dequeued is = %d\n", dequeue(member));

    enqueue(member, 20);

    printf("is full = %d\n", isFull(member));
    printf("is empty = %d\n", isEmpty(member));

    printf("Peeked value = %d\n", peek(member, 2));
    return 0;
}

struct circularQueue *create_circular_queue(int size)
{
    struct circularQueue *member = (struct circularQueue *)malloc(sizeof(struct circularQueue));
    member->size = size;
    member->frontInd = member->backInd = 0;
    member->array = (int *)malloc(size * sizeof(int));
    return member;
}

int isEmpty(struct circularQueue *member)
{
    if (member->backInd == member->frontInd)
    {
        return TRUE;
    }
    return FALSE;
}

int isFull(struct circularQueue *member)
{
    if (((member->backInd + 1) % member->size) == member->frontInd)
    {
        return TRUE;
    }
    return FALSE;
}

int enqueue(struct circularQueue *member, int value)
{
    if (!isFull(member))
    {
        member->array[++member->backInd % member->size] = value;
        return TRUE;
    }
    return FALSE;
}

int dequeue(struct circularQueue *member)
{
    if (!isEmpty(member))
    {
        return member->array[++member->frontInd % member->size];
    }
    return FALSE;
}

int peek(struct circularQueue *member, int index)
{
    return member->array[index % member->size];
}
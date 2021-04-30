#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define ERROR -1

struct DEQueue
{
    int size;
    int frontIndex;
    int backIndex;
    int *array;
};

struct DEQueue *create_DEQueue(int size);
int isFull(struct DEQueue *member);
int isEmpty(struct DEQueue *member);
int enqueueR(struct DEQueue *member, int value);
int enqueueF(struct DEQueue *member, int value);
int dequeueR(struct DEQueue *member);
int dequeueF(struct DEQueue *member);
void traverse(struct DEQueue *member);

int main(void)
{
    struct DEQueue *member = create_DEQueue(10);
    enqueueR(member, 14);
    enqueueR(member, 12);
    enqueueR(member, 98);
    enqueueR(member, 13);
    dequeueF(member);
    dequeueF(member);
    enqueueF(member, 99);
    enqueueF(member, 98);
    dequeueR(member);
    traverse(member);
    return 0;
}

struct DEQueue *create_DEQueue(int size)
{
    struct DEQueue *member = (struct DEQueue *)malloc(sizeof(struct DEQueue));
    member->size = size;
    member->array = (int *)malloc(size * sizeof(int));
    member->frontIndex = -1;
    member->backIndex = -1;
    return member;
}

int isFull(struct DEQueue *member)
{
    return member->backIndex == member->size - 1;
}

int isEmpty(struct DEQueue *member)
{
    return member->frontIndex == member->backIndex;
}

int enqueueR(struct DEQueue *member, int value)
{
    if (!isFull(member))
    {
        member->array[++member->backIndex] = value;
        return TRUE;
    }
    return ERROR;
}

int enqueueF(struct DEQueue *member, int value)
{
    if (member->frontIndex != -1)
    {
        member->array[member->frontIndex--] = value;
        return TRUE;
    }
    return ERROR;
}

int dequeueR(struct DEQueue *member)
{
    if (!isEmpty(member))
    {
        return member->array[member->backIndex--];
    }
    return ERROR;
}

int dequeueF(struct DEQueue *member)
{
    if (!isEmpty(member))
    {
        return member->array[member->frontIndex++];
    }
    return ERROR;
}

void traverse(struct DEQueue *member)
{
    for (int i = member->frontIndex + 1; i <= member->backIndex; i++)
    {
        printf("%d\n", member->array[i]);
    }
}
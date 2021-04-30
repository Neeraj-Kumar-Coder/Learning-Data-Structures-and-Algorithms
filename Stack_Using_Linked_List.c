#include <stdio.h>
#include <stdlib.h>

struct StackNode
{
    int value;
    struct StackNode *next;
};

struct StackNode *create_stack(int data);
void push(struct StackNode **top, int data);
void traverse(struct StackNode *top);
int is_empty(struct StackNode *top);
int pop(struct StackNode **top);

int main(void)
{
    struct StackNode *top = NULL;
    top = create_stack(10);
    push(&top, 13);
    push(&top, 17);
    push(&top, 99);
    pop(&top);
    traverse(top);
    return 0;
}

struct StackNode *create_stack(int data)
{
    struct StackNode *top = (struct StackNode *)malloc(sizeof(struct StackNode));
    top->value = data;
    top->next = NULL;

    return top;
}

void push(struct StackNode **top, int data)
{
    struct StackNode *newNode = create_stack(data);
    newNode->next = *top;
    *top = newNode;
}

void traverse(struct StackNode *top)
{
    while (top != NULL)
    {
        printf("%d\n", top->value);
        top = top->next;
    }
}

int is_empty(struct StackNode *top)
{
    return !top;
}

int pop(struct StackNode **top)
{
    if (!is_empty(*top))
    {
        struct StackNode *tempNode = *top;
        *top = (*top)->next;
        int x = tempNode->value;
        free(tempNode);
        return x;
    }
    return -1;
}
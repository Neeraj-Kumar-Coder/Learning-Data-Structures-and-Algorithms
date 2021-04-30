#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *array;
};

struct stack *create_stack(int size);
int is_empty(struct stack *head);
int is_full(struct stack *head);
int push(struct stack *head, int value);
int pop(struct stack *head);
int stack_top(struct stack *head);
int stack_bottom(struct stack *head);
int peek(struct stack *head, int index);
void enQueueMethod1(struct stack *stack1, struct stack *stack2, int value);
int deQueueMethod1(struct stack *stack1);
void enQueueMethod2(struct stack *stack1, int value);
int deQueueMethod2(struct stack *stack1, struct stack *stack2);

int main(void)
{
    struct stack *stack1 = create_stack(50);
    struct stack *stack2 = create_stack(50);

    //**********************************************************
    // // METHOD 1 : BY MAKING enQueueMethod1 OPERATION COSTLY
    // push(stack1, 12);
    // push(stack1, 13);
    // push(stack1, 14);
    // push(stack1, 15);
    // push(stack1, 16);
    // push(stack1, 17);

    // enQueueMethod1(stack1, stack2, 99);
    // deQueueMethod1(stack1);

    // // FOR TRAVERSAL OF THE STACK
    // printf("The popped element is = %d\n", pop(stack1));
    // printf("The popped element is = %d\n", pop(stack1));
    // printf("The popped element is = %d\n", pop(stack1));
    // printf("The popped element is = %d\n", pop(stack1));
    // printf("The popped element is = %d\n", pop(stack1));
    // printf("The popped element is = %d\n", pop(stack1));
    // printf("The popped element is = %d\n", pop(stack1));
    // printf("The popped element is = %d\n", pop(stack1));
    //************************************************************



    //************************************************************
    // // METHOD 2 : BY MAKING deQueueMethod2 OPERATION COSTLY
    // push(stack1, 12);
    // push(stack1, 13);
    // push(stack1, 14);
    // push(stack1, 15);
    // push(stack1, 16);
    // push(stack1, 17);

    // enQueueMethod2(stack1, 99);
    // deQueueMethod2(stack1, stack2);

    // // FOR TRAVERSAL OF THE STACK
    // printf("The popped element is = %d\n", pop(stack1));
    // printf("The popped element is = %d\n", pop(stack1));
    // printf("The popped element is = %d\n", pop(stack1));
    // printf("The popped element is = %d\n", pop(stack1));
    // printf("The popped element is = %d\n", pop(stack1));
    // printf("The popped element is = %d\n", pop(stack1));
    // printf("The popped element is = %d\n", pop(stack1));
    // printf("The popped element is = %d\n", pop(stack1));
    //*************************************************************
    return 0;
}

struct stack *create_stack(int size)
{
    struct stack *head = (struct stack *)malloc(sizeof(struct stack));
    head->size = size;
    head->top = -1;
    head->array = (int *)malloc(sizeof(int));
    return head;
}

int is_empty(struct stack *head)
{
    return head->top == -1;
}

int is_full(struct stack *head)
{
    return head->top == head->size - 1;
}

int push(struct stack *head, int value)
{
    if (!is_full(head))
    {
        head->array[++head->top] = value;
        return 1;
    }
    else
    {
        printf("Stack Overflow!\n");
        return 0;
    }
}

int pop(struct stack *head)
{
    if (!is_empty(head))
    {
        return head->array[head->top--];
    }
    else
    {
        printf("Stack Underflow!\n");
        return -1;
    }
}

int stack_top(struct stack *head)
{
    if (!is_empty(head))
        return head->array[head->top];
    return -1;
}

int stack_bottom(struct stack *head)
{
    if (!is_empty(head))
        return head->array[0];
    return -1;
}

int peek(struct stack *head, int index)
{
    if (!is_empty(head))
        return head->array[head->top - index];
    return -1;
}

void enQueueMethod1(struct stack *stack1, struct stack *stack2, int value)
{
    while (!is_empty(stack1))
    {
        push(stack2, pop(stack1));
    }
    push(stack1, value);
    while (!is_empty(stack2))
    {
        push(stack1, pop(stack2));
    }
}

int deQueueMethod1(struct stack *stack1)
{
    if (!is_empty(stack1))
    {
        return pop(stack1);
    }
    return -1;
}

void enQueueMethod2(struct stack *stack1, int value)
{
    push(stack1, value);
}

int deQueueMethod2(struct stack *stack1, struct stack *stack2)
{
    if (is_empty(stack1) && is_empty(stack2))
    {
        return -1;
    }
    if (is_empty(stack2))
    {
        while (!is_empty(stack1))
        {
            push(stack2, pop(stack1));
        }
        int value = pop(stack2);
        while (!is_empty(stack2))
        {
            push(stack1, pop(stack2));
        }
        return value;
    }
    return -1;
}
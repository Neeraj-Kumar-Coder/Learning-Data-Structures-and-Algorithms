// STACK DATA STRUCTURE USING ARRAYS:
// METHODS: is_empty(), is_full(), push(), pop(), peek()

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

int main(void)
{
    int size;
    printf("Enter the size of stack: ");
    scanf("%d", &size);

    struct stack *member = create_stack(size);

    if (is_empty(member))
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Stack is not empty\n");
    }

    int number_of_elements;
    printf("Enter the number of elements you want to add: ");
    scanf("%d", &number_of_elements);

    for (int i = 0; i < number_of_elements; i++)
    {
        int temp;
        printf("Enter the element: ");
        scanf("%d", &temp);
        push(member, temp);
    }

    pop(member);

    for (int i = 0; i <= member->top; i++)
    {
        printf("%d ", member->array[i]);
    }

    printf("\n");

    if (is_empty(member))
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Stack is not empty\n");
    }

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
        return 0;
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
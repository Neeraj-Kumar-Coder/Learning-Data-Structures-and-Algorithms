#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *array;
};

struct stack *create_stack(int size);
int is_empty(struct stack *head);
int is_full(struct stack *head);
int push(struct stack *head, int value);
char pop(struct stack *head);
char stack_top(struct stack *head);
char stack_bottom(struct stack *head);
char peek(struct stack *head, int index);
int precedence(char operator);
int isOperator(char character);
char *infixToPostfix(char *infix);

int main(void)
{
    char *infix = "p-q-r/a";
    printf("The postfix expression is = %s\n", infixToPostfix(infix));
    return 0;
}

char *infixToPostfix(char *infix)
{
    struct stack *head = create_stack(100);
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0; // For traversing infix string
    int j = 0; // For traversing postfix string

    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            ++i, ++j;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stack_top(head)))
            {
                push(head, infix[i]);
                ++i;
            }
            else
            {
                postfix[j] = pop(head);
                j++;
            }
        }
    }
    while (!is_empty(head))
    {
        postfix[j] = pop(head);
        ++j;
    }
    postfix[j] = '\0';
    return postfix;
}

int precedence(char operator)
{
    if (operator== '-' || operator== '+')
    {
        return 1;
    }
    else if (operator== '*' || operator== '/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

int isOperator(char character)
{
    if (character == '-' || character == '+' || character == '*' || character == '/')
    {
        return 1;
    }
    return 0;
}

struct stack *create_stack(int size)
{
    struct stack *head = (struct stack *)malloc(sizeof(struct stack));
    head->size = size;
    head->top = -1;
    head->array = (char *)malloc(sizeof(char));
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

char pop(struct stack *head)
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

char stack_top(struct stack *head)
{
    if (!is_empty(head))
        return head->array[head->top];
    return -1;
}

char stack_bottom(struct stack *head)
{
    if (!is_empty(head))
        return head->array[0];
    return -1;
}

char peek(struct stack *head, int index)
{
    if (!is_empty(head))
        return head->array[head->top - index];
    return -1;
}
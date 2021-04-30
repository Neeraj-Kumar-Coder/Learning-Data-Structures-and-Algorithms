#include <stdio.h>
#include <stdlib.h>

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
int stack_top(struct stack *head);
int stack_bottom(struct stack *head);
int peek(struct stack *head, int index);
int is_matching(char parenthesis_1, char parenthesis_2);
int balanced_parenthesis(char *string, struct stack *member);

int main(void)
{
    struct stack *member = create_stack(100);
    char string[100];

    printf("Enter the string for parenthesis matching: ");
    scanf("%[^\n]%*c", string);

    if (balanced_parenthesis(string, member))
    {
        printf("The parenthesis are balanced!\n");
    }
    else
    {
        printf("The parenthesis are not balanced!\n");
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

int is_matching(char parenthesis_1, char parenthesis_2)
{
    if (parenthesis_1 == '(' && parenthesis_2 == ')')
    {
        return 1;
    }
    else if (parenthesis_1 == '[' && parenthesis_2 == ']')
    {
        return 1;
    }
    else if (parenthesis_1 == '{' && parenthesis_2 == '}')
    {
        return 1;
    }
    return 0;
}

int balanced_parenthesis(char *string, struct stack *member)
{
    int i = 0;
    while (string[i] != '\0')
    {
        if (string[i] == '(' || string[i] == '[' || string[i] == '{')
        {
            push(member, string[i]);
        }
        else if (string[i] == ')' || string[i] == ']' || string[i] == '}')
        {
            if (!is_matching(pop(member), string[i]))
            {
                return 0;
            }
        }
        ++i;
    }
    return is_empty(member);
}
#include <stdio.h>
#include <stdlib.h>

typedef struct Term
{
    int exponent;
    int value;
    struct Term *next;
} Term;

void input(Term *head, int degree)
{
    degree++;
    while (degree)
    {
        head->exponent = degree-- - 1;
        printf("Enter the coefficient of the term: ");
        scanf("%d", &head->value);
        head->next = (Term *)malloc(sizeof(Term));
        if (degree)
            head = head->next;
    }
    head->next = NULL;
}

Term *addition(int degree)
{
    degree++;
    Term *head = (Term *)malloc(sizeof(Term));
    Term *temp = head;
    while (--degree)
    {
        temp->next = (Term *)malloc(sizeof(Term));
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}

int main(void)
{
    int degree;
    printf("Enter the degree of the first polynomial: ");
    scanf("%d", &degree);
    Term *firstPoly = (Term *)malloc(sizeof(Term));
    input(firstPoly, degree);

    printf("Enter the degree of the first polynomial: ");
    scanf("%d", &degree);
    Term *secondPoly = (Term *)malloc(sizeof(Term));
    input(secondPoly, degree);

    Term *add = addition((firstPoly->exponent > secondPoly->exponent) ? firstPoly->exponent : secondPoly->exponent);
    Term *temp = add;
    while (firstPoly && secondPoly)
    {
        if (firstPoly->exponent == secondPoly->exponent)
        {
            temp->value = firstPoly->value + secondPoly->value;
            temp->exponent = firstPoly->exponent;
            firstPoly = firstPoly->next;
            secondPoly = secondPoly->next;
        }
        else if (firstPoly->exponent > secondPoly->exponent)
        {
            temp->value = firstPoly->value;
            temp->exponent = firstPoly->exponent;
            firstPoly = firstPoly->next;
        }
        else
        {
            temp->value = secondPoly->value;
            temp->exponent = secondPoly->exponent;
            secondPoly = secondPoly->next;
        }
        temp = temp->next;
    }
    while (firstPoly)
    {
        temp->value = firstPoly->value;
        temp->exponent = firstPoly->exponent;
        firstPoly = firstPoly->next;
        temp = temp->next;
    }
    while (secondPoly)
    {
        temp->value = secondPoly->value;
        temp->exponent = secondPoly->exponent;
        secondPoly = secondPoly->next;
        temp = temp->next;
    }

    while (add)
    {
        printf("%dx^%d + ", add->value, add->exponent);
        add = add->next;
    }
    printf("\b\b.\n");

    return 0;
}
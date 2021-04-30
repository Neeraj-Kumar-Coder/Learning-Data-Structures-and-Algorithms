// Date and Time = 21 April 2021 : 2 P.M.

/*
Creating an Abstract Data Type (myArray) that have:
______________________________________________
    Basic Values        |       Methods
************************|*********************
    total size          |       max
    base address        |       create array
    used size           |       print array
______________________________________________
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Abstract_Data_Type
{
    int total_size;
    int used_size;
    int *base_address;
} myArray;

void initialize(myArray *pointer)
{
    printf("Enter the total size of the array you want to create: ");
    scanf("%d", &pointer->total_size);
    printf("Enter the size which will be in use: ");
    scanf("%d", &pointer->used_size);

    pointer->base_address = (int *)malloc(pointer->total_size * sizeof(int));
}

int max(myArray *member)
{
    int max = 0;
    for (int i = 0; i < member->used_size; i++)
    {
        if ((member->base_address)[i] > max)
        {
            max = (member->base_address)[i];
        }
    }
    return max;
}

void create_array(myArray *member)
{
    for (int i = 0; i < member->used_size; i++)
    {
        printf("Enter the value of the element %d : ", i);
        scanf("%d", &(member->base_address)[i]);
    }
}

void print_array(myArray *member)
{
    for (int i = 0; i < member->used_size; i++)
    {
        printf("%d\n", (member->base_address)[i]);
    }
}

void del(myArray *member)
{
    free(member->base_address);
}

int main(void)
{
    myArray arr;
    initialize(&arr);
    create_array(&arr);
    print_array(&arr);
    printf("The maximum value in the array is = %d\n", max(&arr));
    del(&arr);
    return 0;
}
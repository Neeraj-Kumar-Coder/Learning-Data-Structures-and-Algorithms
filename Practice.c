#include <stdio.h>

void changePointer(int **ptr)
{
    int x = 5;
    *ptr = &x;
}

int main(void)
{
    int a = 7;
    int *ptr = &a;
    printf("Before calling: %d\n", *ptr);
    changePointer(&ptr);
    printf("After calling: %d\n", *ptr);
    return 0;
}
#include <stdio.h>

int decreser(int n);

int main(void)
{
    int value = 5;
    int result = decreser(value);
    printf("The result is = %d\n", result);
    return 0;
}

int decreser(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return decreser(n - 1);
    }

    return n;
}
// TIME COMPLEXITY OF ROTATE FUNCTION = O(elements*size)
// AUXILIARY SPACE COMPLEXITIY OF ROTATE FUNCTION = O(1)

#include <stdio.h>

void rotate(int arr[], int size, int elements);

int main(void)
{
    int array[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(array) / sizeof(int);
    int rotate_by = 2;
    rotate(array, size, rotate_by);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}

void rotate(int arr[], int size, int elements)
{
    while (elements--)
    {
        int temp = arr[0];
        for (int i = 1; i < size; i++)
        {
            arr[i - 1] = arr[i];
        }
        arr[size - 1] = temp;
    }
}
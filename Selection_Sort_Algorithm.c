/*
    TIME COMPLEXITY = O(n^2)
    SPACE COMPLEXITY =  O(1)
    STABLE = FALSE
    RECURSIVE = FALSE (BUT WE CAN MAKE IT RECURSIVE)
    ADAPTIVE = FALSE
    TYPE = INTERNAL
*/

#include <stdio.h>

void selectionSort(int *array, int size);
void selectionSortRecursive(int *array, int size);
void print_array(int *array, int size);

int main(void)
{
    int array[] = {87, 76, 67, 54, 54, 34, 23, 21, 7, 5, 4, 4, 3, 2};
    // int array[] = {2, 3, 4, 4, 5, 7, 21, 23, 34, 54, 54, 67, 76, 87}; // Already sorted array
    int size = sizeof(array) / sizeof(int);
    // selectionSort(array, size);
    selectionSortRecursive(array, size);
    print_array(array, size);
    return 0;
}

void selectionSort(int *array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minValue = array[i], minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (minValue > array[j])
            {
                minValue = array[j];
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            array[i] = array[i] + array[minIndex];
            array[minIndex] = array[i] - array[minIndex];
            array[i] = array[i] - array[minIndex];
        }
    }
}

void selectionSortRecursive(int *array, int size)
{
    if (size == 1) // GUARD CLAUSE
    {
        return;
    }

    int minValue = array[0], minIndex = 0;
    for (int i = 1; i < size; i++)
    {
        if (minValue > array[i])
        {
            minValue = array[i];
            minIndex = i;
        }
    }
    if (minIndex)
    {
        array[0] = array[0] + array[minIndex];
        array[minIndex] = array[0] - array[minIndex];
        array[0] = array[0] - array[minIndex];
    }
    selectionSortRecursive(&array[1], size - 1);
}

void print_array(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
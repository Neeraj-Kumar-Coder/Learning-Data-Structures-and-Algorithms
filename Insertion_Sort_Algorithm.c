/*
    TIME COMPLEXITY = O(n^2)
    SPACE COMPLEXITY =  O(1)
    STABLE = TRUE
    RECURSIVE = FALSE
    ADAPTIVE = TRUE
    TYPE = INTERNAL
*/

#include <stdio.h>

void insertionSort(int *array, int size);
void print_array(int *array, int size);

int main(void)
{
    int array[] = {87, 76, 67, 54, 54, 34, 23, 21, 7, 5, 4, 4, 3, 2};
    // int array[] = {2, 3, 4, 4, 5, 7, 21, 23, 34, 54, 54, 67, 76, 87}; // Already sorted array
    int size = sizeof(array) / sizeof(int);
    insertionSort(array, size);
    print_array(array, size);
    return 0;
}

void insertionSort(int *array, int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp = array[i], j = i - 1;
        while (array[j] > temp && j >= 0)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = temp;
    }
}

void print_array(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
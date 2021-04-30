/*
    TIME COMPLEXITY = O(n^2)
    SPACE COMPLEXITY =  O(1)
    STABLE = TRUE
    RECURSIVE = FALSE
    ADAPTIVE = FASLE (BUT WE CAN MAKE IT ADAPTIVE)
    TYPE = INTERNAL
*/

#include <stdio.h>

void bubbleSort(int arr[], int size);
void print_array(int *array, int size);

int main(void)
{
    int array[] = {87, 76, 67, 54, 54, 34, 23, 21, 7, 5, 4, 4, 3, 2};
    // int array[] = {2, 3, 4, 4, 5, 7, 21, 23, 34, 54, 54, 67, 76, 87};
    int size = sizeof(array) / sizeof(int);
    bubbleSort(array, size);
    printf("Sorted array: ");
    print_array(array, size);
    return 0;
}

void bubbleSort(int arr[], int size)
{
    int isSorted;                      // To make it adaptive
    for (int i = 0; i < size - 1; i++) // For number of passes
    {
        isSorted = 1;                          // To make it adaptive
        for (int j = 0; j < size - i - 1; j++) // For number of comparisions
        {
            if (arr[j] > arr[j + 1])
            {
                arr[j] = arr[j] + arr[j + 1];
                arr[j + 1] = arr[j] - arr[j + 1];
                arr[j] = arr[j] - arr[j + 1];
                isSorted = 0; // To make it adaptive
            }
        }
        if (isSorted) // To make it adaptive
        {
            return;
        }
    }
}

void print_array(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}
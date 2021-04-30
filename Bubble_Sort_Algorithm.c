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
    int array[] = {2, 3, 4, 54, 34, 67, 87, 54, 21, 23, 4, 76, 5, 7};
    int size = sizeof(array) / sizeof(int);
    bubbleSort(array, size);
    printf("Sorted array: ");
    print_array(array, size);
    return 0;
}

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++) // For number of passes
    {
        for (int j = i + 1; j < size; j++) // For number of comparisions
        {
            if (arr[j] > arr[j + 1])
            {
                arr[j] = arr[j] + arr[j + 1];
                arr[j + 1] = arr[j] - arr[j + 1];
                arr[j] = arr[j] - arr[j + 1];
            }
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
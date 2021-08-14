/*
    TIME COMPLEXITY = O(nlog n) [FOR ALL THE THREE CASES]
    SPACE COMPLEXITY =  O(n)
    STABLE = TRUE
    RECURSIVE = TRUE
    ADAPTIVE = FALSE
    TYPE = INTERNAL
*/

#include <stdio.h>
#include <stdlib.h>

void merge(int array[], int low, int mid, int high);
void print_array(int *array, int size);
void mergeSort(int array[], int low, int high);

int main(void)
{
    // int array[] = {5, 4, 3, 2, 1};
    int array[] = {87, 76, 67, 54, 54, 34, 23, 21, 7, 5, 4, 4, 3, 2};
    // int array[] = {2, 3, 4, 4, 5, 7, 21, 23, 34, 54, 54, 67, 76, 87}; // Already sorted array
    int size = sizeof(array) / sizeof(int);
    mergeSort(array, 0, size - 1);
    print_array(array, size);
    return 0;
}

void mergeSort(int array[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(array, low, mid);
        mergeSort(array, mid + 1, high);
        merge(array, low, mid, high);
    }
}

void merge(int array[], int low, int mid, int high)
{
    int *temp_array = (int *)malloc((high - low + 1) * sizeof(int));
    int i = low, j = mid + 1, k = 0;
    while (i <= mid && j <= high)
    {
        if (array[i] < array[j])
        {
            temp_array[k++] = array[i++];
        }
        else
        {
            temp_array[k++] = array[j++];
        }
    }
    while (i <= mid)
    {
        temp_array[k++] = array[i++];
    }
    while (j <= high)
    {
        temp_array[k++] = array[j++];
    }
    j = 0; // to reset the index to zero
    for (int i = low; i < high + 1; i++)
    {
        array[i] = temp_array[j++];
    }
    free(temp_array);
}

void print_array(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
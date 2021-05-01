#include <stdio.h>
#include <stdlib.h>

void print_array(int *array, int size);
void quickSort(int *array, int low, int high);
int partition(int *array, int low, int high);
void swap(int *a, int *b);

int main(void)
{
    int array[] = {5, 4, 3, 2, 1};
    // int array[] = {87, 76, 67, 54, 54, 34, 23, 21, 7, 5, 4, 4, 3, 2};
    // int array[] = {2, 3, 4, 4, 5, 7, 21, 23, 34, 54, 54, 67, 76, 87}; // Already sorted array
    int size = sizeof(array) / sizeof(int);
    quickSort(array, 0, size - 1);
    print_array(array, size);
    return 0;
}

void print_array(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void quickSort(int *array, int low, int high)
{
    if (low < high)
    {
        int index = partition(array, low, high);
        quickSort(array, low, index - 1);
        quickSort(array, index + 1, high);
    }
}

int partition(int *array, int low, int high)
{
    int pivot = array[low];
    int i = (high + 1);

    for (int j = high; j >= low + 1; j--)
    {
        if (array[j] > pivot)
        {
            i--;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i - 1], &array[low]);
    return (i - 1);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
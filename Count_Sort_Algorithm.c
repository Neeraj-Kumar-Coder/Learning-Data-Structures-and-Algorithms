/*
    TIME COMPLEXITY = O(m + n) [HERE 'm' IS THE LARGEST MEMBER OF THE GIVEN ARRAY]
    SPACE COMPLEXITY =  O(m) [IT HAS THE WORSED SPACE COMPLEXITY]
    STABLE = TRUE
    RECURSIVE = FALSE
    ADAPTIVE = FALSE
    TYPE = INTERNAL
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void countSort(int *array, int size);
int maximum(int *array, int size);
void print_array(int *array, int size);

int main(void)
{
    int array[] = {5, 4, 3, 2, 1};
    // int array[] = {87, 76, 67, 54, 54, 34, 23, 21, 7, 5, 4, 4, 3, 2};
    // int array[] = {2, 3, 4, 4, 5, 7, 21, 23, 34, 54, 54, 67, 76, 87}; // Already sorted array
    int size = sizeof(array) / sizeof(int);
    countSort(array, size);
    print_array(array, size);
    return 0;
}

void countSort(int *array, int size)
{
    int size_of_count_array = maximum(array, size) + 1, i;
    int *count_array = (int *)calloc(size_of_count_array, sizeof(int));
    // Used calloc() because it will initialize the heaped array elements with zero
    for (i = 0; i < size; i++)
    {
        count_array[array[i]]++;
    }
    i = 0;
    int j = 0;
    while (i < size_of_count_array)
    {
        if (count_array[i]--)
        {
            array[j++] = i;
            continue;
        }
        ++i;
    }
    free(count_array);
}

int maximum(int *array, int size)
{
    int max = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (max < array[i])
        {
            max = array[i];
        }
    }
    return max;
}

void print_array(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
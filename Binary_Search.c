#include <stdio.h>

int binarySearch(int *array, int size, int element)
{
    int low = 0, mid, high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (array[mid] == element)
        {
            return mid;
        }
        else if (array[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int size = sizeof(arr) / sizeof(int);
    printf("Enter the element which you want to search in the sorted array: ");
    int element;
    scanf("%d", &element);
    int found = binarySearch(arr, size, element);
    if (found == -1)
    {
        printf("The element is not present in the array!!\n");
    }
    else
    {
        printf("The element %d is found at index %d\n", element, found);
    }
    return 0;
}
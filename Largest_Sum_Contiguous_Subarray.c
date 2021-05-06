#include <stdio.h>
#include <limits.h>

int largestSum(int *array, int size);

int main(void)
{
    int array[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int size = sizeof(array) / sizeof(int);
    printf("The largest sum of a contiguous subarray is = %d\n", largestSum(array, size));
    return 0;
}


// TIME COMPLEXITY = O(n)
int largestSum(int *array, int size)
{
    int max_so_far = INT_MIN;
    int max_ending_here = 0;
    for (int i = 0; i < size; i++)
    {
        max_ending_here += array[i];
        if (max_ending_here > max_so_far)
        {
            max_so_far = max_ending_here;
        }
        if (max_ending_here < 0)
        {
            max_ending_here = 0;
        }
    }
    return max_so_far;
}
#include <stdio.h>
#include <stdlib.h>

struct Heap
{
    int capacity;
    int heap_size;
    int *harr;
};

struct Heap *createHeap(int cap);
void buildMaxHeap(struct Heap *node);
void heapSort(struct Heap *node);
void heapSortIterative(struct Heap *node);
void swap(int *a, int *b);
void print_heap(struct Heap *node);

int main(void)
{
    struct Heap *node = createHeap(100);
    printf("Enter the size of the array you want to sort: ");
    scanf("%d", &node->heap_size);
    for (int i = 0; i < node->heap_size; i++)
    {
        printf("Enter the value: ");
        scanf("%d", &node->harr[i]);
    }

    int size = node->heap_size;

    buildMaxHeap(node);
    // heapSort(node);
    heapSortIterative(node);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", node->harr[i]);
    }
    return 0;
}

struct Heap *createHeap(int cap)
{
    struct Heap *node = (struct Heap *)malloc(sizeof(struct Heap));
    node->capacity = cap;
    node->heap_size = 0;
    node->harr = (int *)malloc(cap * sizeof(int));
    return node;
}

void maxHeapify(struct Heap *node, int index)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int max = index;

    if (left < node->heap_size && node->harr[index] < node->harr[left])
    {
        max = left;
    }
    if (right < node->heap_size && node->harr[max] < node->harr[right])
    {
        max = right;
    }
    if (max != index)
    {
        swap(&node->harr[max], &node->harr[index]);
        maxHeapify(node, max);
    }
}

void buildMaxHeap(struct Heap *node)
{
    for (int i = node->heap_size - 1; i >= 0; i--)
    {
        maxHeapify(node, i);
    }
}

void heapSort(struct Heap *node)
{
    if (!node->heap_size)
        return;

    swap(&node->harr[0], &node->harr[--node->heap_size]);
    maxHeapify(node, 0);
    heapSort(node);
}

void heapSortIterative(struct Heap *node)
{
    buildMaxHeap(node);
    int left, right, max, j;
    for (int i = node->heap_size - 1; i >= 0; i--)
    {
        swap(&node->harr[0], &node->harr[i]);
        j = 0;
        while (j < i)
        {
            left = 2 * j + 1;
            right = 2 * j + 2;
            max = j;
            if (left < i && node->harr[j] < node->harr[left])
            {
                max = left;
            }
            if (right < i && node->harr[max] < node->harr[right])
            {
                max = right;
            }
            if (max != j)
            {
                swap(&node->harr[max], &node->harr[j]);
                j = max;
            }
            else
            {
                break;
            }
        }
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_heap(struct Heap *node)
{
    // printf("Heap Size = %d : ", node->heap_size);
    for (int i = 0; i < node->heap_size; i++)
    {
        printf("%d ", node->harr[i]);
    }
    printf("\n");
}
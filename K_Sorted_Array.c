#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Heap
{
    int capacity;
    int heap_size;
    int *harr;
};

struct Heap *createMinHeap(int capacity);
void MIN_HEAPIFY(struct Heap *node, int index);
void BUILD_HEAP(struct Heap *node);
void insert(struct Heap *node, int value);
void swap(int *a, int *b);
void print_heap(struct Heap *node);
int extractMin(struct Heap *node);
void decreaseKey(struct Heap *node, int key, int newValue);
void deleteNode(struct Heap *node, int key);

int main(void)
{
    int size, k, index = 0;

    printf("Enter the size of array you want to sort: ");
    scanf("%d", &size);
    printf("Enter the value of \'k\' for this K-sorted array: ");
    scanf("%d", &k);

    int array[size];
    int sorted_array[size];

    for (int i = 0; i < size; i++)
    {
        printf("Enter the value: ");
        scanf("%d", &array[i]);
    }

    struct Heap *node = createMinHeap(k + 1);
    for (int i = 0; i < k + 1; i++)
    {
        insert(node, array[i]);
    }

    for (int i = k + 1; i < size; i++)
    {
        sorted_array[index++] = extractMin(node);
        insert(node, array[i]);
    }

    while (node->heap_size)
    {
        sorted_array[index++] = extractMin(node);
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d ", sorted_array[i]);
    }

    return 0;
}

struct Heap *createMinHeap(int capacity)
{
    struct Heap *node = (struct Heap *)malloc(sizeof(struct Heap));
    node->capacity = capacity;
    node->heap_size = 0;
    node->harr = (int *)malloc(capacity * sizeof(int));
    return node;
}

void MIN_HEAPIFY(struct Heap *node, int index)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int min = index;

    if (left < node->heap_size && node->harr[index] > node->harr[left])
    {
        min = left;
    }
    if (right < node->heap_size && node->harr[min] > node->harr[right])
    {
        min = right;
    }
    if (min != index)
    {
        swap(&node->harr[min], &node->harr[index]);
        MIN_HEAPIFY(node, min);
    }
}

void BUILD_HEAP(struct Heap *node)
{
    for (int index = node->heap_size - 1; index >= 0; index--)
    {
        MIN_HEAPIFY(node, index);
    }
}

void insert(struct Heap *node, int value)
{
    node->harr[node->heap_size++] = value;
    BUILD_HEAP(node);
}

void deleteNode(struct Heap *node, int key)
{
    decreaseKey(node, key, INT_MIN);
    extractMin(node);
}

int extractMin(struct Heap *node)
{
    int temp = node->harr[0];
    node->harr[0] = node->harr[--node->heap_size];
    MIN_HEAPIFY(node, 0);
    return temp;
}

void decreaseKey(struct Heap *node, int key, int newValue)
{
    int index = -1;
    while (node->harr[++index] != key)
        ;
    node->harr[index] = newValue;

    BUILD_HEAP(node);
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
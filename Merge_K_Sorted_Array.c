#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int value;
    int array_number;
};

struct Heap
{
    int capacity;
    int heap_size;
    struct Array *array;
};

struct Heap *createMinHeap(int cap);
void minHeapify(struct Heap *node, int index);
void buildMinHeap(struct Heap *node);
void insert(struct Heap *node, int key, int arrNum);
struct Array *extractMin(struct Heap *node);
void swap(struct Array *a, struct Array *b);
int *mergeKSortedArray(int arr1[], int size1, int arr2[], int size2);

int main(void)
{
    int array1[] = {99};
    int size1 = sizeof(array1) / sizeof(int);
    int array2[] = {24, 26, 35, 39};
    int size2 = sizeof(array2) / sizeof(int);

    int *merged = mergeKSortedArray(array1, size1, array2, size2);
    for (int i = 0; i < size1 + size2; i++)
    {
        printf("%d ", merged[i]);
    }

    return 0;
}

int *mergeKSortedArray(int arr1[], int size1, int arr2[], int size2)
{
    struct Heap *node = createMinHeap(2);
    int i = 0, j = 0, k = 0;
    insert(node, arr1[i], 1);
    insert(node, arr2[j], 2);
    struct Array *arr = NULL;
    int *array = (int *)malloc((size1 + size2) * sizeof(int));

    while (node->heap_size)
    {
        arr = extractMin(node);
        array[k++] = arr->value;
        if (arr->array_number == 1)
        {
            ++i;
            if (i < size1)
            {
                insert(node, arr1[i], 1);
            }
        }
        else
        {
            ++j;
            if (j < size2)
            {
                insert(node, arr2[j], 2);
            }
        }
    }
    return array;
}

struct Heap *createMinHeap(int cap)
{
    struct Heap *node = (struct Heap *)malloc(sizeof(struct Heap));
    node->capacity = cap;
    node->heap_size = 0;
    node->array = (struct Array *)malloc(cap * sizeof(struct Array));
    return node;
}

void minHeapify(struct Heap *node, int index)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int min = index;

    if (left < node->heap_size && node->array[index].value > node->array[left].value)
    {
        min = left;
    }
    if (right < node->heap_size && node->array[min].value > node->array[right].value)
    {
        min = right;
    }
    if (min != index)
    {
        swap(&node->array[min], &node->array[index]);
        minHeapify(node, min);
    }
}

void buildMinHeap(struct Heap *node)
{
    for (int i = node->heap_size - 1; i >= 0; i--)
    {
        minHeapify(node, i);
    }
}

void insert(struct Heap *node, int key, int arrNum)
{
    if (node->heap_size >= node->capacity)
        return;

    node->array[node->heap_size++].value = key;
    node->array[node->heap_size - 1].array_number = arrNum;
    buildMinHeap(node);
}

struct Array *extractMin(struct Heap *node)
{
    struct Array *temp = (struct Array *)malloc(sizeof(struct Array));
    int value = node->array[0].value, arrNum = node->array[0].array_number;
    temp->value = value, temp->array_number = arrNum;
    swap(&node->array[0], &node->array[--node->heap_size]);
    minHeapify(node, 0);
    return temp;
}

void swap(struct Array *a, struct Array *b)
{
    struct Array temp = *a;
    *a = *b;
    *b = temp;
}
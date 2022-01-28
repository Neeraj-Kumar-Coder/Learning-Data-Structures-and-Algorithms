#include <iostream>
#include <climits>

using namespace std;

class Heap
{
private:
    long long int max_size;
    long long int size;
    long long int *arr;

public:
    Heap(long long int maxSize)
    {
        max_size = maxSize;
        arr = new long long int[max_size];
        size = 0;
    }
    void max_heapify(long long int index)
    {
        long long int maximum = index;
        long long int left = 2 * index + 1;
        long long int right = 2 * index + 2;
        if (left < size && arr[left] > arr[maximum])
            maximum = left;
        if (right < size && arr[right] > arr[maximum])
            maximum = right;

        if (maximum != index)
        {
            swap(arr[index], arr[maximum]);
            max_heapify(maximum);
        }
    }
    void build_max_heap(void)
    {
        for (long long int i = (size - 1) / 2; i >= 0; i--)
        {
            max_heapify(i);
        }
    }
    void increase_value(long long int index, long long int newVal)
    {
        if (newVal < arr[index])
        {
            arr[index] = newVal;
            max_heapify(index);
        }
        else
        {
            long long int parent = (index - 1) / 2;
            arr[index] = newVal;
            while (parent > 0 && arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
                parent = (index - 1) / 2;
            }
            if (arr[parent] < arr[index])
                swap(arr[parent], arr[index]);
        }
    }
    void insert(long long int key)
    {
        arr[size] = LLONG_MIN;
        increase_value(size, key);
        size++;
    }
    void dequeue(void)
    {
        if (size)
        {
            swap(arr[0], arr[size - 1]);
            size--;
            max_heapify(0);
            return;
        }
        cout << "Heap is Empty!";
    }
    long long int getTopPriorityElement(void)
    {
        if (size)
        {
            return arr[0];
        }
        cout << "Heap is Empty!";
        return LLONG_MIN;
    }
};

int main(void)
{
    Heap h(100);
    h.insert(23);
    h.insert(62);
    h.insert(2);
    h.insert(82);
    h.insert(820);
    cout << h.getTopPriorityElement() << '\n';
    h.dequeue();
    cout << h.getTopPriorityElement() << '\n';
    h.dequeue();
    cout << h.getTopPriorityElement() << '\n';
    return 0;
}
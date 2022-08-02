#include <bits/stdc++.h>

using namespace std;

int nextGap(int number)
{
    if (number <= 1)
        return 0;
    return int(ceil(number / 2.0));
}

void merge(vector<int> &array, int low, int high)
{
    int gap = high - low + 1;
    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap))
    {
        for (int j = low; j + gap < high; j++)
        {
            if (array[j] > array[j + gap])
            {
                swap(array[j], array[j + gap]);
            }
        }
    }
}

void mergeSort(vector<int> &array, int low, int high)
{
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;
    mergeSort(array, low, mid);
    mergeSort(array, mid + 1, high);
    merge(array, low, high);
}

int main(void)
{
    vector<int> array;
    int element;
    cout << "Enter your array (when done, enter full stop): ";
    while (cin >> element)
    {
        array.push_back(element);
    }

    mergeSort(array, 0, array.size() - 1);
    cout << "Your sorted array is: ";
    for (auto &&element : array)
    {
        cout << element << ' ';
    }
    cout << '\n';
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int find_index(vector<int> &arr, int key)
{
    int low = 0, high = arr.size() - 1, mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        if (mid - 1 >= low && arr[mid - 1] == key)
            return mid - 1;
        if (mid + 1 <= high && arr[mid + 1] == key)
            return mid + 1;
        if (arr[mid] > key)
            high = mid - 2;
        else
            low = mid + 2;
    }
    return -1;
}

int main(void)
{
    int number_of_elements, key;
    cout << "Enter the number of elements: ";
    cin >> number_of_elements;
    vector<int> arr(number_of_elements);
    for (int i = 0; i < number_of_elements; i++)
        cin >> arr[i];
    cout << "Enter the key you want to search: ";
    cin >> key;
    return 0;
}
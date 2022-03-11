#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

bool binary_search(vector<int> &arr, int key)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return true;
        if (arr[low] < arr[mid])
        {
            if (key >= arr[low] && key < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (key > arr[mid] && key <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return false;
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
    cout << boolalpha << binary_search(arr, key) << '\n';
    return 0;
}
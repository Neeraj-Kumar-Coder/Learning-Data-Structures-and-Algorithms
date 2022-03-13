#include <iostream>
#include <vector>

using namespace std;

int find_first_occurence(vector<int> &arr, int key)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            if (mid - 1 >= low && arr[mid - 1] == key)
                high = mid - 1;
            else
                return mid;
        }
        else if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int find_last_occurence(vector<int> &arr, int key)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            if (mid + 1 <= high && arr[mid + 1] == key)
                low = mid + 1;
            else
                return mid;
        }
        else if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main(void)
{
    vector<int> arr = {2, 2, 2, 2};
    cout << find_first_occurence(arr, 2) << '\n';
    cout << find_last_occurence(arr, 2) << '\n';
    return 0;
}
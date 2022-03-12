#include <iostream>
#include <vector>

using namespace std;

int find_rotate_count(vector<int> &arr)
{
    int n = arr.size();
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] < arr[(mid + 1) % n] && arr[mid] < arr[(mid - 1 + n) % n])
            break;
        if (arr[mid] <= arr[high])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return mid;
}

int main(void)
{
    int length;
    cout << "Enter the length of the array and the array: ";
    cin >> length;
    vector<int> arr(length);
    for (int i = 0; i < length; i++)
        cin >> arr[i];

    cout << "Number of times the array is rotated is : " << find_rotate_count(arr) << '\n';
    return 0;
}
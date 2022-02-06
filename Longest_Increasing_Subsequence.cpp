#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <climits>

using namespace std;

int lis(vector<int> &arr)
{
    vector<int> list(arr.size() + 1, INT_MAX);
    vector<int>::iterator it;
    list[0] = INT_MIN;

    for (int i = 0; i < (int)arr.size(); i++)
    {
        it = upper_bound(list.begin(), list.end(), arr[i]);
        if (*(it - 1) < arr[i] && arr[i] < *it)
        {
            *it = arr[i];
        }
    }

    int length;
    for (length = list.size() - 1; length >= 0; length--)
    {
        if (list[length] != INT_MAX)
        {
            break;
        }
    }

    return length;
}

int main(void)
{
    vector<int> arr;
    int n, temp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }

    cout << "LIS: " << lis(arr) << '\n';
    return 0;
}
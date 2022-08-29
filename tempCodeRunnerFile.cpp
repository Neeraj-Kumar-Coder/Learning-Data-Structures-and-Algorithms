#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int pos = 0, neg = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] >= 0)
            pos++;
        else
            neg++;
    }

    sort(arr.begin(), arr.end());
    int minimum = INT_MAX;
    if (pos == neg)
    {
        int low = 0, high = n / 2;
        while (high < n)
        {
            minimum = min(minimum, arr[low++] * arr[high++]);
        }
    }
    else
    {
        minimum = arr[n / 2] * arr[n / 2 - 1];
    }
    cout << minimum << '\n';
    return 0;
}
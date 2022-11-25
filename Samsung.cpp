#include <bits/stdc++.h>

using namespace std;

int maxSum(int *arr, int length)
{
    vector<int> dp(length + 2);

    for (int i = length + 1; i >= 0; i--)
    {
        if (i >= length)
            dp[i] = 0;
        else
            dp[i] = max(arr[i] + dp[i + 2], dp[i + 1]);
    }
    return dp[0];
}

int *maximizingNumber(int *arr, int n, int *rep, int m)
{
    if (n == 0)
        return nullptr;
    if (m == 0)
        return arr;

    int ptr = m - 1;
    sort(rep, rep + m);

    for (int i = 0; ptr >= 0 && i < n; i++)
    {
        if (rep[ptr] > arr[i])
            arr[i] = rep[ptr--];
    }

    return arr;
}

int main(void)
{
    int arr[] = {1, 0, 2, 4, 5};
    int rep[] = {1, 9, 6};

    int *ans = maximizingNumber(arr, 5, rep, 3);
    for (int i = 0; i < 5; i++)
        cout << ans[i];
    return 0;
}
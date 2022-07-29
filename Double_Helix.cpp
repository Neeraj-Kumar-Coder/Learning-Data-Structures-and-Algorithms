#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dp;

int helper(vector<int> arr[2], vector<int> lookup[2], int i, int vecNum)
{
    if (i >= arr[vecNum].size())
        return 0;

    if (dp[i][vecNum] != -1)
        return dp[i][vecNum];

    if (lookup[vecNum][i] == -1)
        return dp[i][vecNum] = arr[vecNum][i] + helper(arr, lookup, i + 1, vecNum);

    int score_1 = arr[vecNum][i] + helper(arr, lookup, i + 1, vecNum);
    int score_2 = arr[vecNum][i] + helper(arr, lookup, lookup[vecNum][i] + 1, 1 - vecNum);
    return dp[i][vecNum] = max(score_1, score_2);
}

int main(void)
{
    while (true)
    {
        int n1, n2;
        cin >> n1;
        if (!n1)
            break;

        vector<int> arr1(n1);
        for (int i = 0; i < n1; i++)
            cin >> arr1[i];

        cin >> n2;
        vector<int> arr2(n2);
        for (int i = 0; i < n2; i++)
            cin >> arr2[i];
    }
    return 0;
}
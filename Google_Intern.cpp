#include <bits/stdc++.h>

using namespace std;

int helper(string &s, int m, int k, int index)
{
    if (index == s.length())
        return k == 0 ? 1 : 0;

    if (k < 0 || (s[index] - '0') & 1)
        return 0;

    int count = 0;
    for (int i = index + m - 1; i < s.length() - (k - 1) * m; i++)
    {
        if ((s[i] - '0') & 1)
        {
            count += helper(s, m, k - 1, i + 1);
        }
    }

    return count;
}

int helper(string &s, int m, int k)
{
    if (((s.front() - '0') & 1) || !((s.back() - '0') & 1) || (m * k > s.length()))
        return 0;

    const int mod = 1000000007;
    vector<vector<int>> dp(k + 1, vector<int>(s.length() + 1, 0));
    dp[0][s.length()] = 1;

    for (int i = 1; i <= k; i++)
    {
        for (int j = s.length() - 1; j >= 0; j--)
        {
            if ((s[j] - '0') & 1)
                dp[i][j] = 0;
            else
            {
                for (int k = j + m - 1; k < s.length() - (i - 1) * m; k++)
                {
                    if ((s[k] - '0') & 1)
                        dp[i][j] = (dp[i][j] % mod + dp[i - 1][k + 1] % mod) % mod;
                }
            }
        }
    }
    return dp[k][0] % mod;
}

int main(void)
{
    int n, m, k;
    string s;
    cin >> n >> m >> k;
    cin >> s;
    cout << helper(s, m, k) << '\n';
    cout << helper(s, m, k, 0) << '\n';
    return 0;
}
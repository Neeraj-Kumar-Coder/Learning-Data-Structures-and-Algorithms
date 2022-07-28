#include <bits/stdc++.h>

using namespace std;

long long int solution(string a, string b)
{
    int n1 = a.length(), n2 = b.length();
    vector<vector<int>> nr(n1, vector<int>(26, -1)), nl(n1, vector<int>(26, -1));

    for (int i = n1 - 2; i >= 0; i--)
    {
        nr[i] = nr[i + 1];
        nr[i][a[i + 1] - 'a'] = i + 1;
    }

    vector<int> dummy(26, -1);
    for (int i = 0; i < n1; i++)
    {
        if (dummy[a[i] - 'a'] == -1)
            dummy[a[i] - 'a'] = i;
        nl[i] = dummy;
    }

    vector<int> lookup = nr[0];
    lookup[a.front() - 'a'] = 0;
    long long int i = lookup[b.front() - 'a'], multiplier = 0, idx = 1;
    while (idx < n2)
    {
        if (nr[i][b[idx] - 'a'] != -1)
        {
            i = nr[i][b[idx] - 'a'];
        }
        else if (nl[i][b[idx] - 'a'] != -1)
        {
            multiplier++;
            i = nl[i][b[idx] - 'a'];
        }
        else
        {
            return -1;
        }
        idx++;
    }

    return multiplier * n1 + i + 1;
}

long long solutionBrute(string a, string b)
{
    vector<int> hash(26, 0);
    for (auto &&ch : a)
        hash[ch - 'a']++;

    for (auto &&ch : b)
        if (hash[ch - 'a'] == 0)
            return -1;

    long long int idx = 0, i = 0, n = a.length();
    while (true)
    {
        if (a[i % n] == b[idx])
            idx++;
        if (idx == int(b.length()))
            break;
        i++;
    }
    return i + 1;
}

int main(void)
{
    string a, b;
    cin >> a >> b;
    cout << solutionBrute(a, b) << '\n';
    cout << solution(a, b) << '\n';
    return 0;
}
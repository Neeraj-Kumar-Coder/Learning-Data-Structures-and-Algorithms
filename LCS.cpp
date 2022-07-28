#include <bits/stdc++.h>

using namespace std;

string result;

int lcs(string &a, string &b, int idx1, int idx2, string current)
{
    if (idx1 >= a.length() || idx2 >= b.length())
    {
        if (current.length() > result.length())
            result = current;
        return 0;
    }

    if (a[idx1] == b[idx2])
    {
        current.push_back(a[idx1]);
        return 1 + lcs(a, b, idx1 + 1, idx2 + 1, current);
    }

    return max(lcs(a, b, idx1, idx2 + 1, current), lcs(a, b, idx1 + 1, idx2, current));
}

int main(void)
{
    string a, b;
    cin >> a >> b;
    cout << "LENGTH: " << lcs(a, b, 0, 0, "") << '\n';
    cout << "STRING: " << result << '\n';
    return 0;
}
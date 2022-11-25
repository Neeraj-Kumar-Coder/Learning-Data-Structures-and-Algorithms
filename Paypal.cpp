#include <bits/stdc++.h>
#define ll long long int

using namespace std;

pair<ll, ll> helper(vector<ll> &arr, ll k)
{
    sort(arr.begin(), arr.end());
    vector<pair<ll, ll>> temp;
    temp.emplace_back(arr[0], 0);

    for (auto &&ele : arr)
    {
        if (ele == temp.back().first)
            temp.back().second++;
        else
            temp.emplace_back(ele, 1);
    }

    int idx1 = -1;
    for (int i = 0; i < temp.size(); i++)
    {
        if (k > temp[i].second * arr.size())
            k -= temp[i].second * arr.size();
        else
        {
            idx1 = i;
            break;
        }
    }

    int idx2 = -1;

    for (int i = 0; i < arr.size(); i++)
    {
        if (k > temp[idx1].second)
            k -= temp[idx1].second;
        else
        {
            idx2 = i;
            break;
        }
    }

    return {temp[idx1].first, arr[idx2]};
}

int main(void)
{
    vector<ll> arr = {4, 1};
    pair<ll, ll> answer = helper(arr, 3);
    cout << answer.first << ' ' << answer.second << '\n';
    return 0;
}
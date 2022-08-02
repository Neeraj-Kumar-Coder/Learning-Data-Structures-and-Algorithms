// Meet in the middle algorithm
#include <bits/stdc++.h>

#define int long long int

using namespace std;

void subSetSumFiller(vector<int> &arr, int low, int high, vector<int> &container)
{
    int limit = (1 << (high - low + 1));
    for (int i = 0; i < limit; i++)
    {
        int idx = low, sum = 0, temp = i;
        while (temp)
        {
            if (temp & 1)
                sum += arr[idx];
            idx++;
            temp >>= 1;
        }
        container.push_back(sum);
    }
}

signed main(void)
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> segment_1, segment_2;
    int mid = n / 2;
    subSetSumFiller(arr, 0, mid, segment_1);
    subSetSumFiller(arr, mid + 1, n - 1, segment_2);

    sort(segment_2.begin(), segment_2.end());
    int totalSubSets = 0;

    for (auto &&partialSum : segment_1)
    {
        int low = lower_bound(segment_2.begin(), segment_2.end(), a - partialSum) - segment_2.begin();
        int high = upper_bound(segment_2.begin(), segment_2.end(), b - partialSum) - segment_2.begin();
        totalSubSets += high - low;
    }
    cout << totalSubSets << '\n';
    return 0;
}
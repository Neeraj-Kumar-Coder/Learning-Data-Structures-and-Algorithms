#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;
    vector<int> height(n);
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }

    int low = 0, high = *max_element(height.begin(), height.end());
    long long int answer = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        long long int part = 0;
        for (int i = 0; i < n; i++)
        {
            part += max(0, height[i] - mid);
        }

        if (part >= m)
        {
            answer = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << answer;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        vector<int> position(n);
        for (int i = 0; i < n; i++)
        {
            cin >> position[i];
        }
        sort(position.begin(), position.end());
        int low = 0, high = position.back() - position.front(), answer = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int cows = 1, previous = position.front();
            for (int i = 1; i < n; i++)
            {
                if (position[i] - previous >= mid)
                {
                    if (++cows == c)
                        break;
                    previous = position[i];
                }
            }

            if (cows == c)
            {
                answer = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        cout << answer << '\n';
    }
    return 0;
}
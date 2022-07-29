#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int test_case;
    cin >> test_case;
    while (test_case--)
    {
        int number_of_prata;
        cin >> number_of_prata;
        int number_of_chefs;
        cin >> number_of_chefs;

        vector<int> rank(number_of_chefs);
        for (int i = 0; i < number_of_chefs; i++)
            cin >> rank[i];

        int low = 1, high = 5000000, answer = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int kitna_prata = 0;
            for (auto &&rnk : rank)
            {
                kitna_prata += (sqrt(1 + (8 * mid) / rnk) - 1) / 2;
            }

            if (kitna_prata >= number_of_prata)
            {
                answer = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        cout << answer << '\n';
    }
    return 0;
}
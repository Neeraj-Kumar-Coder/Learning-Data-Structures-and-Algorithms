#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxRow, maxColumn;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char ch;
    cin >> maxRow >> maxColumn;
    int limit = 2 * max(maxRow, maxColumn);
    vector<vector<int>> countOfOnes(limit, vector<int>(limit, 0));
    for (int i = 0; i < maxRow; i++)
    {
        for (int j = 0; j < maxColumn; j++)
        {
            cin >> ch;
            if (ch == '1')
                countOfOnes[i][j]++;
        }
    }

    for (int i = 0; i < limit; i++)
    {
        for (int j = 0; j < limit; j++)
        {
            if (i - 1 >= 0)
                countOfOnes[i][j] += countOfOnes[i - 1][j];
            if (j - 1 >= 0)
                countOfOnes[i][j] += countOfOnes[i][j - 1];
            if (i - 1 >= 0 && j - 1 >= 0)
                countOfOnes[i][j] -= countOfOnes[i - 1][j - 1];
        }
    }

    int temp, minimumToggles = INT_MAX, row, column, oneCount;
    for (int k = 2; k < limit / 2; k++)
    {
        temp = 0;
        for (int i = 0; i < maxRow; i += k)
        {
            for (int j = 0; j < maxColumn; j += k)
            {
                row = i + k - 1;
                column = j + k - 1;
                oneCount = countOfOnes[row][column];
                if (i)
                    oneCount -= countOfOnes[row - k][column];
                if (j)
                    oneCount -= countOfOnes[row][column - k];
                if (i && j)
                    oneCount += countOfOnes[i - 1][j - 1];
                temp += min(oneCount, k * k - oneCount);
            }
        }
        minimumToggles = min(minimumToggles, temp);
    }

    cout << minimumToggles << '\n';
    return 0;
}
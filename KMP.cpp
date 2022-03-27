#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief finds the lps array for a given pattern (KMP pattern matching pre-processing)
 * @param pattern pattern whose lps array is needed
 * @return returns the corresponding lps array
 **/
vector<int> LPS(string &pattern)
{
    vector<int> lps_array(pattern.size());
    lps_array[0] = 0;
    int i = 1, len = 0;
    while (i < pattern.size())
    {
        if (pattern[len] == pattern[i])
        {
            lps_array[i++] = ++len;
        }
        else
        {
            if (len == 0)
                lps_array[i++] = 0;
            else
                len = lps_array[len - 1];
        }
    }
    return lps_array;
}

int main(void)
{
    string pattern;
    cout << "Enter the pattern: ";
    cin >> pattern;
    vector<int> lps = LPS(pattern);

    for (auto &&i : pattern)
    {
        cout << i << ' ';
    }
    cout << '\n';
    for (auto &&i : lps)
    {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}
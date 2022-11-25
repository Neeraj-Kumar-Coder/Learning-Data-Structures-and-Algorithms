#include <bits/stdc++.h>
#define OFFSET 3

using namespace std;

unordered_map<char, unordered_set<char>> getFirst(vector<string> &productions)
{
    unordered_map<char, unordered_set<char>> first;
    int n = productions.size();
    for (int i = n - 1; i >= 0; i--)
    {
        int it = 0;
        char nonTerminal = productions[i][it];

        it += OFFSET;
        while (it < productions[i].length())
        {
            if (productions[i][it] >= 'A' && productions[i][it] <= 'Z')
            {
                bool eFound = false;

                if (first.find(productions[i][it]) == first.end())
                    continue;

                for (auto &value : first[productions[i][it]])
                {
                    if (value != 'e')
                        first[nonTerminal].insert(value);
                    else
                        eFound = true;
                }

                if (!eFound)
                {
                    while (it < productions[i].length() && productions[i][it] != '|')
                        ++it;
                    if (it != productions[i].length())
                        ++it;
                }
                else if (it + 1 == productions[i].length() || productions[i][it + 1] == '|')
                {
                    first[nonTerminal].insert('e');
                    it += 2;
                }
                else
                    ++it;
            }
            else
            {
                first[nonTerminal].insert(productions[i][it]);
                while (it < productions[i].length() && productions[i][it] != '|')
                    ++it;
                if (it != productions[i].length())
                    ++it;
            }
        }
    }
    return first;
}

unordered_map<char, unordered_set<char>> getFollow(vector<string> &productions, unordered_map<char, unordered_set<char>> &first)
{
    unordered_map<char, unordered_set<char>> follow;
    unordered_map<char, char> buffer;
    int n = productions.size();

    follow[productions[0][0]].insert('$');
    for (int i = 0; i < n; i++)
    {
        char nonTerminal = productions[i][0];
        for (int j = 0; j < n; j++)
        {
            int idx = 1;
            while (productions[j].find(nonTerminal, idx) != string::npos)
            {
                int it = productions[j].find(nonTerminal, idx);
                it++;
                idx = it;
                while (it < productions[j].length() && productions[j][it] != '|')
                {
                    char c = productions[j][it];
                    if (c >= 'A' && c <= 'Z')
                    {
                        follow[nonTerminal].insert(first[c].begin(), first[c].end());
                        if (follow[nonTerminal].find('e') == follow[nonTerminal].end())
                            break;
                        follow[nonTerminal].erase('e');
                        it++;
                    }
                    else
                    {
                        follow[nonTerminal].insert(c);
                        break;
                    }
                }
                if ((it == productions[j].length() || productions[j][it] == '|') && productions[j][0] != nonTerminal)
                {
                    buffer[nonTerminal] = productions[j][0];
                    follow[nonTerminal].insert(follow[productions[j][0]].begin(), follow[productions[j][0]].end());
                }
            }
        }
    }
    for (auto &p : buffer)
        follow[p.first].insert(follow[p.second].begin(), follow[p.second].end());
    return follow;
}

int main()
{
    int numberOfProductions;
    cout << "Enter the number of productions: ";
    cin >> numberOfProductions;

    cout << "Enter your productions: (in the form A->B)\n";
    vector<string> productions(numberOfProductions);
    for (int i = 0; i < numberOfProductions; i++)
        cin >> productions[i];

    auto first = getFirst(productions);
    cout << "\nFirst:\n";
    for (auto &nonT : first)
    {
        cout << nonT.first << ": {";
        auto it = nonT.second.begin();
        if (it != nonT.second.end())
        {
            cout << *it;
            it++;
        }
        while (it != nonT.second.end())
        {
            cout << ", " << *it;
            it++;
        }
        cout << "}\n";
    }

    cout << endl;
    cout << "Follow:\n";

    auto follow = getFollow(productions, first);
    for (auto &nonT : follow)
    {
        cout << nonT.first << ": {";
        auto it = nonT.second.begin();
        if (it != nonT.second.end())
        {
            cout << *it;
            it++;
        }
        while (it != nonT.second.end())
        {
            cout << ", " << *it;
            it++;
        }
        cout << "}\n";
    }
    return 0;
}
// 5
// E->TA
// A->+TA|e
// T->FC
// C->*FC|e
// F->(E)|i
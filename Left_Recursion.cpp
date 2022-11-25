#include <bits/stdc++.h>
#define OFFSET 3

using namespace std;

int main(void)
{
    int numberOfProductions;
    cout << "Enter the number of productions: ";
    cin >> numberOfProductions;

    vector<string> productions(numberOfProductions);
    for (int i = 0; i < numberOfProductions; i++)
    {
        cin >> productions[i];
    }

    char nonTerminal;
    string alpha, beta;
    for (int i = 0; i < numberOfProductions; i++)
    {
        cout << "Grammar: " << productions[i] << '\n';
        nonTerminal = productions[i][0];
        if (nonTerminal == productions[i][OFFSET])
        {
            cout << "Is left recursive!\n";
            int idx = 0;
            while (idx < productions[i].length() && productions[i][idx] != '|')
                idx++;

            if (idx == productions[i].length())
            {
                cout << "\nCannot be reduced!\n";
            }
            else
            {
                alpha = productions[i].substr(OFFSET + 1, idx - OFFSET - 1);
                beta = productions[i].substr(idx + 1);

                cout << nonTerminal << "->" << beta << nonTerminal << "'\n";
                cout << nonTerminal << "'->" << alpha << nonTerminal << "'"
                     << "| e\n";
            }
        }
        else
        {
            cout << "\nNot left recursive!\n";
        }
        cout << '\n';
    }

    return 0;
}
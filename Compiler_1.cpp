#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string n;
    cout << "Enter the digit: ";
    cin >> n;

    string mapping[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    for (auto &&ch : n)
    {
        assert(ch <= '0' && ch >= '9');
        cout << mapping[ch - '0'] << ' ';
    }

    return 0;
}
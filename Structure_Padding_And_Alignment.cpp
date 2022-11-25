#include <bits/stdc++.h>

using namespace std;

struct Name
{
    int value;
    double marks;
    int value2;
};

int main(void)
{
    cout << sizeof(int) << '\n';
    cout << sizeof(double) << '\n';
    cout << alignof(int) << '\n';
    cout << alignof(double) << '\n';

    cout << sizeof(Name) << '\n';
    cout << alignof(Name) << '\n';

    return 0;
}

// i i i i # # # # d d d  d  d  d  d  d  i  i  i  i  #  #  #  #
// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23
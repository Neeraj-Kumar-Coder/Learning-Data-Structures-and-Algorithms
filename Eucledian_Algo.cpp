#include <bits/stdc++.h>

using namespace std;

int eucledianAlgo(int a, int b)
{
    if (b == 0)
        return a;
    return eucledianAlgo(b, a % b);
}

tuple<int, int, int> extendedEucledianAlgo(int r1, int r2, int s1, int s2, int t1, int t2)
{
    if (r2 == 0)
        return make_tuple(r1, s1, t1);
    return extendedEucledianAlgo(r2, r1 % r2, s2, s1 - (r1 / r2) * s2, t2, t1 - (r1 / r2) * t2);
}

int main(void)
{
    int a, b;
    cout << "Enter the values of a, b: ";
    cin >> a >> b;
    assert(a > 0 && b > 0);
    cout << eucledianAlgo(a, b) << '\n';
    auto r2 = extendedEucledianAlgo(a, b, 1, 0, 0, 1);
    cout << get<0>(r2) << ' ' << get<1>(r2) << ' ' << get<2>(r2) << '\n';
    return 0;
}
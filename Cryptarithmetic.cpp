/**
 *      S    E    N    D
 * +    M    O    R    E
 * ----------------------
 * M    O    N    E    Y
 * ----------------------
 **/
#include <iostream>

using namespace std;

int main(void)
{
    for (int m = 0; m < 2; m++)
    {
        for (int o = 0; o < 10; o++)
        {
            if (o == m)
                continue;
            for (int n = 0; n < 10; n++)
            {
                if (n == o || n == m)
                    continue;
                for (int e = 0; e < 10; e++)
                {
                    if (e == n || e == o || e == m)
                        continue;
                    for (int y = 0; y < 10; y++)
                    {
                        if (y == e || y == n || y == o || y == m)
                            continue;
                        for (int s = 0; s < 10; s++)
                        {
                            if (s == y || s == e || s == n || s == o || s == m)
                                continue;
                            for (int r = 0; r < 10; r++)
                            {
                                if (r == s || r == y || r == e || r == n || r == o || r == m)
                                    continue;
                                for (int d = 0; d < 10; d++)
                                {
                                    if (d == r || d == s || d == y || d == e || d == n || d == o || d == m)
                                        continue;

                                    int num1 = s * 1000 + e * 100 + n * 10 + d;
                                    int num2 = m * 1000 + o * 100 + r * 10 + e;
                                    int sum = m * 10000 + o * 1000 + n * 100 + e * 10 + y;
                                    if (num1 + num2 == sum)
                                        cout << "Solution:" << '\n'
                                             << "M = " << m << '\n'
                                             << "O = " << o << '\n'
                                             << "N = " << n << '\n'
                                             << "E = " << e << '\n'
                                             << "Y = " << y << '\n'
                                             << "S = " << s << '\n'
                                             << "R = " << r << '\n'
                                             << "D = " << d << '\n';
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
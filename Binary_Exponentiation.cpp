#include <iostream>
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define MOD 1000000007

using namespace std;

long long int power(long long int, int);
long long int powerFast(long long int, int);

int main(void)
{
    cout << power(13, 10) << '\n';
    cout << powerFast(13, 10) << '\n';
    return 0;
}

long long int power(long long int base, int exponent)
{
    if (exponent == 0)
        return 1;
    if (exponent == 1)
        return base;

    long long int temp = power(base, exponent / 2);
    long long int result = temp * temp;
    if (exponent & 1)
        result = result * base;
    return result;
}

long long int powerFast(long long int base, int exponent)
{
    long long int result = 1;
    while (exponent)
    {
        if (exponent & 1)
            result = result * base;
        base = base * base;
        exponent = exponent >> 1;
    }
    return result;
}
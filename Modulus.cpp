#include <iostream>

using namespace std;

long long int fastPower(long long int base, long long int exponent, long long int mod)
{
    long long int answer = 1;
    while (exponent > 0)
    {
        if (exponent & 1)
            answer = (answer * base) % mod;
        base = (base * base) % mod;
        exponent >>= 1;
    }
    return answer;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int T, M, K;
    string N;
    cin >> T;
    while (T--)
    {
        cin >> M >> K;
        cin >> N;

        long long int *noDelete = new long long int[M];
        long long int *oneDelete = new long long int[M];
        long long int tenPow = 1;
        for (long long int i = M - 1; i >= 0; i--)
        {
            noDelete[i] = ((N[i] - '0') * tenPow) % K;
            tenPow = (tenPow * 10) % K;
        }
        for (long long int i = M - 2; i >= 0; i--)
        {
            noDelete[i] = (noDelete[i] + noDelete[i + 1]) % K;
        }

        for (long long int i = 0; i < M; i++)
        {
            oneDelete[i] = ((N[i] - '0') * fastPower(10, M - i - 2, K)) % K;
        }
        for (long long int i = 1; i < M; i++)
        {
            oneDelete[i] = (oneDelete[i] + oneDelete[i - 1]) % K;
        }

        long long int maxMod = noDelete[0], tempMod;
        for (long long int i = 0; i < M; i++)
        {
            tempMod = 0;
            if (i + 1 < M)
                tempMod = noDelete[i + 1];
            if (i - 1 >= 0)
                tempMod = (tempMod + oneDelete[i - 1]) % K;
            maxMod = max(tempMod, maxMod);
        }
        cout << maxMod << '\n';
    }
    return 0;
}
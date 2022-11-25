#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007

using namespace std;

vector<vector<ll>> multiply(vector<vector<ll>> &mat1, vector<vector<ll>> &mat2)
{
    vector<vector<ll>> result(2, vector<ll>(2));
    result[0][0] = ((mat1[0][0] * mat2[0][0]) % MOD + (mat1[0][1] * mat2[1][0]) % MOD) % MOD;
    result[0][1] = ((mat1[0][0] * mat2[0][1]) % MOD + (mat1[0][1] * mat2[1][1]) % MOD) % MOD;
    result[1][0] = ((mat1[1][0] * mat2[0][0]) % MOD + (mat1[1][1] * mat2[1][0]) % MOD) % MOD;
    result[1][1] = ((mat1[1][0] * mat2[0][1]) % MOD + (mat1[1][1] * mat2[1][1]) % MOD) % MOD;
    return result;
}

vector<vector<ll>> matrix_exponentiation(vector<vector<ll>> &mat, ll exp)
{
    vector<vector<ll>> result = {{1, 0}, {0, 1}};
    vector<vector<ll>> base = mat;
    while (exp)
    {
        if (exp & 1)
            result = multiply(result, base);
        base = multiply(base, base);
        exp >>= 1;
    }
    return result;
}

ll fib(ll n)
{
    if (n < 2)
        return n;
    vector<vector<ll>> base_matrix = {{1, 1}, {1, 0}};
    vector<vector<ll>> result = matrix_exponentiation(base_matrix, n - 1);
    return result[0][0];
}

int main(void)
{
    ll n;
    cin >> n;
    cout << fib(n) << '\n';
    return 0;
}
// Fibonacci (starting from 0th term): 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ...
#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

size_t NthFibonacci(size_t);
vector<vector<size_t>> multiply(vector<vector<size_t>> &, vector<vector<size_t>> &);
vector<vector<size_t>> matrix_exponentiation(vector<vector<size_t>> &, size_t);

int main(void)
{
    size_t term;
    cout << "Enter the term which you want to know in Fibonacci Series: ";
    cin >> term;
    cout << "O(n) Term number " << term << " is: " << NthFibonacci(term) << '\n';
    vector<vector<size_t>> mat = {{1, 1}, {1, 0}};
    cout << "O(log n) Term number " << term << " is: " << matrix_exponentiation(mat, term)[0][0] << '\n';
    return 0;
}

/**
 * @brief Time Complexity: O(n)
 * @param term The fibonacci term you want to find (starting from 0)
 * @return The required fibonacci number
 **/
size_t NthFibonacci(size_t term)
{
    size_t previous = 0, current = 1, tempCurrent;
    while (term--)
    {
        tempCurrent = current;
        current += previous;
        current %= MOD;
        previous = tempCurrent;
    }
    return current % MOD;
}

/**
 * @brief Time Complexity: O(1). It is contant time complexity because it works on matrix of size 3x3 only
 * @param mat1 The first matrix
 * @param mat2 The second matrix
 * @return The result after matrix multiplication
 **/
vector<vector<size_t>> multiply(vector<vector<size_t>> &mat1, vector<vector<size_t>> &mat2)
{
    size_t dimension = mat1.size();
    vector<vector<size_t>> result(dimension, vector<size_t>(dimension, 0));
    for (size_t i = 0; i < dimension; i++)
        for (size_t j = 0; j < dimension; j++)
            for (size_t k = 0; k < dimension; k++)
                result[i][j] += (mat1[i][k] % MOD * mat2[k][j] % MOD) % MOD, result[i][j] %= MOD;
    return result;
}

/**
 * @brief Time Complexity: O(log n)
 * @param mat The matrix to exponentiate
 * @param exp The exponent of the matrix
 * @return The result after exponentiating the given matrix
 **/
vector<vector<size_t>> matrix_exponentiation(vector<vector<size_t>> &mat, size_t exp)
{
    vector<vector<size_t>> result = {{1, 0}, {0, 1}};
    vector<vector<size_t>> temp = mat;

    while (exp)
    {
        if (exp & 1)
            result = multiply(result, temp);
        temp = multiply(temp, temp);
        exp >>= 1;
    }

    return result;
}
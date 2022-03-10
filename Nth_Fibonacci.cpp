// Fibonacci (starting from 0th term): 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ...
#include <iostream>
#include <vector>

using namespace std;

size_t NthFibonacci(unsigned int);
vector<vector<size_t>> multiply(vector<vector<size_t>> &, vector<vector<size_t>> &);
vector<vector<size_t>> matrix_exponentiation(vector<vector<size_t>> &, size_t);

int main(void)
{
    unsigned int term;
    cout << "Enter the term which you want to know in Fibonacci Series: ";
    cin >> term;
    cout << "O(n) Term number " << term << " is: " << NthFibonacci(term) << '\n';
    vector<vector<size_t>> mat = {{1, 1}, {1, 0}};
    cout << "O(log n) Term number " << term << " is: " << matrix_exponentiation(mat, term)[0][0] << '\n';
    return 0;
}

// Time Complexity: O(n)
size_t NthFibonacci(unsigned int term)
{
    size_t previous = 0, current = 1, tempCurrent;
    while (term--)
    {
        tempCurrent = current;
        current += previous;
        previous = tempCurrent;
    }
    return current;
}

// Time Complexity: O(log n)
vector<vector<size_t>> multiply(vector<vector<size_t>> &mat1, vector<vector<size_t>> &mat2)
{
    size_t dimension = mat1.size();
    vector<vector<size_t>> result(dimension, vector<size_t>(dimension, 0));
    for (size_t i = 0; i < dimension; i++)
        for (size_t j = 0; j < dimension; j++)
            for (size_t k = 0; k < dimension; k++)
                result[i][j] += mat1[i][k] * mat2[k][j];
    return result;
}

vector<vector<size_t>> matrix_exponentiation(vector<vector<size_t>> &mat, size_t exp)
{
    if (exp == 0)
        return {{1, 0}, {0, 1}};

    vector<vector<size_t>> temp = matrix_exponentiation(mat, exp / 2);
    vector<vector<size_t>> result = multiply(temp, temp);
    if (exp & 1)
        result = multiply(result, mat);

    return result;
}
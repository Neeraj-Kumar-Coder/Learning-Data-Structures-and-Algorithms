#include <iostream>
#include <vector>

using namespace std;

vector<vector<size_t>> multiply(vector<vector<size_t>> &, vector<vector<size_t>> &);
vector<vector<size_t>> matrix_exponentiation(vector<vector<size_t>> &, size_t);

int main(void)
{
    vector<vector<size_t>> mat = {{1, 1}, {1, 0}};

    vector<vector<size_t>> result = matrix_exponentiation(mat, 10);
    for (size_t i = 0; i < result.size(); i++)
    {
        for (size_t j = 0; j < result.size(); j++)
        {
            cout << result[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}

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
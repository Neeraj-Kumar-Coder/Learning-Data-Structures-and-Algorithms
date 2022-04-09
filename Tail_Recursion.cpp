#include <iostream>

using namespace std;

/**
 * @brief A Non Tail Recursive Function to find sum of first n natural numbers
 * @param n Nth natural number upto to find the sum
 * @return returns the sum of first n natural numbers
 **/
int findNthSum(int n)
{
    if (n <= 1)
        return n;
    return n + findNthSum(n - 1);
}

/**
 * @brief A Tail Recursive Function to find the sum of first n natural numbers
 * @param n Nth natural number upto to find the sum
 * @param current_sum the current sum of the series
 * @return returns the sum of first n natural numbers
 **/
int findNthSum(int n, int current_sum)
{
    if (n == 0)
        return current_sum;
    return findNthSum(n - 1, current_sum + n);
}

int main(void)
{
    cout << findNthSum(10) << '\n';
    cout << findNthSum(10, 0) << '\n';
    return 0;
}
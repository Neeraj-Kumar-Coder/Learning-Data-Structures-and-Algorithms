#include <iostream>
#include <vector>

using namespace std;

vector<bool> buildSeive(unsigned long long int);

int main(void)
{
    unsigned long long int number;
    cout << "Enter the number: ";
    cin >> number;
    cout << "All primes less than or equal to " << number << " is: ";

    vector<bool> isPrime = buildSeive(number);
    for (unsigned long long int prime = 0; prime < isPrime.size(); prime++)
    {
        if (isPrime[prime])
        {
            cout << prime << ' ';
        }
    }
    cout << '\n';
    return 0;
}

vector<bool> buildSeive(unsigned long long int number)
{
    unsigned long long int limit = number + 1;
    vector<bool> seive(limit, true);
    seive[0] = seive[1] = false;
    for (unsigned long long int i = 2; i * i < limit; i++)
    {
        if (seive[i])
        {
            for (unsigned long long int j = i * i; j < limit; j += i)
            {
                seive[j] = false;
            }
        }
    }
    return seive;
}
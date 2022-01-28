#include <iostream>
#include <algorithm>

using namespace std;

string toBinary(unsigned long long int);

int main(void)
{
    unsigned long long int number;
    cout << "Enter the number to convert to binary: ";
    cin >> number;
    cout << "The number in Binary is: " << toBinary(number) << '\n';
    return 0;
}

string toBinary(unsigned long long int number)
{
    if (!number)
        return "0";
    string result;
    while (number)
    {
        result.push_back(number % 2 + '0');
        number /= 2;
    }
    reverse(result.begin(), result.end());
    return result;
}
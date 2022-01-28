#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void)
{
    unsigned int numberOfRopes;
    cout << "Enter the number of ropes: ";
    cin >> numberOfRopes;
    priority_queue<unsigned long long int> lengths;
    unsigned long long int len;
    for (unsigned int i = 0; i < numberOfRopes; i++)
    {
        cout << "Enter the length of the rope: ";
        cin >> len;
        lengths.push(len);
    }
    unsigned long long int cost = 0;
    while (lengths.size() != 1)
    {
        len = 0;
        len += lengths.top();
        lengths.pop();
        len += lengths.top();
        lengths.pop();
        cost += len;
        lengths.push(len);
    }
    cout << "The minimum cost of connecting the ropes is: " << cost << '\n';
    return 0;
}
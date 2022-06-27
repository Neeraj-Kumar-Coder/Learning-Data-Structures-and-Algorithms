#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

int main(void)
{
    unordered_map<int, stack<int>> myStack;
    unordered_map<int, int> frequency;
    int queries, type, value, max_frequency = 1;

    cin >> queries;
    for (int current = 1; current <= queries; current++)
    {
        cin >> type >> value;
        switch (type)
        {
        case 1:
            frequency[value]++;
            max_frequency = max(max_frequency, frequency[value]);
            myStack[frequency[value]].push(value);
            break;
        case 2:
        {
            int element = myStack[max_frequency].top();
            myStack[max_frequency].pop();
            if (myStack[max_frequency].empty())
                max_frequency--;
            frequency[element]--;
            cout << element << ' ';
            break;
        }
        default:
            cout << "Enter a valid query type!\n";
            current--;
            break;
        }
    }
    return 0;
}
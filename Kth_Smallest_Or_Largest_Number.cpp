#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
    int n, k;
    cout << "Enter the number of elements: ";
    cin >> n;
    int key;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the number: ";
        cin >> key;
        arr.push_back(key);
    }
    cout << "Enter k: ";
    cin >> k;
    priority_queue<int> maxh;
    priority_queue<int, vector<int>, greater<int>> minh;
    for (auto val : arr)
    {
        maxh.push(val);
        if (maxh.size() > k)
            maxh.pop();
        minh.push(val);
        if (minh.size() > k)
            minh.pop();
    }
    cout << "The kth smallest number is: " << maxh.top() << '\n';
    cout << "The kth largest number is: " << minh.top() << '\n';
    return 0;
}
#include <iostream>
#include <queue>

#define pipii pair<int, pair<int, int>>

using namespace std;

class Compare
{
public:
    bool operator()(pipii &a, pipii &b)
    {
        if (a.first != b.first)
            return a.first < b.first;
        return a.second.first > b.second.first;
    }
};

int main(void)
{
    priority_queue<pipii, vector<pipii>, Compare> maxh;
    maxh.push({2, {3, 9}});
    maxh.push({2, {2, 9}});
    maxh.push({1, {4, 9}});
    maxh.push({2, {9, 9}});
    while (!maxh.empty())
    {
        cout << maxh.top().first << ", " << maxh.top().second.first << " " << maxh.top().second.second << '\n';
        maxh.pop();
    }
    return 0;
}
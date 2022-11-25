#include <bits/stdc++.h>

using namespace std;

const int fastio = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution
{
private:
    // It will return 0 if it is possible to divide the graph into some components with sum == target. Else it will return number other than zero
    int notPossibleToDivide(vector<vector<int>> &graph, vector<int> &nums, int target, int node, int parent)
    {
        int total = nums[node];
        for (auto &&ngbr : graph[node])
        {
            if (ngbr == parent)
                continue;

            total += notPossibleToDivide(graph, nums, target, ngbr, node);
        }

        return total == target ? 0 : total;
    }

public:
    int componentValue(vector<int> &nums, vector<vector<int>> &edges)
    {
        int numberOfVertices = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> graph(numberOfVertices);

        for (auto &&edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int edgesDeleted = 0;
        for (int parts = 1; parts <= numberOfVertices; parts++)
        {
            if (totalSum % parts)
                continue;

            if (notPossibleToDivide(graph, nums, totalSum / parts, 0, -1))
                continue;

            edgesDeleted = max(edgesDeleted, parts - 1);
        }

        return edgesDeleted;
    }
};

int main(void)
{
    vector<int> nums = {6, 2, 2, 2, 6};
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {1, 3}, {3, 4}};

    Solution obj;
    cout << obj.componentValue(nums, edges) << '\n';
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fillDistance(vector<vector<int>> &graph, vector<int> &distance, int node)
{
    if (graph[node].empty())
        return 0;

    int max_dis = 0;
    for (auto &&ngbr : graph[node])
    {
        max_dis = max(max_dis, fillDistance(graph, distance, ngbr));
    }
    return distance[node] = max_dis + 1;
}

vector<int> solve(int n, int q, vector<pair<int, int>> edges, vector<pair<int, int>> query)
{
    vector<vector<int>> graph(n);
    vector<int> parent(n);
    parent[0] = -1;
    for (auto &&p : edges)
    {
        if (p.first > p.second)
            swap(p.first, p.second);
        graph[p.first].push_back(p.second);
        parent[p.second] = p.first;
    }

    vector<int> distance(n);
    fillDistance(graph, distance, 0);

    vector<int> result;
    for (auto &&q : query)
    {
        if (q.first > q.second)
            swap(q.first, q.second);

        int ignore = q.second, current = q.second;
        while (parent[current] != q.first)
        {
            ignore = current;
            current = parent[current];
        }

        current = q.first;
        int dist = 0;
        while (current != -1)
        {
            for (auto &&ngbr : graph[current])
            {
                if (ngbr != ignore)
                    dist = max(dist, distance[ngbr] + 1);
            }
            current = parent[current];
        }

        result.push_back(dist);
    }
    return result;
}

int main(void)
{
    // vector<int> ans = solve(5, 2, {{0, 1}, {0, 2}, {1, 3}, {1, 4}}, {{0, 1}, {1, 4}});
    vector<int> ans = solve(3, 1, {{0, 1}, {0, 2}}, {{0, 1}});
    for (auto &&val : ans)
    {
        cout << val << ' ';
    }
    cout << '\n';
    return 0;
}
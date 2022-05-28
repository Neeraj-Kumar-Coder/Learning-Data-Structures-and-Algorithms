// https://leetcode.com/explore/learn/card/graph/618/disjoint-set/3840/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Union_Find
{
private:
    vector<int> parent;

public:
    Union_Find(int size) : parent(size)
    {
        for (int i = 0; i < size; i++)
        {
            parent[i] = i;
        }
    }

    int Find(int x)
    {
        while (parent[x] != x)
        {
            x = parent[x];
        }
        return x;
    }

    void Union(int x, int y)
    {
        int root_x = Find(x);
        int root_y = Find(y);

        if (root_x != root_y)
        {
            parent[root_y] = root_x;
        }
    }

    bool connected(int x, int y)
    {
        return Find(x) == Find(y);
    }
};

int main(void)
{
    Union_Find uf(7);
    while (true)
    {
        int choice;
        cout << "1. Union\n2. Find\n3. Connected\n4. Exit\n: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int x, y;
            cout << "Enter x and y for union: ";
            cin >> x >> y;
            uf.Union(x, y);
            break;
        }
        case 2:
        {
            int x;
            cout << "Enter x to find root: ";
            cin >> x;
            uf.Find(x);
            break;
        }
        case 3:
        {
            int x, y;
            cout << "Enter x and y to check for connectivity: ";
            cin >> x >> y;
            cout << boolalpha << "Connectivity status: " << uf.connected(x, y) << '\n';
            break;
        }
        case 4:
        default:
            goto end;
        };
    }
end:
    return 0;
}
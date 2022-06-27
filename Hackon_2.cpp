#include <bits/stdc++.h>

using namespace std;

vector<int> arr;
class Segment_Tree
{
private:
    vector<bitset<1001>> tree;

public:
    Segment_Tree(int size) : tree(vector<bitset<1001>>(size, bitset<1001>(0))) {}
    void build(int low, int high, int index)
    {
        if (low == high)
        {
            tree[index].set(arr[low]);
            return;
        }
        int mid = low + (high - low) / 2;
        build(low, mid, 2 * index);
        build(mid + 1, high, 2 * index + 1);
        tree[index] = tree[2 * index] ^ tree[2 * index + 1];
    }

    void update(int low, int high, int val, int i, int index)
    {
        if (high < i || i < low)
            return;
        if (low == high && low == i)
        {
            tree[index] = tree[index].flip(val).flip(arr[i]);
            arr[i] = val;
            return;
        }

        int mid = low + (high - low) / 2;
        update(low, mid, val, i, 2 * index);
        update(mid + 1, high, val, i, 2 * index + 1);
        tree[index] = tree[2 * index] ^ tree[2 * index + 1];
    }

    bitset<1001> query(int low, int high, int l, int r, int index)
    {
        if (l > high || r < low)
        {
            bitset<1001> res;
            return res;
        }
        if (low >= l && high <= r)
            return tree[index];

        int mid = low + (high - low) / 2;
        bitset<1001> f = query(low, mid, l, r, 2 * index);
        bitset<1001> s = query(mid + 1, high, l, r, 2 * index + 1);
        return f ^ s;
    }
};

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n;
        cin >> q;
        arr = vector<int>(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Segment_Tree st(4 * n + 1);
        st.build(0, n - 1, 1);
        while (q--)
        {
            int first, second, third;
            cin >> first >> second >> third;
            if (first == 1)
            {
                st.update(0, n - 1, third, second - 1, 1);
            }
            else
            {
                bitset<1001> temp = st.query(0, n - 1, second - 1, third - 1, 1);
                cout << temp.count() << '\n';
            }
        }
    }
    return 0;
}
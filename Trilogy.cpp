#include <bits/stdc++.h>

using namespace std;

class Segment_Tree
{
private:
    vector<int> seg_tree;
    vector<int> pending;
    int arr_size;

    void updateUtil(int seg_index, int low, int high, int arr_low, int arr_high)
    {
        if (pending[seg_index])
        {
            seg_tree[seg_index] = high - low + 1 - seg_tree[seg_index];
            if (low != high)
            {
                pending[2 * seg_index + 1] ^= 1;
                pending[2 * seg_index + 2] ^= 1;
            }
            pending[seg_index] = 0;
        }

        if (arr_low > high || arr_high < low)
            return;

        if (arr_low <= low && arr_high >= high)
        {
            seg_tree[seg_index] = high - low + 1 - seg_tree[seg_index];
            if (low != high)
            {
                pending[2 * seg_index + 1] ^= 1;
                pending[2 * seg_index + 2] ^= 1;
            }
            return;
        }

        int mid = low + (high - low) / 2;
        updateUtil(2 * seg_index + 1, low, mid, arr_low, arr_high);
        updateUtil(2 * seg_index + 2, mid + 1, high, arr_low, arr_high);
        seg_tree[seg_index] = seg_tree[2 * seg_index + 1] + seg_tree[2 * seg_index + 2];
    }

    int queryUtil(int seg_index, int low, int high, int key)
    {
        if (pending[seg_index])
        {
            seg_tree[seg_index] = high - low + 1 - seg_tree[seg_index];
            if (low != high)
            {
                pending[2 * seg_index + 1] ^= 1;
                pending[2 * seg_index + 2] ^= 1;
            }
            pending[seg_index] = 0;
        }

        if (low == high)
            return low;

        int mid = low + (high - low) / 2;
        if (pending[2 * seg_index + 1])
        {
            seg_tree[2 * seg_index + 1] = mid - low + 1 - seg_tree[2 * seg_index + 1];
            if (mid != low)
            {
                pending[2 * (2 * seg_index + 1) + 1] ^= 1;
                pending[2 * (2 * seg_index + 1) + 2] ^= 1;
            }
            pending[2 * seg_index + 1] = 0;
        }
        if (pending[2 * seg_index + 2])
        {
            seg_tree[2 * seg_index + 2] = high - mid - seg_tree[2 * seg_index + 2];
            if (mid + 1 != high)
            {
                pending[2 * (2 * seg_index + 2) + 1] ^= 1;
                pending[2 * (2 * seg_index + 2) + 2] ^= 1;
            }
            pending[2 * seg_index + 2] = 0;
        }

        if (seg_tree[2 * seg_index + 1] < key)
            return queryUtil(2 * seg_index + 2, mid + 1, high, key - seg_tree[2 * seg_index + 1]);
        return queryUtil(2 * seg_index + 1, low, mid, key);
    }

public:
    Segment_Tree(int size)
    {
        arr_size = size;
        seg_tree.resize(4 * arr_size + 1, 0);
        pending.resize(4 * arr_size + 1, 0);
    }

    void update(int arr_low, int arr_high)
    {
        updateUtil(0, 0, arr_size - 1, arr_low, arr_high);
    }

    int query(int key)
    {
        return queryUtil(0, 0, arr_size - 1, key);
    }
};

int main(void)
{
    Segment_Tree st(11);
    st.update(3, 6);
    cout << st.query(4) << '\n';
    st.update(4, 7);
    st.update(4, 7);
    cout << st.query(4) << '\n';
    return 0;
}
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Segment_Tree
{
private:
    vector<int> seg_tree;
    vector<int> pending;
    vector<int> arr_copy;
    int arr_size;

    void buildUtil(int seg_index, int low, int high)
    {
        if (low == high)
        {
            seg_tree[seg_index] = arr_copy[low];
            return;
        }

        int mid = low + (high - low) / 2;
        buildUtil(2 * seg_index + 1, low, mid);
        buildUtil(2 * seg_index + 2, mid + 1, high);
        seg_tree[seg_index] = min(seg_tree[2 * seg_index + 1], seg_tree[2 * seg_index + 2]);
    }

    void updateUtil(int seg_index, int low, int high, int arr_low, int arr_high, int increment_value)
    {
        if (pending[seg_index])
        {
            seg_tree[seg_index] += pending[seg_index];
            if (low != high)
            {
                pending[2 * seg_index + 1] += pending[seg_index];
                pending[2 * seg_index + 2] += pending[seg_index];
            }
            pending[seg_index] = 0;
        }

        if (arr_low > high || arr_high < low)
            return;

        if (arr_low <= low && arr_high >= high)
        {
            seg_tree[seg_index] += increment_value;
            if (low != high)
            {
                pending[2 * seg_index + 1] += increment_value;
                pending[2 * seg_index + 2] += increment_value;
            }
            return;
        }

        int mid = low + (high - low) / 2;
        updateUtil(2 * seg_index + 1, low, mid, arr_low, arr_high, increment_value);
        updateUtil(2 * seg_index + 2, mid + 1, high, arr_low, arr_high, increment_value);
        seg_tree[seg_index] = min(seg_tree[2 * seg_index + 1], seg_tree[2 * seg_index + 2]);
    }

    int queryUtil(int seg_index, int low, int high, int target_low, int target_high)
    {
        if (pending[seg_index])
        {
            seg_tree[seg_index] += pending[seg_index];
            if (low != high)
            {
                pending[2 * seg_index + 1] += pending[seg_index];
                pending[2 * seg_index + 2] += pending[seg_index];
            }
            pending[seg_index] = 0;
        }

        if (target_low <= low && target_high >= high)
        {
            return seg_tree[seg_index];
        }
        if (target_low > high || target_high < low)
        {
            return INT_MAX;
        }

        int mid = low + (high - low) / 2;
        int left = queryUtil(2 * seg_index + 1, low, mid, target_low, target_high);
        int right = queryUtil(2 * seg_index + 2, mid + 1, high, target_low, target_high);
        return min(left, right);
    }

public:
    Segment_Tree(void) : arr_size(0) {}
    void build(const vector<int> &arr)
    {
        arr_copy = vector<int>(arr);
        arr_size = arr_copy.size();
        seg_tree = vector<int>(4 * arr_size);
        pending = vector<int>(4 * arr_size, 0);
        buildUtil(0, 0, arr_size - 1);
    }

    void update(int arr_index, int increment_value)
    {
        updateUtil(0, 0, arr_size - 1, arr_index, arr_index, increment_value);
    }

    void update(int arr_low, int arr_high, int increment_value)
    {
        updateUtil(0, 0, arr_size - 1, arr_low, arr_high, increment_value);
    }

    int query(int low, int high)
    {
        return queryUtil(0, 0, arr_size - 1, low, high);
    }
};

int main(void)
{
    int number_of_elements;
    cout << "Enter the number of elements in the array: ";
    cin >> number_of_elements;
    vector<int> arr(number_of_elements);
    cout << "Enter the array: ";
    for (int i = 0; i < number_of_elements; i++)
    {
        cin >> arr[i];
    }

    Segment_Tree st;
    st.build(arr);
    char query_type;
    int low, high, increment_value, index;
    bool quit = false;
    while (true)
    {
        cout << "\nMinimum in range (q)\tPoint update (p)\tRange update (r)\tExit (e)\nInput: ";
        cin >> query_type;
        switch (query_type)
        {
        case 'q':
            cout << "Enter the range: ";
            cin >> low >> high;
            cout << "The minimum in the range is: " << st.query(low, high) << '\n';
            break;
        case 'p':
            cout << "Enter the index and increment factor: ";
            cin >> index >> increment_value;
            st.update(index, increment_value);
            break;
        case 'r':
            cout << "Enter the range and increment value: ";
            cin >> low >> high >> increment_value;
            st.update(low, high, increment_value);
            break;
        case 'e':
            quit = true;
            break;
        }
        if (quit)
            break;
    }

    return 0;
}
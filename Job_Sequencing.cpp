//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

// } Driver Code Ends
/*
struct Job
{
    int id;	 // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
*/

class Segment_Tree
{
private:
    vector<int> seg_tree;
    int arr_size;

    void buildUtil(int seg_index, int low, int high)
    {
        if (low == high)
        {
            seg_tree[seg_index] = low;
            return;
        }

        int mid = low + (high - low) / 2;
        buildUtil(2 * seg_index + 1, low, mid);
        buildUtil(2 * seg_index + 2, mid + 1, high);
        seg_tree[seg_index] = max(seg_tree[2 * seg_index + 1], seg_tree[2 * seg_index + 2]);
    }

    int queryUtil(int seg_index, int low, int high, int start, int end)
    {
        if (start <= low && end >= high)
            return seg_tree[seg_index];

        if (start > high || end < low)
            return -1;

        int mid = low + (high - low) / 2;
        int left = queryUtil(2 * seg_index + 1, low, mid, start, end);
        int right = queryUtil(2 * seg_index + 2, mid + 1, high, start, end);
        return max(left, right);
    }

    void updateUtil(int seg_index, int low, int high, int index)
    {
        if (low == high)
        {
            seg_tree[seg_index] = -1;
            return;
        }

        int mid = low + (high - low) / 2;
        if (index >= low && index <= mid)
            updateUtil(2 * seg_index + 1, low, mid, index);
        else
            updateUtil(2 * seg_index + 2, mid + 1, high, index);

        seg_tree[seg_index] = max(seg_tree[2 * seg_index + 1], seg_tree[2 * seg_index + 2]);
    }

public:
    Segment_Tree(void) : arr_size(0) {}
    void build(int size)
    {
        arr_size = size;
        seg_tree.resize(4 * arr_size + 1);
        buildUtil(0, 0, arr_size - 1);
    }
    int query(int start, int end)
    {
        return queryUtil(0, 0, arr_size - 1, start, end);
    }
    void update(int index)
    {
        updateUtil(0, 0, arr_size - 1, index);
    }
};

class Solution
{
public:
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        sort(arr, arr + n, [](const Job &a, const Job &b)
             { return a.profit > b.profit; });

        Segment_Tree st;
        st.build(100);
        int job_count = 0, total_profit = 0;
        for (int i = 0; i < n; i++)
        {
            int available = st.query(0, arr[i].dead - 1);
            if (available == -1)
                continue;
            total_profit += arr[i].profit;
            job_count++;
            st.update(available);
        }
        return {job_count, total_profit};
    }
};

//{ Driver Code Starts.
// Driver program to test methods
int main()
{
    int t;
    // testcases
    cin >> t;

    while (t--)
    {
        int n;

        // size of array
        cin >> n;
        Job arr[n];

        // adding id, deadline, profit
        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
        }
        Solution ob;
        // function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

// } Driver Code Ends
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = 0;
        for (int x : nums)
            sum += x;
        
        if (target > sum || target < -sum)
            return 0;
        vector<vector<int>> dp(nums.size(), vector<int>(2 * sum + 1, 0));
        dp[0][sum + nums[0]] += 1;
        dp[0][sum - nums[0]] += 1;

        int row = nums.size(), column = dp[0].size();

        for (int i = 0; i < row - 1; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (dp[i][j])
                {
                    dp[i + 1][j + nums[i + 1]] += dp[i][j];
                    dp[i + 1][j - nums[i + 1]] += dp[i][j];
                }
            }
        }
        return dp[nums.size() - 1][target + sum];
    }
};

int main(void)
{
    Solution obj;
    vector<int> arr = {0, 0, 0, 0, 0, 0, 0, 0, 1};
    int target = 1;
    cout << obj.findTargetSumWays(arr, target);
    return 0;
}
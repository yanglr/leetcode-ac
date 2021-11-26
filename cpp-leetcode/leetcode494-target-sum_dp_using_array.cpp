#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        nums.insert(nums.begin(), 0);
        const int N = nums.size();
        int sum = 0;
        for (int& x : nums) sum += x;
        if (target > sum || target < -sum) return 0;
        int dp[N][2*sum + 1];
        for (auto& row : dp)
            fill(row, row + 2*sum + 1, 0);
        dp[0][0 + sum] = 1; 
        for (int i = 1; i < N; i++)
        {
            for (int s = -sum; s <= sum; s++)
            {
                if (s + nums[i] + sum <= 2 * sum)
                    dp[i][s + nums[i] + sum] += dp[i - 1][s + sum];
                if (s - nums[i] + sum >= 0)
                    dp[i][s - nums[i] + sum] += dp[i - 1][s + sum];
            }
        }
        return dp[N - 1][target + sum];
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    auto res = sol.findTargetSumWays(nums, target);
    cout << res << endl;

    return 0;
}
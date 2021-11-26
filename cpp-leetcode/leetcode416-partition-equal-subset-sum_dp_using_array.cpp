#include<vector>
#include<algorithm>
#include<numeric>
#include<iostream>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum0 = accumulate(nums.begin(), nums.end(), 0);
        if (sum0 % 2 != 0) return false;
        int sum = sum0/2;
        bool dp[sum + 1]; // 原数组nums中的元素是否能凑出和为i, 如果能就将dp值更新为1。每来一个数nums[i], 都有选或不选两种状态
        fill(dp, dp + sum + 1, false);
        dp[0] = true;
        for (int& num : nums)
        {
            for (int j = sum; j >= 0; j--)
            {
                if (j >= num) /* 此处必须带上= */
                    dp[j] = dp[j] || dp[j - num];
            }            
        }
        return dp[sum];                
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {1, 5, 11, 5};
    auto res = sol.canPartition(nums);
    cout << (res ? "True" : "False") << endl;

    return 0;
}
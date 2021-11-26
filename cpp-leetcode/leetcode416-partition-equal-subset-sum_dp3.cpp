#include<vector>
#include<algorithm>
#include<numeric>
#include<iostream>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        vector<int> dp(sum + 1, 0); // dp[i]: 类似于0-1背包问题, 存0或1, 子序列的和能达到i就记作1, 否则记为0
        dp[0] = 1;
        for (const int& num : nums)
        {
            for (int i = sum; i >= 0; i--)
                if (dp[i] == 1) dp[i + num] = 1;
            if (dp[sum/2] == 1) return true;   // 如果其中一组的和为 sum/2, 那么就返回true
        }
        return false;
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
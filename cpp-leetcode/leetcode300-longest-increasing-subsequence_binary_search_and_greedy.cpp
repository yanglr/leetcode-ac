#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1); /* dp[i]: 以 nums[i] 结尾的LIS(最长上升子序列)的长度  */
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i]) /* 新来的数nums[j]是否能形成1个新的LIS, 使得nums[j]是新LIS中第2大的数且新LIS长度=LIS的长度+1? 如果能就更新之 */
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++)
            res = max(res, dp[i]); 
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7};
    auto res = sol.lengthOfLIS(nums);
    cout << res << endl;

    return 0;
}
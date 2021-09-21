#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int N = nums.size();
        // dp[i][0] -> LIS 的长度
        // dp[i][1] -> 同一长度的LIS 的个数
        vector<vector<int> > dp(N, vector<int>(2, 1));
        int maxLen = 1;
        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                if (nums[j] > nums[i])
                {                    
                    if (dp[i][0] + 1 > dp[j][0]) /* 新来的数nums[j]是否能使得LIS的长度+1? */
                    {
                        dp[j][0] = dp[i][0] + 1;
                        // 下面这行容易忘记(dp[j][1]的初始值是1, 需要先更新为当前LIS的个数)
                        dp[j][1] = dp[i][1];
                        maxLen = max(maxLen, dp[j][0]);                       
                    }
                    else if (dp[i][0] + 1 == dp[j][0])
                        dp[j][1] += dp[i][1];    
                }                                
            }
        }
        int count = 0;
        for (int i = 0; i < N; i++)
        {
            if (dp[i][0] == maxLen)
                count += dp[i][1];
        }
        return count;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 5, 4, 7};
    auto res = sol.findNumberOfLIS(nums);
    cout << res << endl;

    return 0;
}
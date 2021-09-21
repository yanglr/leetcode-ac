#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int N = nums.size();
        int res = 0;
        int maxLen = 0;
        vector<pair<int, int>> dp(N, {1, 1}); /* dp[i]: pair of {以nums[i]结尾的LIS的长度, 以nums[i]结尾的LIS 的数量} */
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    if (dp[i].first == dp[j].first + 1)
                        dp[i].second += dp[j].second;
                    if (dp[j].first + 1 > dp[i].first)
                        dp[i] = {dp[j].first + 1, dp[j].second};
                }
            }
            if (maxLen == dp[i].first) res += dp[i].second;
            if (maxLen < dp[i].first)
            {
                maxLen = dp[i].first;
                res = dp[i].second;
            }
        }
        return res;
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
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

// 前缀和 + 二分查找
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums){
        int len = nums.size();
        if (len == 0)
            return 0;
        int minLen = INT_MAX;
        // 构造前缀和
        vector<int> preSum(len + 1);
        preSum[0] = 0;
        for (int i = 0; i < len; i++)
            preSum[i + 1] = preSum[i] + nums[i];

       for (int i = 0; i < len; i++)
        {
            int toFind = target + preSum[i]; /* preSum_right - preSum_[i] = target */
            auto rIt = lower_bound(preSum.begin(), preSum.end(), toFind); /* 找的是第一个 ≥x 的 */
            if (rIt != preSum.end())
            {
                int curLen = rIt - (preSum.begin() + i);
                minLen = min(minLen, curLen);
            }
        }
        minLen = (minLen == INT_MAX) ? 0 : minLen;
        return minLen;
    }
};

// Test
int main()
{
    Solution sol;
    int target = 7;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    auto res = sol.minSubArrayLen(target, nums);
    cout << res << endl;

    return 0;
}
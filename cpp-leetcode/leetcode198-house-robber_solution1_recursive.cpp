#include<bits/stdc++.h>
using namespace std;

class Solution {
public:    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> opt(n+2, 0);
        
        return optSum(nums, 0, opt);
    }

    // 返回 dp[start..] 能抢到的最大值
    int optSum(vector<int> nums, int startIndex, vector<int>& opt)
    {
        if (startIndex > nums.size() - 1) /* 不可能发生的情况, 直接 return 0 */
            return 0;
        // 查表, 如果缓存中的值已不是初始值就return
        if (opt[startIndex] != 0)
            return opt[startIndex];
        int res = max(optSum(nums, startIndex + 1, opt), 
                      nums[startIndex] + optSum(nums, startIndex + 2, opt));
        opt[startIndex] = res;

        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {1,2,3,1};
    auto res = sol.rob(nums);
    cout << res << endl;

    nums = {2,7,9,3,1};
    res = sol.rob(nums);
    cout << res << endl;

    return 0;
}
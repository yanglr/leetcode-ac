#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int max1 = optSum(nums, 0, nums.size() - 2); // 情形2
        int max2 = optSum(nums, 1, nums.size() - 1); // 情形3
        return max(max1, max2);
    }
    // 情形1: 198.打家劫舍 的逻辑
    int optSum(vector<int>& nums, int start, int end) {
        if (end == start) return nums[start];
        vector<int> opt(nums.size());
        opt[start] = nums[start];
        opt[start + 1] = max(nums[start], nums[start + 1]);
        
        for (int i = start + 2; i <= end; i++) {
            opt[i] = max(opt[i - 2] + nums[i], opt[i - 1]);
        }
        return opt[end];
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {2,3,2};
    auto res = sol.rob(nums);
    cout << res << endl;

    nums = {1,2,3,1};
    res = sol.rob(nums);
    cout << res << endl;

    return 0;
}
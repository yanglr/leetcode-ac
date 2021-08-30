#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int totalCount = 0;
        int len = nums.size();
        vector<int> dp(len, 0); // dp[i]表示长度为i的等差子数组的个数
        for (int i = 2; i < len; i++)
        {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
                dp[i] = dp[i - 1] + 1; /* 这里的dp[i-1]表示在末尾直接插入1个满足等差性质的数(这样算的数量和前一项相等), 而1表示生成一个新的数组, 相当于前面生成的数组窗口整体后移1位 */
            totalCount += dp[i];
        }

        return totalCount;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = { 1, 1, 2, 3, 4, 5 };
    auto res = sol.numberOfArithmeticSlices(nums);
    cout << res << endl;
    
    return 0;
}
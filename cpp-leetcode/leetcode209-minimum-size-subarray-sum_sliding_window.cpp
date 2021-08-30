#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

// 滑动窗口(双指针)
// 用 2 个指针，一个指向数组开始的位置，一个指向数组最后的位置，
// 并维护区间内的和 sum 大于等于 s 同时数组长度最小。
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums){
        int len = nums.size();
        if (len == 0)
            return 0;
        
        int minLen = INT_MAX;
        int left = 0, sum = 0;
        for (int i = 0; i < len; ++i)  /* i: right指针 */
        { 
            sum += nums[i];
            while (sum >= target)
            {
                minLen = min(minLen, i - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return (minLen == INT_MAX) ? 0 : minLen;        
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